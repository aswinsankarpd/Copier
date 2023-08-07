#include "header.h"

int main() {

    char source_string[100];

    while(1){
        /*PRINTING FORMALITIES - BEGIN*/
        printcwd();
        /*PRINTING FORMALITIES - END*/

    
        /*ACCQUIRING USER INPUT - BEGIN*/
        scanf("%[^\n]s",source_string);
        getchar();

        if (strcmp(source_string, "quit") == 0) {
            break;
        }

        struct data new;
        new = substring(source_string);

        commandparser(new);
    }

}