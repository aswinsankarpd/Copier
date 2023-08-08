#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>


struct data{
    char command[100];
    char src[100];
    char dest[100];
};

void lscommand();
void printcwd();
struct data substring(char *source_string);
void commandparser(struct data new);
void copy_handler(const char* source_dir, const char* dest_dir, char* recursive);
void copy_file(const char* source_path, const char* destination_path);
void copy_directory(const char* source_dir, const char* dest_dir);
void moveFile(const char *srcPath, const char *destPath);
void moveFilesRecursively(const char *srcDir, const char *destDir);
void copyFile(const char *, const char *);
void copyFilesWithExtension(const char *, const char *, const char *);
