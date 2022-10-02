
/// @file stack_dump.h
///
/// @brief Dumping stack into logfile

#ifndef STACK_DUMP_H
#define STACK_DUMP_H

/// @brief Dumping stack info into logfile
///
/// @param[in] logfile file where to write logs
/// @param[in] stk stack to be dumped
void StackDump_(FILE* logfile, const Stack* stk);

/// @brief Dumping stack elements into log file
///
/// @param[in] logfile file where to write logs
/// @param[in] stk stack to be dumped
void StackDumpElems_(FILE* logfile, const Stack* stk);

#endif /* STACK_DUMP_H */

