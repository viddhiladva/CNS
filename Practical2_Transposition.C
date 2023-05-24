#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

void encrypt(char *plaintext, int key);
void decrypt(char *ciphertext, int key);

void main() {
    char input[MAX_LEN];
    int key;
    clrscr();
    printf("Enter a string to encrypt: ");
    fgets(input, MAX_LEN, stdin);
    printf("Enter a key: ");
    scanf("%d", &key);
    encrypt(input, key);
    printf("Encrypted string: %s\n", input);
    decrypt(input, key);
    printf("Decrypted string: %s\n", input);
    getch();
}

void encrypt(char *plaintext, int key) {
    int len = strlen(plaintext),i,j;
    char ciphertext[MAX_LEN];
    int rows = (len + key - 1) / key;
    for ( i = 0; i < rows; i++) {
	for ( j = 0; j < key; j++) {
            int index = i + j * rows;
            if (index < len) {
                ciphertext[i * key + j] = plaintext[index];
            } else {
                ciphertext[i * key + j] = ' ';
            }
        }
    }
    strcpy(plaintext, ciphertext);
}

void decrypt(char *ciphertext, int key) {
    int len = strlen(ciphertext),i,j,index;
    char plaintext[MAX_LEN];
    int rows = (len + key - 1) / key;
    for ( i = 0; i < rows; i++) {
	for ( j = 0; j < key; j++) {
	     index = i * key + j;
            if (index < len) {
                plaintext[i + j * rows] = ciphertext[index];
            }
        }
    }
    strcpy(ciphertext, plaintext);
}