#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char global_buffer[68];

void m(void) {
    time_t current_time;
    
    current_time = time(NULL);
    printf("%s - %d\n", global_buffer, (int)current_time);
}

int main(int argc, char *argv[]) {
    struct data {
        int number;
        char *buffer;
    };
    
    struct data *first_data = malloc(sizeof(struct data));
    first_data->number = 1;
    first_data->buffer = malloc(8);
    
    struct data *second_data = malloc(sizeof(struct data));
    second_data->number = 2;
    second_data->buffer = malloc(8);
    
    /* Vulnerability: Unsafe strcpy can overflow buffers */
    if (argc > 1)
        strcpy(first_data->buffer, argv[1]);  // First overflow
    
    if (argc > 2)
        strcpy(second_data->buffer, argv[2]);  // Second overflow
    
    FILE *file = fopen("./r", "r");
    if (file != NULL) {
        fgets(global_buffer, sizeof(global_buffer), file);
        fclose(file);
    }
    
    puts("~~");
    
    return 0;
}
