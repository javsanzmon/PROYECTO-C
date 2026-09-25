#include  "input_usr.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>

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
            exit(EXIT_FAILURE);
        }
        errno = 0;
        parsed_input = strtol(line, &endptr, 10);
        if (endptr == line) {
            printf("No parseable digits were found, try again...\n");
            continue; // strtol couldn't find any parseable digit, asks again for input
        }else if (errno == ERANGE && (parsed_input == LONG_MAX || parsed_input == LONG_MIN) || (errno != 0 && parsed_input == 0)){
            // overflow state, errno = ERANGE and we ask for input again
            printf("Input overflowed (string is either too big/small), try again...");
            continue;
        }else{
            /*
            strtol outputs 0 if it doesn't parse any digit, meaning it
            could be confused with the user input 0 (exit program).
            So we check directly if strtol has done anything by comparing with endptr.
            */
            if ((parsed_input >= 0 && parsed_input <= 7) && (*endptr == '\n' || *endptr == '\0')){ // Uses '' as "" references a string
                free(line);
                return (int)parsed_input;   
            }else{
                printf("Inputed value is not allowed (!= 0-7) or contains garbage (extra characters), try again...");
                continue;
            }
           
        } 
        
    }

}