#include <stdbool.h>
#include <inttypes.h>

bool can_sum(int64_t target_sum, uint64_t* list, uint32_t size);
bool can_sum_memoized(int64_t target_sum, uint64_t* list, uint32_t size, bool* memo);