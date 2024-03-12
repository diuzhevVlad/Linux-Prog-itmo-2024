#include "dlfcn.h"
#include "stdio.h"
#include <stdlib.h>

int (*some_func) (int);

int main(int argc, char* argv[]){
    void* hdl = dlopen(argv[1],RTLD_LAZY);
    some_func = (int(*)(int))dlsym(hdl, argv[2]);
    printf("%d\n",some_func(atoi(argv[3])));
    return 0;
}