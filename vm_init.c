#include <assert.h>
#include <err.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "util.h"
#include "vm.h"

#define VM_INIT_SRC_CAP		8
#define VM_INIT_PROG_CAP	8

static const struct obj VM_INIT_CODE[] = {
	{ .type = OBJ_BUILTIN,	.builtin	= BUILTIN_READ		},
	{ .type = OBJ_BUILTIN,	.builtin	= BUILTIN_EVAL		},
	{ .type = OBJ_JMP,	.addr		= 0x0			}
};

#define VM_INIT_CODE_LEN ARRAY_LEN(VM_INIT_CODE)

void
vm_init(struct vm *vm, FILE *in)
{
	assert(vm != NULL);
	assert(in != NULL);

	vm->in = in;

	vm->src = calloc(VM_INIT_SRC_CAP, 1);
	if (vm->src == NULL)
		err(1, "calloc");
	vm->src_len = 0;
	vm->src_cap = VM_INIT_SRC_CAP;

	vm->pc = 0;
	vm->prog = calloc(sizeof(*vm->prog), VM_INIT_PROG_CAP);
	if (vm->prog == NULL)
		err(1, "calloc");
	assert(VM_INIT_CODE_LEN < VM_INIT_PROG_CAP);
	memcpy(vm->prog, VM_INIT_CODE, sizeof(VM_INIT_CODE));
	vm->prog_len = VM_INIT_CODE_LEN;
	vm->prog_cap = VM_INIT_PROG_CAP;
}
