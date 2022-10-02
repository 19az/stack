
#include "stack_dump.h"

void StackDump_(FILE* logfile, const Stack* stk)
{
    ASSERT(logfile != NULL);

    if (stk == NULL)
    {
        fprintf(logfile, "given NULL ptr in stk\n");
        
        return;
    }

    fprintf(logfile,
            "Stack [%p] \"%s\" at %s at %s(%lu):\n",
            stk,
            stk->var_data.var_name,
            stk->var_data.func_name,
            stk->var_data.file,
            stk->var_data.line);

    fprintf(logfile, "{\n");

    fprintf(logfile,
            "data [%p]\n"
            "size     = %lx\n"
            "capacity = %lx\n",
            stk->data,
            stk->size,
            stk->capacity);

#ifdef CANARY_PROTECT
    fprintf(logfile, "left struct canary:  ");
    fprintf_canary_stack(logfile, &(stk->l_canary));

    fprintf(logfile, "right struct canary: ");
    fprintf_canary_stack(logfile, &(stk->r_canary));
#endif

#ifdef HASH_PROTECT
    fprintf(logfile, "struct hash value: ");
    fprintf_hash_stack(logfile, stk->hash_struct_value);

    fprintf(logfile, "real struct hash:  ");
    fprintf_hash_stack(logfile, GetHashStructStack_(stk));

    fprintf(logfile, "\n");

    fprintf(logfile, "data hash value: ");
    fprintf_hash_stack(logfile, stk->hash_data_value);

    fprintf(logfile, "real data hash:  ");
    fprintf_hash_stack(logfile, GetHashDataStack_(stk));
#endif

    StackDumpElems_(logfile, stk);

    fprintf(logfile, "}\n\n");

    fflush(logfile);
}

void StackDumpElems_(FILE* logfile, const Stack* stk)
{    
    ASSERT(logfile != NULL);
    ASSERT(stk     != NULL);

    fprintf(logfile, "\t{\n");

    if (stk->data == NULL ||
        stk->data == POISON_ELEM_T_PTR_STACK)
    {
        fprintf(logfile, "\tBad data ptr\n\t}\n");

        return;
    }


#ifdef CANARY_PROTECT
    fprintf(logfile, "\tleft  data canary: ");
    fprintf_canary_stack(logfile, L_CANARY_PTR_DATA);
#endif

    for (size_t index = 0; index < stk->capacity; index++)
    {
        fprintf(logfile,
                "\t%c [%2lu] = ",
                (index < stk->size) ? '*' : ' ',
                index + 1);

        fprintf_elem_t_stack(logfile, stk->data + index);
    }

#ifdef CANARY_PROTECT
    fprintf(logfile, "\tright data canary: ");
    fprintf_canary_stack(logfile, R_CANARY_PTR_DATA);
#endif

    fprintf(logfile, "\t}\n");
}
