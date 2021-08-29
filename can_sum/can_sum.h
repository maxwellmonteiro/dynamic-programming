#include <stdbool.h>
#include <inttypes.h>
#include <vector.h>

bool can_sum(int64_t target_sum, uint64_t* list, uint32_t size);
vector_type(bool) create_memo(uint32_t size);
bool can_sum_memoized(int64_t target_sum, uint64_t* list, uint32_t size, bool* memo);
bool can_sum_memoized_findable(int64_t target_sum, uint64_t* list, uint32_t size, vector_type(uint64_t)* memo);