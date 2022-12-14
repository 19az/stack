
#include <stdio.h>

#include "inc/stack/stack.h"

int main() {

    Stack stk{};

    StackCtor(&stk, 1);

    const size_t n_elems = 19;

    for (size_t index = 0; index < n_elems; index++)
    {
        StackPush(&stk, (uint32_t) index);
    }

    for (size_t index = 0; index < n_elems; index++)
    {
        StackPop(&stk);
    }

    StackDtor(&stk);

    fclose(LOGFILE);

    return 0;
}
