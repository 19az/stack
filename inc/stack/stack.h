
#ifndef STACK_H
#define STACK_H

#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "constants/stack_constants.h"
#define ERR_TYPE ERR_TYPE_STACK
#include "../error_handling/error_handling.h"

struct Stack
{
#ifdef HASH_PROTECT
    HASH_TYPE_STACK hash_struct_value   = 0;
    HASH_TYPE_STACK hash_data_value     = 0;
#endif

#ifdef CANARY_PROTECT
    CANARY_STACK l_canary = POISON_CANARY_STACK;
#endif

    Elem_t*      data     = POISON_ELEM_T_PTR_STACK;

    size_t       size     = POISON_SIZE_T_STACK;
    size_t       capacity = POISON_SIZE_T_STACK;
    
#ifndef NDEBUG
    VAR_DATA var_data = {};
#endif

#ifdef CANARY_PROTECT
    CANARY_STACK r_canary = POISON_CANARY_STACK;
#endif
};

#include "dump/stack_dump.h"
#include "error/stack_error.h"
#include "resize/stack_resize.h"

#ifdef HASH_PROTECT
#include "hash/stack_hash.h"
#endif

/// @brief Constructs object of Stack with given size
///
/// @param stk pointer to the object to construct
/// @param[in] size size of constructing stack
void StackCtor_(Stack* stk, size_t size ERR_SUPPORT_DECL);

#ifdef NDEBUG
    #define StackCtor(stk, size) StackCtor_(stk, size)
#else
    #define StackCtor(stk, size)           \
        (stk)->var_data = VAR_INFO(stk);   \
                                           \
        setvbuf(LOGFILE, NULL, _IONBF, 0); \
                                           \
        StackCtor_(stk, size);

#endif

/// @brief Destructs object of Stack
void StackDtor(Stack* stk ERR_SUPPORT_DECL);

/// @brief Adds new element to the stack
///
/// @param stk pointer to the stack
/// @param[in] elem element to add
void StackPush(Stack* stk, Elem_t elem ERR_SUPPORT_DECL);

/// @brief Removes the last element from the stack and returns it
///
/// @param stk pointer to the stack
///
/// @return removed element
Elem_t StackPop(Stack* stk ERR_SUPPORT_DECL);

#define L_CANARY_PTR_DATA (((CANARY_STACK*) stk->data) - 1)
#define R_CANARY_PTR_DATA ((CANARY_STACK*) (stk->data + stk->capacity))

#ifdef NDEBUG
    #define StackDump(stk) ((void) 0)
#else
    #define StackDump(stk)        \
        DUMP(LOGFILE);            \
                                  \
        StackDump_(LOGFILE, stk);

#endif /* ifndef NDEBUG: StackDump() */

#define StackError(stk)                                   \
    (StackError_(stk, (err) ? err : NULL)                 \
        ERR_HANDLED_MSSG(LOGFILE, ERR_VERIFICATOR_STACK))

#include "stack.cpp"
#include "dump/stack_dump.cpp"
#include "error/stack_error.cpp"
#include "resize/stack_resize.cpp"

#ifdef HASH_PROTECT
#include "hash/stack_hash.cpp"
#endif

#undef StackDump
#undef StackError

#undef LOGFILE

#undef L_CANARY_DATA
#undef R_CANARY_DATA

#undef ERR_TYPE

#endif /* STACK_H */
