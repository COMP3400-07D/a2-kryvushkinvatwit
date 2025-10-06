#include <stddef.h> // For NULL
// TODO: Include any necessary header files here

/**
 * Fills the given character array `dest` with the character `c`, 
 * repeating it up to `dest_cap - 1` times, and then appends a 
 * null terminator ('\0') at the end to make it a proper string.
 *
 * If `dest` is NULL or `dest_cap` is less than or equal to 0,
 * the function does nothing.
 *
 * Examples:
 *  dest_cap = 2, c = 'S' → "S"
 *  dest_cap = 9, c = 'R' → "RRRRRRRR"
 *  dest_cap = 1, c = 'G' → ""
 */
void string_fill(char dest[], int dest_cap, char c) {
    if (!dest || dest_cap <= 0) return;

    if (dest_cap == 1) {
        dest[0] = '\0';
        return;
    }

    int fill = dest_cap - 1; // leave room for null terminator
    for (int i = 0; i < fill; ++i) {
        dest[i] = c;
    }

    dest[fill] = '\0';
}


