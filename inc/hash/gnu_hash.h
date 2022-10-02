
#include <stdint.h>

/// @brief Hash function using gnu-hash algorithm
///
/// @param[in] start start of data to count hash
/// @param[in] finish finish of data to count hash
///
/// @return unsigned 32 bits value
uint32_t gnu_hash(const char *start, const char *finish);

