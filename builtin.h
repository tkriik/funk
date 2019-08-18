#ifndef BUILTIN_H
#define BUILTIN_H

enum builtin {
	BUILTIN_READ = 1,
	BUILTIN_EVAL,
	BUILTIN_DOT
};

struct builtin_meta {
	const char *name;
};

const struct builtin_meta *get_builtin_meta(enum builtin);

#endif
