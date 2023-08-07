#include "header.h"

struct data substring(char *source_string){
   
    struct data new;
    int len = sscanf(source_string,"%s %s %s",new.command,new.src,new.dest);
   
    return new;
}
