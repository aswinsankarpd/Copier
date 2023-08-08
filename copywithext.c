#include "header.h"

void copyFile(const char *srcPath, const char *destPath) {
    FILE *srcFile = fopen(srcPath, "rb");
    if (srcFile == NULL) {
        perror("Error opening source file");
        return;
    }

    FILE *destFile = fopen(destPath, "wb");
    if (destFile == NULL) {
        perror("Error creating destination file");
        fclose(srcFile);
        return;
    }

    char buffer[4096];
    size_t bytesRead;
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), srcFile)) > 0) {
        fwrite(buffer, 1, bytesRead, destFile);
    }

    fclose(srcFile);
    fclose(destFile);
}

void copyFilesWithExtension(const char *srcDir, const char *destDir, const char *extension) {
    DIR *dir = opendir(srcDir);

    if (dir == NULL) {
        perror("Error opening source directory");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char srcPath[1024];
        char destPath[1024];
        snprintf(srcPath, sizeof(srcPath), "%s/%s", srcDir, entry->d_name);
        snprintf(destPath, sizeof(destPath), "%s/%s", destDir, entry->d_name);

        struct stat st;
        if (stat(srcPath, &st) == 0 && S_ISREG(st.st_mode)) {
            const char *fileExt = strrchr(entry->d_name, '.');
            if (fileExt != NULL && strcmp(fileExt, extension) == 0) {
                copyFile(srcPath, destPath);
            }
        }
    }

    closedir(dir);
}