/* SPDX-License-Identifier: GPL-2.0 */
#ifndef _ASM_PARISC_JUMP_LABEL_H
#define _ASM_PARISC_JUMP_LABEL_H

#ifndef __ASSEMBLER__

#include <linux/types.h>
#include <linux/stringify.h>
#include <asm/assembly.h>

#define JUMP_LABEL_NOP_SIZE 4

static __always_inline bool arch_static_branch(struct static_key *key, bool branch)
{
	asm goto("1:\n\t"
		 "nop\n\t"
		 ".pushsection __jump_table,  \"aw\"\n\t"
		 ".align %1\n\t"
		 ".word 1b - ., %l[l_yes] - .\n\t"
		 __stringify(ASM_ULONG_INSN) " %c0 - .\n\t"
		 ".popsection\n\t"
		 : : "i" (&((char *)key)[branch]), "i" (sizeof(long))
		 : : l_yes);

	return false;
l_yes:
	return true;
}

static __always_inline bool arch_static_branch_jump(struct static_key *key, bool branch)
{
	asm goto("1:\n\t"
		 "b,n %l[l_yes]\n\t"
		 ".pushsection __jump_table,  \"aw\"\n\t"
		 ".align %1\n\t"
		 ".word 1b - ., %l[l_yes] - .\n\t"
		 __stringify(ASM_ULONG_INSN) " %c0 - .\n\t"
		 ".popsection\n\t"
		 : : "i" (&((char *)key)[branch]), "i" (sizeof(long))
		 : : l_yes);

	return false;
l_yes:
	return true;
}

#endif  /* __ASSEMBLER__ */
#endif
