#include <stddef.h> // For NULL

/**
 * Fills the given array with numbers from 'begin' to 'end' (inclusive)
 * in increasing order, but writes at most 'array_len' elements.
 * Returns the number of elements successfully written.
 *
 * Examples:
 *  array_len=2, begin=11, end=12  → {11,12}, returns 2
 *  array_len=6, begin=11, end=14  → {11,12,13,14}, returns 4
 *  array_len=2, begin=11, end=14  → {11,12}, returns 2
 *  array_len=0, begin=11, end=14  → N/A, returns 0
 */
int array_fill(int* array, int array_len, int begin, int end) {
    if (!array || array_len <= 0 || begin > end) {
        return 0;
    }

    int total = end - begin + 1;
    int count = (total < array_len) ? total : array_len;

    for (int i = 0; i < count; ++i) {
        array[i] = begin + i;
    }

    return count;
}

