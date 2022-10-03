
#include <stdint.h>

#include "stack_elem_t.h"
FILE* const LOGFILE = fopen(logfilename, "w");

#include "inc/stack/stack.h"

int main() {

    Stack stk1{};

    StackCtor(&stk1, 0);

    const size_t n_elems = 654;

    for (size_t index = 0; index < n_elems; index++)
    {
        StackPush(&stk1, (uint32_t) index);
    }

    for (size_t index = 0; index < n_elems; index++)
    {
        StackPop(&stk1);
    }

    StackDtor(&stk1);

    fclose(LOGFILE);

    return 0;
}
