#include "header.h"

char command[100];
static char src[100];
static char dest[100];

void commandparser(struct data new){

    strcpy(command,new.command);
    // printf("%s %s %s",command,src,dest);

    if (strcmp(command,"source") == 0){
        strcpy(src,new.src);
    }

    if (strcmp(command,"dest") == 0){
        strcpy(dest,new.src);
    }

    if (strcmp(command,"ls") == 0){
        lscommand(src);
    }

    if (strcmp(command,"lls") == 0){
        lscommand(dest);
    }

    if (strcmp(command,"copy") == 0){
        copy_directory(src,dest);
    }

    printf("%s %s %s", command,src,dest);
}