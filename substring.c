#include "header.h"


// reading input arguments differently and storing them in the variables
struct data substring(char *source_string){
   
    struct data new;
    int len = sscanf(source_string,"%s %s %s",new.command,new.src,new.dest);
   
    return new;
}
