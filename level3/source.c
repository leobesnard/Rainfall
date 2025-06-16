#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int m = 0;  // Global variable at address 0x804988c

void v(void) {
    char buffer[512];  // Local buffer for user input
    
    fgets(buffer, sizeof(buffer), stdin);
    
    // VULNERABILITY: Direct user input used as format string
    printf(buffer);  // Should be: printf("%s", buffer)
    
    // Check if the global variable equals 64 (0x40)
    if (m == 64) {
        fwrite("Wait what?!\n", 1, 12, stdout);
        
        // Execute a shell with the privileges of the program
        system("/bin/sh");
    }
    
    return;
}

int main(void) {
    v();
    return 0;
}
