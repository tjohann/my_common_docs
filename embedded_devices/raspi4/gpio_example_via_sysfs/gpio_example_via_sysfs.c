/*
  Simple application to handle gpio via sysfs

  Note: the control via sysfs is deprecated, but i use it because i need no
        other libs than libc (works with musl libc)

  Build it native on the decice:
  gcc -Wall -Wextra -o gpio_example_via_sysfs gpio_example_via_sysfs.c

  Build it via buildroot cross compiler (for example):
  ~/builds/buildroot_raspi4/output/host/bin/aarch64-linux-gcc  -Wall -Wextra -o gpio_example_via_sysfs gpio_example_via_sysfs.c

  Usage: ./gpio_example_via_sysfs 10 (as root)
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

#define ON  1
#define OFF 0

#define IN  0
#define OUT 1

#define LOW  0
#define HIGH 1

#define POUT 23 /* PIN 16 */
#define PIN  24 /* PIN 18 */

#define DEFAULT_COUNT 60
#define MAX_LEN 3


int
gpio_pin_state(int pin, unsigned char state)
{
	char str[MAX_LEN];
	int fd;

open_it:
	if (state == ON)
		fd = open("/sys/class/gpio/export", O_WRONLY);
	else
		fd = open("/sys/class/gpio/unexport", O_WRONLY);
	if (fd == -1) {
		if (errno == EINTR)
			goto open_it;
		goto error;
	}

	int n = snprintf(str, MAX_LEN, "%d", pin);
	if (n < 0)
		goto error;

	int err = write(fd, str, n);
	if (err == -1)
		goto error;

	close(fd);
	return 0;
error:
	fprintf(stderr, "ERROR: could not active PIN -> %d\n", pin);
	return -1;
}


static int
GPIODirection(int pin, int dir)
{
	static const char s_directions_str[]  = "in\0out";

#define DIRECTION_MAX 35
	char path[DIRECTION_MAX];
	int fd;

	snprintf(path, DIRECTION_MAX, "/sys/class/gpio/gpio%d/direction", pin);
	fd = open(path, O_WRONLY);
	if (-1 == fd) {
		fprintf(stderr, "Failed to open gpio direction for writing!\n");
		return(-1);
	}

	if (-1 == write(fd, &s_directions_str[IN == dir ? 0 : 3], IN == dir ? 2 : 3)) {
		fprintf(stderr, "Failed to set direction!\n");
		return(-1);
	}

	close(fd);
	return(0);
}

static int
GPIORead(int pin)
{
#define VALUE_MAX 30
	char path[VALUE_MAX];
	char value_str[3];
	int fd;

	snprintf(path, VALUE_MAX, "/sys/class/gpio/gpio%d/value", pin);
	fd = open(path, O_RDONLY);
	if (-1 == fd) {
		fprintf(stderr, "Failed to open gpio value for reading!\n");
		return(-1);
	}

	if (-1 == read(fd, value_str, 3)) {
		fprintf(stderr, "Failed to read value!\n");
		return(-1);
	}

	close(fd);

	return(atoi(value_str));
}

static int
GPIOWrite(int pin, int value)
{
	static const char s_values_str[] = "01";

	char path[VALUE_MAX];
	int fd;

	snprintf(path, VALUE_MAX, "/sys/class/gpio/gpio%d/value", pin);
	fd = open(path, O_WRONLY);
	if (-1 == fd) {
		fprintf(stderr, "Failed to open gpio value for writing!\n");
		return(-1);
	}

	if (1 != write(fd, &s_values_str[LOW == value ? 0 : 1], 1)) {
		fprintf(stderr, "Failed to write value!\n");
		return(-1);
	}

	close(fd);
	return(0);
}

int
main(int argc, char *argv[])
{
	int repeat = 10;

	/* normal workflow:
	   output@LED
	   echo "23" > /sys/class/gpio/export

	   input@key
	   echo "24" > /sys/class/gpio/export


	*/
	if (gpio_pin_state(POUT, ON) == -1 || gpio_pin_state(PIN, ON) == -1)
		return EXIT_FAILURE;

	/*
	 * Set GPIO directions
	 */
	if (-1 == GPIODirection(POUT, OUT) || -1 == GPIODirection(PIN, IN))
		return(2);

	do {
		/*
		 * Write GPIO value
		 */
		if (-1 == GPIOWrite(POUT, repeat % 2))
			return(3);

		/*
		 * Read GPIO value
		 */
		printf("I'm reading %d in GPIO %d\n", GPIORead(PIN), PIN);

		usleep(500 * 1000);
	}
	while (repeat--);


	/* ignore error -> kernel will cleanup anyway */
	(void) gpio_pin_state(POUT, OFF);
	(void) gpio_pin_state(PIN, OFF);

	return EXIT_SUCCESS;
}
