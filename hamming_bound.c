#include <stddef.h>
#include <stdbool.h>
#include <math.h>
#include "ecc-exists.h"

bool hamming_bound(size_t q, size_t n, size_t k, size_t d, bool verbose) {
    verbose_print(verbose, "Testing code with Hamming bound...\n");

    if (((double) k / n + log(volume(q, e(d), n)) / log(q) / n) <= 1) {
        verbose_print(verbose, "Code exists by Hamming bound\n");
        return true;
    } else {
        verbose_print(verbose, "Code does not exist by Hamming bound\n");
        return false;
    }
}
