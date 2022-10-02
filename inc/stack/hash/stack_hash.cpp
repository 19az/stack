
#include "../../hash/gnu_hash.h"

#include "stack_hash.h"

#define HASH_ALG(...) gnu_hash(__VA_ARGS__)

#define GET_HASH_DATA_STACK(stk)                        \

HASH_TYPE_STACK GetHashStructStack_(const Stack* stk)
{
    return HASH_ALG( (const char*) &stk->data,
                    ((const char*) &stk->size) + sizeof(size_t));
}

HASH_TYPE_STACK GetHashDataStack_(const Stack* stk)
{
    return HASH_ALG( (const char*) stk->data,
                    ((const char*) stk->data) + stk->capacity);
}

#undef HASH_ALG

#undef GET_HASH_STRUCT_STACK
#undef GET_HASH_DATA_STACK

