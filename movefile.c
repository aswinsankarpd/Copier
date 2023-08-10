#include "header.h"

//move files normally
void moveFile(const char *srcPath, const char *destPath) {
    if (rename(srcPath, destPath) != 0) {
        perror("Error moving file");
    }
}

//recursive copying by repearting normal copying
void moveFilesRecursively(const char *srcDir, const char *destDir) {
    struct dirent *entry;
    DIR *dir = opendir(srcDir);

    if (dir == NULL) {
        perror("Error opening directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char srcPath[1024];
        char destPath[1024];
        snprintf(srcPath, sizeof(srcPath), "%s/%s", srcDir, entry->d_name);
        snprintf(destPath, sizeof(destPath), "%s/%s", destDir, entry->d_name);

        struct stat st;
        if (stat(srcPath, &st) == 0) {
            if (S_ISREG(st.st_mode)) {
                moveFile(srcPath, destPath);
            } else if (S_ISDIR(st.st_mode)) {
                mkdir(destPath);  // Create destination directory if not exists
                moveFilesRecursively(srcPath, destPath);
                rmdir(srcPath);
            }
        }
    }

    closedir(dir);
}