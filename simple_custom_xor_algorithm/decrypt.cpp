#include <Windows.h>
#include <stdio.h>

unsigned char sh_encrypted[] = "your_shellcode";

int key = "XOR Key Used to Encrypt";

void xor_decrypt(unsigned char* encrypted, int size, int key, unsigned char* decrypted) {
    int counter = 3;
    for (int i = 0; i < size; i++) {
        int xored = encrypted[i] ^ key;
        int data_plus = xored - counter;
        decrypted[i] = data_plus;
    }
}

int main() {

    int size = sizeof(sh_encrypted) / sizeof(sh_encrypted[0]);
    unsigned char* buffer = (unsigned char*)malloc(size * sizeof(unsigned char));
    xor_decrypt(sh_encrypted, size, key, buffer);
    printf("XOR Key: %d\n", key);
    printf("Shellcode Decrypted: ");
    for (int i = 0; i < size; i++) {
        printf("\\x%02x", buffer[i]);
    }
    printf("\n");

    return 0;

}
