
/// @file stack_error.h
///
/// @brief Handling errors in stack

#ifndef STACK_ERROR_H
#define STACK_ERROR_H

/// @brief Checks if stack info is valid
///
/// @param[in] stk pointer to stack to check
///
/// @return 0 if stack is OK, error code otherwise
///
/// @note Provides ERR_SUPPORT mode
///
/// @see ERR_SUPPORT_DECL
ERR_TYPE_STACK StackError_(const Stack* stk ERR_SUPPORT_DECL);

/// @brief Check if stack elements are valid
///
/// @param[in] stk pointer to the stack to check
///
/// @return 0 if stack elements are OK, error code otherwise
ERR_TYPE_STACK StackErrorElems_(const Stack* stk ERR_SUPPORT_DECL);

#endif /* STACK_ERROR_H */

