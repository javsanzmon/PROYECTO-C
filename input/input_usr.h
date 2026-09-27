#ifndef INPUT_USR_H
#define INPUT_USR_H

enum state {OVERFLOW, GETLINE_RUN_ERROR, STRTOL_RUN_ERROR, OK, USER_EOF, STRTOL_CHAR_JUNK};
struct output{
    long num;
    enum state error_code;
};

struct output get_input(void);

#endif