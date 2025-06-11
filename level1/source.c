#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void run(void) {
    printf("Good... Wait what?\n");
    system("/bin/sh");
}

int main(int argc, char *argv[]) {
    char buffer[64];
    
    gets(buffer);
    
    return 0;
}
