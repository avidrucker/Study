#include <stdio.h>

// Simple hash function (DJB2)
unsigned int simple_hash(const char *str) {
    unsigned long hash = 5381;
    int c;

    while (*str != '\0') { // Use explicit comparison for clarity
        c = *str;  // Take the current character from the string
        str++;     // Move the pointer to the next character
        
        // Compute hash * 33 + c using more explicit operations
        hash = (hash << 5);   // hash * 32
        hash = hash + hash;  // hash * 32 + hash = hash * 33
        hash = hash + c;     // Finally add the ASCII value of the character
    }

    return hash;
}

int main(int argc, char *argv[]) {
    char text[] = "hello";
    unsigned int result = simple_hash(text);
    printf("The hash of \"%s\" is %u\n", text, result);
    
    return 0;
}