#ifndef INPUT_USR_H
#define INPUT_USR_H

enum input_state {STRTOL_OVERFLOW, GETLINE_RUN_ERROR, STRTOL_RUN_ERROR, INPUT_OK, USER_EOF, STRTOL_CHAR_JUNK};
union result {
    long num;
    char *string;
};
struct output{
    union result out;
    enum input_state error_code;
};

struct output get_string(void);
struct output get_num(void);

#endif