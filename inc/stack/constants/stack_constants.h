
/// @file stack_constants.h
///
/// @brief Stack constants

#ifndef STACK_CONSTANTS_H
#define STACK_CONSTANTS_H

// POISON values

const size_t POISON_SIZE_T_STACK = 0xDEAD512E;

#ifdef CANARY_PROTECT
    typedef uint64_t CANARY_STACK;
    
    const CANARY_STACK POISON_CANARY_STACK = 0xDEADCA17A129DEAD;

    void fprintf_canary_stack(FILE* stream, const CANARY_STACK* canary);

    void fprintf_canary_stack(FILE* stream, const CANARY_STACK* canary)
    {
        fprintf(stream, "%lx\n", *canary);
    }
#endif

// Hash

typedef uint32_t HASH_TYPE_STACK;

void fprintf_hash_stack(FILE* stream, const HASH_TYPE_STACK hash);

void fprintf_hash_stack(FILE* stream, const HASH_TYPE_STACK hash)
{
    fprintf(stream, "%u\n", hash);
}

// Errors

#define ERR_TYPE_STACK uint32_t

/// Errors that might occur in Stack
enum errors_stack : ERR_TYPE_STACK
{
        ERR_BAD_STACK_PTR_STACK     = 1,       ///< Bad pointer to stack
#define ERR_BAD_STACK_PTR_STACK_MSSG               "Bad pointer to stack"

        ERR_REALLOC_STACK           = 1 << 1,  ///< Error during realloc
#define ERR_REALLOC_STACK_MSSG                     "Error during realloc"

        ERR_CANARY_STRUCT_STACK     = 1 << 2,  ///< Damaged struct canary
#define ERR_CANARY_STRUCT_STACK_MSSG               "Damaged struct canary"

        ERR_CANARY_DATA_STACK       = 1 << 3,  ///< Damaged data canary
#define ERR_CANARY_DATA_STACK_MSSG                 "Damaged data canary"

        ERR_BAD_DATA_PTR_STACK      = 1 << 4,  ///< Bad data pointer value
#define ERR_BAD_DATA_PTR_STACK_MSSG                "Bad data pointer value"

        ERR_SIZE_GR_CAP_STACK       = 1 << 5,  ///< Size greater then capacity
#define ERR_SIZE_GR_CAP_STACK_MSSG                 "Size greater then capacity"

        ERR_SIZE_POIS_STACK         = 1 << 6,  ///< Bad size value
#define ERR_SIZE_POIS_STACK_MSSG                   "Bad size value"

        ERR_CAP_POIS_STACK          = 1 << 7,  ///< Bad capacity value
#define ERR_CAP_POIS_STACK_MSSG                    "Bad capacity value"
  
        ERR_ELEM_GR_SIZE_USED_STACK = 1 << 8,  ///< Element greater than size was used
#define ERR_ELEM_GR_SIZE_USED_STACK_MSSG           "Element greater than size was used"
        
        ERR_HASH_STRUCT_STACK       = 1 << 9,  ///< Bad struct hash
#define ERR_HASH_STRUCT_STACK_MSSG                 "Bad struct hash"

        ERR_HASH_DATA_STACK         = 1 << 10, ///< Bad data hash
#define ERR_HASH_DATA_STACK_MSSG                   "Bad data hash"

        ERR_VERIFICATOR_STACK       = 1 << 11, ///< Verificator finded error
#define ERR_VERIFICATOR_STACK_MSSG                 "Verificator finded error"
};

#endif /* STACK_CONSTANTS_H */
