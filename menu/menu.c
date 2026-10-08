#include "input/input_usr.h"
#include <errno.h>
#include <strlib.h>

struct output case = get_num();
// Checkear si el input va sin fallos
if (case.error_code == INPUT_OK){
    // Printeo de menu...
    printf(
        "Program emulating a process scheduler\n\n"
        "Select one of the following options:\n\n"
        "1. Add a new process to the schedule\n"
        "2. Delete a specific process from the schedule\n"
        "3. Information about a process\n"
        "4. Show the entire schedule\n"
        "5. Delete the current schedule\n"
        "6. Sort the schedule by a criterion\n"
        "7. Help\n"
        "0. Exit\n\n"
        "If you enter CTRL+D:\n"
        "   - In this menu, the program will terminate gracefully.\n"
        "   - In a submenu, the program will return to this menu.\n\n"

        "Please, enter an option (help: 7): "
        );
    // Switch para llamar a x función dependiendo del input    
    switch(case){
        // Añadir funciones cuando tengamos todas...
        case 1:

        case 2:

        case 3:

        case 4:

        case 5:
    
        case 6:
    
        case 7:
    
        case 0:
        
        default:    
    }
}

