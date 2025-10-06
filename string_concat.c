#include <stddef.h> // For NULL
// TODO: Include any necessary header files here

/**
 * Concatenates the string `src2` onto the end of `src1`, as long as there is
 * enough space within `src1_cap` (including room for the null terminator).
 * 
 * If `src1` has no null terminator within its capacity, or if `src1` or `src2`
 * are NULL, the function does nothing.
 *
 * Example (src1_cap = 4):
 *  src1 = "AA", src2 = "BB" → result: "AAB"
 */
void string_concat(char* src1, int src1_cap, const char* src2) {
    if (!src1 || !src2 || src1_cap <= 0) return;

    // Find length of src1 (bounded by src1_cap)
    int len1 = 0;
    while (len1 < src1_cap && src1[len1] != '\0') {
        ++len1;
    }

    // If no null terminator found within capacity, cannot safely append
    if (len1 == src1_cap) return;

    // Append from src2 until out of space or end of src2
    int i = len1;
    int j = 0;
    while (i < src1_cap - 1 && src2[j] != '\0') {
        src1[i++] = src2[j++];
    }

    // Add null terminator
    src1[i] = '\0';
}



