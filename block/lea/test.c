
// test unit for LEA-128 block cipher
// odzhan

#include <stdio.h>
#include <stdint.h>
#include <string.h>

// 128-bit master key
uint8_t key[16] = 
{0x0f, 0x1e, 0x2d, 0x3c, 0x4b, 0x5a, 0x69, 0x78, 
 0x87, 0x96, 0xa5, 0xb4, 0xc3, 0xd2, 0xe1, 0xf0};
 
// 128-bit plain text
uint8_t plain[16] = 
{0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 
 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f};
 
// 128-bit cipher text
uint8_t cipher[16] = 
{0x9f, 0xc8, 0x4e, 0x35, 0x28, 0xc6, 0xc6, 0x18, 
 0x55, 0x32, 0xc7, 0xa7, 0x04, 0x64, 0x8b, 0xfd};
 
void lea128(void *mk, void *data);

int main(void) {
    uint8_t  data[16];
    int      equ;
    
    memcpy (data, plain, 16);
    lea128(key, data);
    equ = (memcmp(data, cipher, 16)==0);
    printf("LEA-128 test : %s\n", equ ? "OK" : "FAILED");
    return 0;
}
  

