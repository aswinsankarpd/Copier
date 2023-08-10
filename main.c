/*
Purpose : To implement Copier Functionalities
Date: 6-Aug-2023
Author: Aswin Sankar
*/

#include "header.h"

int main() {

    char source_string[100];

    while(1){
        /*PRINTING FORMALITIES - BEGIN*/
        /*Printing CWD*/
        printcwd();
        /*PRINTING FORMALITIES - END*/

    
        /*ACCQUIRING USER INPUT - BEGIN*/
        scanf("%[^\n]s",source_string);
        getchar(); // Flushing command line

        /*Break condition to quit operation*/
        if (strcmp(source_string, "quit") == 0) {
            break;
        }

        //passing user input to seperate command source and destination files.
        struct data new;
        new = substring(source_string);

        // passing the command to command parser
        commandparser(new);
    }

}