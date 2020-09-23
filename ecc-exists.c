#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <qc.h>
#include "ecc-exists.h"

bool ecc_exists(size_t q, size_t n, size_t k, size_t d, bool verbose) {
    if ( q < 2) {
        verbose_print(verbose, "Ill-formed code: q < 2 is not meaningful\n");
        return false;
    } else if (k >= n) {
        verbose_print(verbose, "Ill-formed code: no space to fit check bits\n");
        return false;
    } else if (d == 0) {
        verbose_print(verbose, "Ill-formed code: it does not fix or even detect any errors by design\n");
        return false;
    } else if (singleton_bound(q, n, k, d, verbose) &&
        hamming_bound(q, n, k, d, verbose) &&
        gilbert_bound(q, n, k, d, verbose)) {
        return true;
    } else {
        return false;
    }
}

int main(int argc, char* argv[]) {
	size_t q, n, k, d;
	bool verbose = false;
	qc_args* args = qc_args_new();
	qc_args_unsigned(args, "q", &q, "Code bitness");
    qc_args_unsigned(args, "n", &n, "Code block length");
    qc_args_unsigned(args, "k", &k, "Information bits");
    qc_args_unsigned(args, "d", &d, "Hamming distance");
    qc_args_flag(args, 'v', "verbose", &verbose, "Spam terminal with thoughts");
    char* err;
    if (qc_args_parse(args, argc, argv, &err) == -1) {
        fprintf(stderr, "Failed to parse command line arguments: %s\n", err);
        free(err);
        exit(EXIT_FAILURE);
    }
    bool exists = ecc_exists(q, n, k, d, verbose);
    printf("Code with provided parameters %s!\n", exists ? "exists" : "does not exist");
    exit(exists ? EXIT_SUCCESS : EXIT_FAILURE);
}
