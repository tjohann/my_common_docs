/*
 * a simple libconfig example for my_clock project
 */

#include <stdio.h>
#include <stdlib.h>
#include <libconfig.h>

int main(void)
{
	config_t cfg;
	config_setting_t *settings, *root;
	const char *str;

	config_init(&cfg);

	if(config_read_file(&cfg, "tempd.conf") != CONFIG_TRUE )
	{
		fprintf(stderr, "%s:%d - %s\n",
			config_error_file(&cfg),
			config_error_line(&cfg),
			config_error_text(&cfg));

		config_destroy(&cfg);
		exit(EXIT_FAILURE);
	}

	if(config_lookup_string(&cfg, "name", &str))
		fprintf(stdout, "config-file for %s\n", str);
	else
		fprintf(stderr, "No 'name' setting in config file!\n");

	putchar('\n');

	if(config_lookup_string(&cfg, "common.message_file", &str))
		fprintf(stdout, "common.message_file for %s\n", str);
	else
		fprintf(stderr, "No 'common.message_file' setting in config file!\n");

	if(config_lookup_string(&cfg, "tempd.i2c_adapter", &str))
		fprintf(stdout, "tempd.i2c_adapter for %s\n", str);
	else
		fprintf(stderr, "No 'tempd.i2c_adapter' setting in config file!\n");


	config_destroy(&cfg);

	exit(EXIT_SUCCESS);
}
