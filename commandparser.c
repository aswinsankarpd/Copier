#include "header.h"

char command[100];
static char src[100];
static char dest[100];
static char thesource[100];
static char thedest[100];
void commandparser(struct data new){

    strcpy(command,new.command);

    if (strcmp(command,"source") == 0){
        strcpy(src,new.src);
        strcpy(thesource,new.src);
    }

    if (strcmp(command,"dest") == 0){
        strcpy(dest,new.src);
        strcpy(thedest,new.src);
    }

    if (strcmp(command,"ls") == 0){
        lscommand(src);
    }

    if (strcmp(command,"lls") == 0){
        lscommand(dest);
    }

    if (strcmp(command,"copy") == 0){
        if (strcpy(new.src,"-R"))
            copy_handler(thesource,thedest,new.src);
        else
            copy_handler(thesource,thedest," ");
    }

    printf("%s %s %s ", command,src,dest);
}