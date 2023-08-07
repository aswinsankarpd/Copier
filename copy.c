#include "header.h"


void copy_file(const char* source_path, const char* destination_path) {
    FILE* source_file = fopen(source_path, "rb");
    FILE* destination_file = fopen(destination_path, "wb");

    if (source_file && destination_file) {
        int ch;
        while ((ch = fgetc(source_file)) != EOF) {
            fputc(ch, destination_file);
        }
        fclose(source_file);
        fclose(destination_file);
    } else {
        printf("Error opening file!\n");
    }
}

void copy_directory(const char* source_dir, const char* dest_dir) {
    DIR* dir;
    struct dirent* entry;
    char source_path[100];
    char dest_path[100];

    dir = opendir(source_dir);
    printf("sjdfhksdjf %s",source_dir);
    if (dir == NULL) {
        printf("Error opening directory!\n");
        return;
    }

    // Create destination directory if it doesn't exist
    // mkdir(dest_dir, 0777);

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(source_path, 100, "%s/%s", source_dir, entry->d_name);
        snprintf(dest_path, 100, "%s/%s", dest_dir, entry->d_name);

        if (entry->d_type == DT_REG) {
            // If it's a regular file, copy it
            copy_file(source_path, dest_path);
        } else if (entry->d_type == DT_DIR) {
            // If it's a subdirectory, recursively copy its contents
            copy_directory(source_path, dest_path);
        }
    }

    closedir(dir);
}