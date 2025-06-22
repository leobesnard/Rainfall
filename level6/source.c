#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

void n(void) {
    system("/bin/cat /home/user/level7/.pass");
}

void m(void) {
    puts("Nope");
}

int main(int argc, char *argv[]) {
    char *buffer1;      // Will hold user input
    void (**buffer2)(); // Will hold function pointer
    
    buffer1 = malloc(64);
    
    buffer2 = malloc(4);
    
    *buffer2 = m;
    
    // VULNERABILITY: Unsafe strcpy without bounds checking
    if (argc > 1) {
        strcpy(buffer1, argv[1]); // Can overflow buffer1 into buffer2
    }
    
    (*buffer2)();
    
    return 0;
}
