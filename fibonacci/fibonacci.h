#include <inttypes.h>

uint64_t fibonacci(long n);

uint64_t* create_memo(long n);
void destroy_memo(uint64_t* memo);
uint64_t fibonacci_memoized(long n, uint64_t* memo);