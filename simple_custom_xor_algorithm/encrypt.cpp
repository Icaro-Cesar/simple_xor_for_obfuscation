#include <iostream>
#include <ctime>
#include <cstdlib>
#include <Windows.h>

unsigned char shellcode[] = "your_shell_code";

void xor_encrypt(unsigned char* raw, int size, int key, unsigned char* encrypted) {
    int counter = 3;
    for (int i = 0; i < size; i++) {
        int data_plus = raw[i] + counter;
        int xored = data_plus ^ key;
        encrypted[i] = xored;
    }
}

int main() {
    srand(time(NULL));

    int xor_key = rand() % 254;
    printf("XOR Key: %d\n", xor_key);

    int size = sizeof(shellcode) / sizeof(shellcode[0]);
    unsigned char* buffer = (unsigned char*)malloc(size * sizeof(unsigned char));
    xor_encrypt(shellcode, size, xor_key, buffer);
    printf("Shellcode Encrypted: ");
    for (int i = 0; i < size; i++) {
        printf("\\x%02x", buffer[i]);
    }
    printf("\n");

    return 0;
}
