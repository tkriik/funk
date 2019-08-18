#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "vm.h"

#define FUNK_VSN_MAJOR 0
#define FUNK_VSN_MINOR 1
#define FUNK_VSN_PATCH 0

struct vm VM;

static void
usage(void)
{
	extern char *__progname;
	fprintf(stderr, "usage: %s [-hV] [file]\n", __progname);
	exit(1);
}

int
main(int argc, char *argv[])
{
	FILE *in = NULL;

	int opt;
	while ((opt = getopt(argc, argv, "hV")) != -1) {
		switch (opt) {
		case 'V':
			fprintf(stderr, "funk %d.%d.%d\n", FUNK_VSN_MAJOR, FUNK_VSN_MINOR, FUNK_VSN_PATCH);
			return 0;
		case 'h':
		default:
			usage();
		}
	}

	argc -= optind;
	argv += optind;

	if (argc == 0)
		in = stdin;
	else if (argc == 1) {
		const char *filename = argv[0];
		in = fopen(filename, "r");
		if (in == NULL)
			err(1, "can't open file '%s'", filename);
	} else
		usage();

	vm_init(&VM, in);
	vm_dump(&VM);

	return 0;
}
