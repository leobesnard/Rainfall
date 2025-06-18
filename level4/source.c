#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

volatile int m = 0;  // Global variable at address 0x8049810

void p(char *buffer) {
    // VULNERABILITY: Direct user input used as format string
    printf(buffer);  // Should be: printf("%s", buffer);
}

void n(void) {
    char buffer[512];
    
    // Read input safely with fgets
    fgets(buffer, sizeof(buffer), stdin);
    
    // Pass to vulnerable printf wrapper
    p(buffer);
    
    // Check if global variable has been modified to the magic value
    if (m == 0x01025544) {  // 16930116 decimal
        system("/bin/cat /home/user/level5/.pass");
    }
}

int main(void) {
    n();
    return 0;
}
