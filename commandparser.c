#include "header.h"

char command[100];
static char src[100];
static char dest[100];
static char thesource[100];
static char thedest[100];
void commandparser(struct data new){

    strcpy(command,new.command);

    if (strcmp(command,"src") == 0){
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

    if ((strcmp(command,"copy") == 0) && (strcmp(new.dest,"*.c") == 0)){
        copyFilesWithExtension(thesource,thedest,"*.c");
    }

    if (strcmp(command,"copy") == 0){
        if (strcmp(new.src,"-R") == 0)
            copy_handler(thesource,thedest,new.src);
        else
            copy_handler(thesource,thedest," ");
    }


    if (strcmp(command,"move") == 0){
        moveFilesRecursively(thesource,thedest);
    }

    if (strcmp(command,"help") == 0){
        printf("ls\nlls\ndest [diffDir]\nsrc  [diffDir]\ncopy -R file(s) *.c *.txt h*\nmove");
    }

    printf("%s %s %s ", command,src,dest);
}