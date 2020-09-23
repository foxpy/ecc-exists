#include <stddef.h>
#include <stdbool.h>
#include <math.h>
#include "ecc-exists.h"

bool gilbert_bound(size_t q, size_t n, size_t k, size_t d, bool verbose) {
    verbose_print(verbose, "Testing code with Gilbert bound...\n");

    // I am doubt this one works as intended, it feels too restrictive
    // I have checked calculations twice, everything is alright
    // Maybe I do not understand the Gilbert bound properly? Maybe.
    if (((double) k / n + log(volume(q, 2*e(d), n)) / log(q) / n) <= 1) {
        verbose_print(verbose, "Code exists by Gilbert bound\n");
        return true;
    } else {
        verbose_print(verbose, "Code does not exist by Gilbert bound\n");
        return false;
    }
}
