#include <stdio.h>
#include <string.h>

// A simple and small range hash function
unsigned short simple_hash(const char *str) {
    unsigned short hash = 7;  // Using a small prime number as seed
    int c;

    while (*str != '\0') {
        c = *str;   // Take the current character from the string
        str++;      // Move the pointer to the next character

        printf("during calculation, hash * 31 + c = %u\n", hash * 31 + c);
        // Calculate hash value using a small prime multiplier and modulus to keep the value low
        hash = (hash * 31 + c) % 100000; // 2113;  // Using 2113 as it's the largest prime below 65536/31
    }

    return hash;
}

int main(int argc, char *argv[]) {
    char text[101];  // Array to store up to 100 characters + 1 for null terminator
    printf("Enter a string (up to 100 characters): ");
    fgets(text, sizeof(text), stdin);  // Read up to 100 characters from stdin

    // Remove newline character if fgets stops reading because of it
    if (text[strlen(text) - 1] == '\n') {
        text[strlen(text) - 1] = '\0';
    }

    unsigned short result = simple_hash(text);
    printf("The hash of \"%s\" is %u\n", text, result);

    return 0;
}
