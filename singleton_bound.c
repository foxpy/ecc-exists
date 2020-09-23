#include <stddef.h>
#include <stdbool.h>
#include "ecc-exists.h"

bool singleton_bound(size_t q, size_t n, size_t k, size_t d, bool verbose) {
    verbose_print(verbose, "Testing code with Singleton bound...\n");
    if (q != 2) {
        verbose_print(verbose, "Singleton bound does not apply to codes with q != 2\n");
        return true;
    } else {
        if (d <= (n - k + 1)) {
            verbose_print(verbose, "Code exists by Singleton bound\n");
            return true;
        } else {
            verbose_print(verbose, "Code does not exist by Singleton bound\n");
            return false;
        }
    }
}
