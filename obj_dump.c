#include <stdio.h>

#include "builtin.h"
#include "obj.h"
#include "vm.h"

void
obj_dump(struct obj obj)
{
	const struct builtin_meta *builtin_meta;

	switch (obj.type) {
	case OBJ_WORD:
		fprintf(stderr, "%s", obj.word);
		break;
	case OBJ_BUILTIN:
		builtin_meta = get_builtin_meta(obj.builtin);
		fprintf(stderr, "#builtin<%s>", builtin_meta->name);
		break;
	case OBJ_INTEGER:
		fprintf(stderr, "%ld", obj.integer);
		break;
	case OBJ_JMP:
		fprintf(stderr, "#jmp<" VM_ADDR_FMT ">", obj.addr);
		break;
	default:
		fprintf(stderr, "<INVALID>");
		break;
	}
}
