#include <stddef.h> // For NULL
// TODO: Include any necessary header files here
#include <stdlib.h> // For malloc
#include <ctype.h>  // For toupper, islower

/**
 * Converts all lowercase alphabetic characters in the string `s`
 * to uppercase and returns a newly allocated string containing
 * the result. All other characters remain unchanged.
 *
 * Returns NULL if `s` is NULL or if memory allocation fails.
 * The caller is responsible for freeing the returned string.
 */
char* capitalize(const char* s) {
    if (!s) return NULL;

    // Compute string length manually (no string.h allowed)
    int len = 0;
    const char* p = s;
    while (*p++ != '\0') {
        len++;
    }

    // Allocate space for new string (including null terminator)
    char* out = (char*)malloc((size_t)len + 1);
    if (!out) return NULL;

    // Convert each lowercase letter to uppercase
    for (int i = 0; i < len; ++i) {
        unsigned char ch = (unsigned char)s[i];
        out[i] = (char)(islower(ch) ? toupper(ch) : ch);
    }

    // Add string terminator
    out[len] = '\0';
    return out;
}


