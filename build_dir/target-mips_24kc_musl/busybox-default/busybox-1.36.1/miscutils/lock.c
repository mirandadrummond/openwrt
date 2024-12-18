/*
 * Copyright (C) 2006 Felix Fietkau <nbd@nbd.name>
 *
 * This is free software, licensed under the GNU General Public License v2.
 */

//config:config LOCK
//config:	bool "lock"
//config:	default n
//config:	help
//config:	  Small utility for using locks in scripts

//applet:IF_LOCK(APPLET(lock, BB_DIR_BIN, BB_SUID_DROP))

//kbuild:lib-$(CONFIG_LOCK) += lock.o

//usage:#define lock_trivial_usage NOUSAGE_STR
//usage:#define lock_full_usage ""

#include <sys/types.h>
#include <sys/file.h>
#include <sys/stat.h>
#include <signal.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "busybox.h"

static int unlock = 0;
static int shared = 0;
static int waitonly = 0;
static int try_lock = 0;
static int fd;
static char *file;

static void usage(char *name)
{
	fprintf(stderr, "Usage: %s [-suw] <filename>\n"
	                "	-s	Use shared locking\n"
	                "	-u	Unlock\n"
	                "	-w	Wait for the lock to become free, don't acquire lock\n"
			"	-n	Don't wait for the lock to become free. Fail with exit code\n"
					"\n", name);
	exit(1);
}

static void exit_unlock(int sig)
{
	flock(fd, LOCK_UN);
	exit(0);
}

static int do_unlock(void)
{
	FILE *f;
	int i;

	if ((f = fopen(file, "r")) == NULL)
		return 0;

	fscanf(f, "%d", &i);
	if (i > 0)
		kill(i, SIGTERM);

	fclose(f);

	return 0;
}

static int do_lock(void)
{
	pid_t pid;
	int flags;
	char pidstr[12];

	if ((fd = open(file, O_RDWR | O_CREAT | O_EXCL, 0700)) < 0) {
		if ((fd = open(file, O_RDWR)) < 0) {
			fprintf(stderr, "Can't open %s\n", file);
			return 1;
		}
	}

	flags = shared ? LOCK_SH : LOCK_EX;
	flags |= try_lock ? LOCK_NB : 0;

	if (flock(fd, flags) < 0) {
		fprintf(stderr, "Can't lock %s\n", file);
		return 1;
	}

	pid = fork();

	if (pid < 0)
		return -1;

	if (pid == 0) {
		signal(SIGKILL, exit_unlock);
		signal(SIGTERM, exit_unlock);
		signal(SIGINT, exit_unlock);
		if (waitonly)
			exit_unlock(0);
		else
			while (1)
				sleep(1);
	} else {
		if (!waitonly) {
			lseek(fd, 0, SEEK_SET);
			ftruncate(fd, 0);
			snprintf(pidstr, sizeof(pidstr), "%d\n", pid);
			write(fd, pidstr, strlen(pidstr));
			close(fd);
		}

		return 0;
	}
	return 0;
}

int lock_main(int argc, char **argv) MAIN_EXTERNALLY_VISIBLE;
int lock_main(int argc, char **argv)
{
	char **args = &argv[1];
	int c = argc - 1;

	while ((*args != NULL) && (*args)[0] == '-') {
		char *ch = *args;
		while (*(++ch) > 0) {
			switch(*ch) {
				case 'w':
					waitonly = 1;
					break;
				case 's':
					shared = 1;
					break;
				case 'u':
					unlock = 1;
					break;
				case 'n':
					try_lock = 1;
					break;
			}
		}
		c--;
		args++;
	}

	if (c != 1)
		usage(argv[0]);

	file = *args;
	if (unlock)
		return do_unlock();
	else
		return do_lock();
}
