#include  "input_usr.h"
#include <stdio.h>
#include <stdlib.h>

int get_input(void) {
    // Variable initialization
    char *line = NULL; // User input
    size_t len = 0; // Buffer size
    ssize_t char_read; // Read characters, returns -1 on error
    long parsed_input = 0; // Output of function
    char *endptr; // Points to the last processed character in strtol

    while(1){ // Loop always runs, stopped/continued with return/continue
        char_read = getline(&line, &len, stdin);
        if (char_read == -1){
            free(line);
            //Error handling here
        }else{
            parsed_input = strtol(line, &endptr, 10);
            if (endptr == line) {
                continue // strtol couldn't find any parseable digit, asks again for input
            }else if (endptr != line){
                /*
                strtol outputs 0 if it doesn't parse any digit, meaning it
                could be confused with the user input 0 (exit program).
                So we check directly if strtol has done anything by comparing witha endptr.
                */
                return parsed_input;               
            }else{
                return 0; // Exit returns 0
            }
        }
    }

}