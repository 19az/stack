
/// @file stack_hash.h
///
/// @brief Hash protect in Stack

#ifndef STACK_HASH_H
#define STACK_HASH_H

/// @brief Get struct Stack hash
///
/// @param[in] stk pointer to the Stack to get hash
HASH_TYPE_STACK GetHashStructStack_(const Stack* stk);

/// @brief Get data Stack hash
///
/// @param[in] stk pointer to the Stack to get hash
HASH_TYPE_STACK GetHashDataStack_(const Stack* stk);

#endif /* STACK_HASH_H */

