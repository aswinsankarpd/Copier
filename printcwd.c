#include "header.h"


// to print current working directory 
void printcwd() {
    char cwd[4096];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("Copier %s > ", cwd);
    } else {
        perror("getcwd error");
    }
}
