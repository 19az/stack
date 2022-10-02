
#ifdef HASH_PROTECT
    #define UPDATE_HASH_STACK(stk)                         \
        stk->hash_struct_value = GetHashStructStack_(stk); \
        stk->hash_data_value   = GetHashDataStack_  (stk); 
#else
    #define UPDATE_HASH_STACK(stk) ((void) 0)
#endif

void StackCtor_(Stack* stk, size_t new_size ERR_SUPPORT_DEFN)
{
    if (stk == NULL
        ERR_HANDLED_MSSG(LOGFILE, ERR_BAD_STACK_PTR_STACK))
        return;

    if ( 
#ifdef CANARY_PROTECT
         (stk->l_canary != POISON_CANARY_STACK)     ||
         (stk->r_canary != POISON_CANARY_STACK)     ||
#endif
         (stk->data     != POISON_ELEM_T_PTR_STACK) ||

         (stk->size     != POISON_SIZE_T_STACK)     ||
         (stk->capacity != POISON_SIZE_T_STACK) 
       ) 
    {
        ERR_REPORT_MSSG(LOGFILE,
            "Attempt constructing used and not destructed stack");

        return;
    }

    stk->data = NULL;

    stk->size     = 0;
    stk->capacity = 0;

    ERR_TYPE_STACK err_resize = 0;
    StackResize_(stk, new_size, &err_resize);

    if (ERR_CHECK_MSSG(LOGFILE, err_resize, ERR_REALLOC_STACK))
        return;

    UPDATE_HASH_STACK(stk);

    if (StackError(stk)) {
        StackDump (stk);
        return;
    }
}

void StackDtor(Stack* stk ERR_SUPPORT_DEFN)
{
    if (StackError(stk)) {
        StackDump (stk);
        return;
    }

    ASSERT(stk->data != NULL &&
           stk->data != POISON_ELEM_T_PTR_STACK);

#ifdef CANARY_PROTECT
    ASSERT(L_CANARY_PTR_DATA != NULL);
    
    free(L_CANARY_PTR_DATA);
#else
    free(stk->data);
#endif

    stk->data     = POISON_ELEM_T_PTR_STACK;
    stk->capacity = POISON_SIZE_T_STACK;
    stk->size     = POISON_SIZE_T_STACK;
}

void StackPush(Stack *stk, Elem_t elem ERR_SUPPORT_DEFN)
{
    if (StackError(stk)) {
        StackDump (stk);
        return;
    }

    ERR_TYPE_STACK err_resize = 0;
    StackResize_(stk, stk->size + 1, &err_resize);

    if (ERR_CHECK_MSSG(LOGFILE, err_resize, ERR_REALLOC_STACK))
        return;

    ASSERT(stk->data != NULL &&
           stk->data != POISON_ELEM_T_PTR_STACK);

    ASSERT(stk->capacity >= stk->size);

    stk->data[stk->size++] = elem;

    UPDATE_HASH_STACK(stk);

    if (StackError(stk)) {
        StackDump (stk);
        return;
    }
}

Elem_t StackPop(Stack *stk ERR_SUPPORT_DEFN)
{
#ifdef POISON_ELEM_T_PROTECT
    Elem_t ret_value = POISON_ELEM_T_STACK;
#else
    Elem_t ret_value = Elem_t{};
#endif
    
    if (StackError(stk)) {
        StackDump (stk);

        return ret_value;
    }

    if (stk->size == 0) return ret_value;

    ASSERT(stk->data != NULL &&
           stk->data != POISON_ELEM_T_PTR_STACK);

    ASSERT(stk->capacity >= stk->size);

    ret_value = stk->data[stk->size - 1];

#ifdef POISON_ELEM_T_PROTECT
    stk->data[stk->size - 1] = POISON_ELEM_T_STACK;
#endif

    ERR_TYPE_STACK err_resize = 0;
    StackResize_(stk, stk->size - 1, &err_resize);

    if (ERR_CHECK_MSSG(LOGFILE, err_resize, ERR_REALLOC_STACK))
    {
        return ret_value;
    }
    
    stk->size--;

    UPDATE_HASH_STACK(stk);

    if (StackError(stk)) {
        StackDump (stk);

        return ret_value;
    }

    return ret_value;
}

#undef UPDATE_HASH_STACK
    
