#include "input_usr.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>

struct output get_string(void) {
    // Variable initialization
    char *line = NULL; // User input
    size_t len = 0; // Buffer size
    ssize_t char_read; // Read characters, returns -1 on error
    struct output result; 

    char_read = getline(&line, &len, stdin);
    if (char_read == -1){ // getline always outputs -1 on error or EOF, so we use feof to distinguish the two cases
        free(line);
        result.out.string = NULL;
        if (feof(stdin)){
            result.error_code = USER_EOF;
            return result;
        }else{
            result.error_code = GETLINE_RUN_ERROR;
            return result;
        }
    }
    result.out.string = line;
    result.error_code = OK;
    return result;
}

struct output get_num(void){
    long parsed_input; // Output of function
    char *endptr; // Points to the last processed character in strtol
    struct output result; 
    struct output input = get_string();

    if (input.error_code == OK){
        errno = 0;
        parsed_input = strtol(input.out.string, &endptr, 10);

        /*
        strtol outputs 0 if it doesn't parse any digit, meaning it
        could be confused with the user input 0 (exit program).
        So we check directly if strtol has done anything by comparing endptr with line.
        */

        // Checks if endptr hasn't moved (meaning that it didn't work properly)
        if (endptr == input.out.string) {
            free(input.out.string);
            result.out.num = -1;
            result.error_code = STRTOL_RUN_ERROR;
            return result;
        } // Checks for underflow/overflow
        else if (((errno == ERANGE) && (parsed_input == LONG_MAX || parsed_input == LONG_MIN)) || (errno != 0 && parsed_input == 0)){
            free(input.out.string);
            result.out.num = -1;
            result.error_code = OVERFLOW;
            return result;
        } // Last case: endptr has moved and either it has reached the end (\n, \0) or has found junk (extra letters) on its input
        else{
            if (*endptr == '\n' || *endptr == '\0'){ // Uses '' as "" references a string
                free(input.out.string);
                result.out.num = parsed_input;
                result.error_code = OK;
                return result; 
            }else{
                free(input.out.string);
                result.out.num = -1;
                result.error_code = STRTOL_CHAR_JUNK;
                return result;
            }
        } 
    }else{
        result.out.num = -1;
        result.error_code = input.error_code;
        return result;
    }

}