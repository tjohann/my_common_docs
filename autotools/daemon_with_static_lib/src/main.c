/*
  GPL
  (c) 2016, thorsten.johannvorderbrueggen@t-online.de

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

 */

#include "libservice.h"

static char *program_name;
static int running_mode = RUN_AS_APPLICATION;

static sigset_t mask;

static void
__attribute__((noreturn)) usage(int status)
{
	putchar('\n');
	baa_info_msg(_("Usage: %s [options]                             "),
		     program_name);
	baa_info_msg(_("Options:                                        "));
	baa_info_msg(_("        -h   show help                          "));
	baa_info_msg(_("        -a   run as application in foreground   "));
	baa_info_msg(_("        -s   run as service/daemon in background"));
	putchar('\n');

	exit(status);
}

static void
cleanup(void)
{
	baa_info_msg(_("Finalize cleanup -> cheers %s\n"), getenv("USER"));
}

static void *
sig_handler(void *args)
{
	(void) args;

	int sig = EINVAL;
	int err = -1;
	for (;;) {
		err = sigwait(&mask, &sig);
		if (err != 0)
			baa_error_exit(_("sigwait() != 0 in %s"), __FUNCTION__);
#ifdef __DEBUG__
		baa_info_msg(_("Catched signal \"%s\" (%d)"),
			     strsignal(sig), sig);
#endif
		switch(sig) {
		case SIGTERM:
			baa_info_msg(_("Goodbye crude world "));
			exit(EXIT_SUCCESS);
			break;
		case SIGHUP:
			baa_info_msg(_("Signal \"%s\" (%d) -> what should i do?"),
				     strsignal(sig), sig);
			break;
		default:
			baa_error_msg(_("Unhandled signal \"%s\" (%d)"),
				      strsignal(sig), sig);
		}
	}

	return NULL;
}

int
main(int argc, char *argv[])
{
	pthread_t tid_sig_handler;

	setlocale(LC_ALL, "");
	bindtextdomain(PACKAGE, LOCALEDIR);
	textdomain(PACKAGE);

	baa_set_program_name(&program_name, argv[0]);

	int c;
	while ((c = getopt(argc, argv, "hasf:d:")) != -1) {
		switch (c) {
		case 'a':
			running_mode = RUN_AS_APPLICATION;
			break;
		case 's':
                        running_mode = RUN_AS_DAEMON;
			break;
		case 'h':
			usage(EXIT_SUCCESS);
			break;
		default:
			baa_error_msg(_("ERROR: no valid argument\n"));
			usage(EXIT_FAILURE);
		}
	}

	if (atexit(cleanup) != 0)
		exit(EXIT_FAILURE);

	if (running_mode == RUN_AS_DAEMON) {
		if (baa_become_daemon() != 0) {
			baa_error_exit(_("become_daemon() != 0"));
		} else {
			baa_info_msg(_("now i'm a daemon"));
		}
	} else {
		baa_info_msg(_("run in foreground as application"));
	}

	sigfillset(&mask);
	int err = pthread_sigmask(SIG_BLOCK, &mask, NULL);
	if (err != 0)
		baa_th_error_exit(err, _("Could not set sigmask in %s"),
				  __FUNCTION__);

	err = pthread_create(&tid_sig_handler, NULL, sig_handler, 0);
	if (err != 0)
		baa_th_error_exit(err, _("Could not create pthread in %s"),
				  __FUNCTION__);



	// only for testing
	sleep(20);

	return EXIT_SUCCESS;
}
