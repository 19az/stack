
/// @file stack_resize.h
///
/// @brief Resize function for Stack

#ifndef STACK_RESIZE_H
#define STACK_RESIZE_H

/// @brief Changes capacity of given stack
///
/// @param stk pointer to Stack to change capacity
/// @param[in] new_size capacity which should fit in
/// stack after resize
///
/// @note provides ERR_SUPPORT mode
///
/// @see ERR_SUPPORT_DEFN
void StackResize_(Stack* stk, size_t new_size ERR_SUPPORT_DECL);

/// @brief Makes dump of stack and StackResize() arguments into logfile
///
/// @param[in] logfile file where write dumps to
/// @param[in] stk stack to dump
/// @param[in] new_size new_size arg of StackResize_() function
void StackResizeDump_(FILE* logfile, const Stack* stk, size_t new_size);

#endif /* STACK_RESIZE_H */

