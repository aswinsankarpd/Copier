#include "header.h"

void copy_handler(const char* source_dir, const char* dest_dir, char* recursive){
    printf("%s",recursive);
    if (strcmp(recursive,"-R") == 0){
        copy_directory(source_dir,dest_dir);
    }
    else{
        copy_file(source_dir,dest_dir);
    }
}

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
    }
}

void copy_directory(const char* source_dir, const char* dest_dir) {
    DIR* dir;
    struct dirent* entry;
    char source_path[100];
    char dest_path[100];

    dir = opendir(source_dir);
    if (dir == NULL) {
        printf("Error opening directory!\n");
        return;
    }

    _mkdir(dest_dir);

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(source_path, sizeof(source_path), "%s/%s", source_dir, entry->d_name);
        snprintf(dest_path, sizeof(dest_path), "%s/%s", dest_dir, entry->d_name);

        if (entry->d_type == DT_REG) {
            copy_file(source_path, dest_path);
        } else if (entry->d_type == DT_DIR) {
            copy_directory(source_path, dest_path);
        }
    }

    closedir(dir);
}