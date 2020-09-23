#include <stddef.h>
#include <stdio.h>
#include "qc.h"

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
    printf("Going to analyze if following ECC exists: q=%zu n=%zu k=%zu d=%zu\n", q, n, k, d);
    printf("while %s verbose...\n", verbose ? "being" : "not being");
}
