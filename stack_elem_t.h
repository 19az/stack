
// This file consist of
// constants which describe type of stack element
// and functions which needed to work with it

#include <stdio.h>

const char* logfilename = "logfile.txt";

typedef uint32_t Elem_t;

const Elem_t  POISON_ELEM_T_STACK = 0xDEADF00D;

Elem_t* const POISON_ELEM_T_PTR_STACK = (Elem_t*) 0xDEADE1E17719DEAD;

void fprintf_elem_t_stack(FILE* stream, const Elem_t* elem);

void fprintf_elem_t_stack(FILE* stream, const Elem_t* elem)
{
    fprintf(stream, "%x\n", *elem);
}

#define CANARY_PROTECT
#define POISON_ELEM_T_PROTECT
#define HASH_PROTECT

