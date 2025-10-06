#include <stddef.h> // For NULL
// TODO: Include any necessary header files here
#include <stdlib.h> // malloc, realloc, free

// Forward declaration because this file relies on array_fill implemented elsewhere.
int array_fill(int *array, int array_len, int begin, int end);

/**
 * Creates and returns a dynamically allocated array containing all EVEN numbers
 * in the inclusive range [begin, end], in increasing order.
 * Returns NULL if the range is invalid or if there are no even numbers.
 * Caller is responsible for freeing the returned array.
 */
int* array_create_evens(int begin, int end) {
    if (begin > end) {
        return NULL;
    }

    int total = end - begin + 1;
    if (total <= 0) {
        return NULL;
    }

    int *buf = (int*)malloc((size_t)total * sizeof(int));
    if (!buf) {
        return NULL;
    }

    int written = array_fill(buf, total, begin, end);

    int ev_count = 0;
    for (int i = 0; i < written; ++i) {
        if ((buf[i] % 2) == 0) {
            buf[ev_count++] = buf[i];
        }
    }

    if (ev_count == 0) {
        free(buf);
        return NULL;
    }

    int *shrunk = (int*)realloc(buf, (size_t)ev_count * sizeof(int));
    return shrunk ? shrunk : buf;
}

