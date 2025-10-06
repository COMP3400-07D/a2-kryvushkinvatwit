#include <stddef.h> // For NULL
#include <stdbool.h> // For true/false
#include <ctype.h>   // For isupper, islower, isalpha, isdigit

/**
 * Checks if the given string `s` is a valid password.
 *
 * A valid password must:
 *  - Have a length between 6 and 10 characters (inclusive)
 *  - Contain only letters (a–z, A–Z) and digits (0–9)
 *  - Include at least two lowercase letters
 *  - Include at least two uppercase letters
 *
 * Returns true if valid, false otherwise.
 */
bool valid_password(const char* s) {
    if (!s) return false;

    int length = 0;
    int lower_count = 0;
    int upper_count = 0;

    for (const char* p = s; *p != '\0'; ++p) {
        unsigned char ch = (unsigned char)*p;

        if (!(isalpha(ch) || isdigit(ch))) {
            return false; // invalid character
        }
        if (islower(ch)) lower_count++;
        if (isupper(ch)) upper_count++;

        length++;
        if (length > 10) {
            return false; // too long
        }
    }

    if (length < 6) return false;
    if (lower_count < 2) return false;
    if (upper_count < 2) return false;

    return true;
}


