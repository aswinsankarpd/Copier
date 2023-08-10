#include "header.h"


// to print contents of the current sub directory.
void lscommand(char *src){
    DIR *dir;
    struct dirent *entry;

    dir = opendir(src);

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            printf("%s\n", entry->d_name);
        }
    }

    closedir(dir);
    
}