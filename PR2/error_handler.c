#include <stdio.h>
#include <stdlib.h>

static FILE *error_file = NULL;

void set_error_path(const char *path) {
    if (error_file) {
        fclose(error_file);
    }
    error_file = fopen(path, "w");
    if (!error_file) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }
}

void log_error(const char *message) {
    if (error_file) {
        fprintf(error_file, "ERROR: %s\n", message);
    } else {
        fprintf(stderr, "ERROR: %s\n", message);
    }
}

