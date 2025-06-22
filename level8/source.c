#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char *auth = NULL;
char *service = NULL;

int main(void) {
    char buffer[128];
    
    while (1) {
        /* Display the current state of auth and service pointers */
        printf("%p, %p > ", auth, service);
        
        if (fgets(buffer, sizeof(buffer), stdin) == NULL)
            break;
        
        if (strncmp(buffer, "auth ", 5) == 0) {
            auth = malloc(4);
            
            if (auth != NULL) {
                *((int*)auth) = 0;
                
                size_t len = strlen(buffer + 5);
                if (len <= 30) {
                    /* VULNERABILITY: strcpy to a 4-byte buffer */
                    strcpy(auth, buffer + 5);
                }
            }
        }
        
        else if (strncmp(buffer, "reset", 5) == 0) {
            free(auth);
        }
        
        else if (strncmp(buffer, "service", 7) == 0) {
            service = strdup(buffer + 7);
        }
        
        else if (strncmp(buffer, "login", 5) == 0) {
            /* VULNERABILITY: Check memory 32 bytes past auth buffer */
            if (auth != NULL && *((int*)(auth + 32)) != 0) {
                /* Successful login - spawn a shell */
                system("/bin/sh");
            } else {
                fwrite("Password:\n", 1, 10, stdout);
            }
        }
    }
    
    return 0;
}
