#include <assert.h>

#include "builtin.h"

static const struct builtin_meta BUILTIN_META_TABLE[] = {
	[BUILTIN_READ]	= { .name = "READ"	},
	[BUILTIN_EVAL]	= { .name = "EVAL"	},
	[BUILTIN_DOT]	= { .name = "."		}
};

const struct builtin_meta *
get_builtin_meta(enum builtin builtin)
{
	assert(BUILTIN_READ <= builtin);
	assert(builtin <= BUILTIN_DOT);

	return &BUILTIN_META_TABLE[builtin];
}
