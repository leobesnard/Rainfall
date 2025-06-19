#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void o(void) {
    system("/bin/sh");
    _exit(1);  // Use _exit() to immediately terminate without cleanup
}

void n(void) {
    char buffer[512];
    
    // Read user input safely with fgets
    fgets(buffer, sizeof(buffer), stdin);
    
    // VULNERABILITY: User input is directly passed as a format string
    printf(buffer);  // Should be: printf("%s", buffer);
    
    // Program exits without returning to main
    exit(1);
}

int main(void) {
    n();
    return 0;  // Never reached due to exit() in n()
}
