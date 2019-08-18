#ifndef OBJ_H
#define OBJ_H

#include "builtin.h"

enum obj_type {
	// objects read from source
	OBJ_WORD = 1,

	// objects parsed from words
	OBJ_BUILTIN,
	OBJ_INTEGER,

	// internal objects
	OBJ_JMP
};

struct obj {
	enum obj_type type;
	union {
		const char *word;
		enum builtin builtin;
		long integer;
		size_t addr;
	};
};

void obj_assert(struct obj);
void obj_dump(struct obj);

#endif
