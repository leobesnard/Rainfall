#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void p(void) {
    char buffer[64];        // Local buffer on the stack
    unsigned long *ret_ptr; // Pointer to store the return address
    
    fflush(stdout);
    
    // Read user input without bounds checking - VULNERABILITY 
    gets(buffer);
    
    // Get the return address from the stack
    // In real assembly, this is retrieved from the stack frame
    ret_ptr = (unsigned long *)__builtin_return_address(0);
    
    // Protection check: Is the return address in the stack region?
    // Stack addresses typically start with 0xb on 32-bit Linux
    if ((*ret_ptr & 0xb0000000) == 0xb0000000) {
        // Attempted stack-based exploit detected!
        printf("(%p)\n", (void *)*ret_ptr);
        _exit(1); // Terminate the program
    }
    
    puts(buffer);               
    strdup(buffer);            
                              
                                // shellcode to heap memory (starts with 0x08)
    
}

int main() {
    p();
    return 0;
}
