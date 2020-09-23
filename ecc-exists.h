#pragma once
#include <stddef.h>
#include <stdbool.h>

void verbose_print(bool verbose, const char* format, ...);
double volume(size_t q, size_t e, size_t n);
size_t e(size_t d);
bool singleton_bound(size_t q, size_t n, size_t k, size_t d, bool verbose);
bool hamming_bound(size_t q, size_t n, size_t k, size_t d, bool verbose);
bool gilbert_bound(size_t q, size_t n, size_t k, size_t d, bool verbose);
