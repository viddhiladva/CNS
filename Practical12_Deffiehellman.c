#include <stdio.h>
#include <math.h>

// Function to calculate power using modulo operator
int power(int base, int exponent, int modulus) {
    if (exponent == 0)
        return 1;
    
    long result = 1;
    base %= modulus;
    
    while (exponent > 0) {
        if (exponent % 2 == 1)
            result = (result * base) % modulus;
        
        base = (base * base) % modulus;
        exponent /= 2;
    }
    
    return result;
}

// Function to perform the Diffie-Hellman key exchange
void diffieHellman(int p, int g, int a, int b) {
    int aliceSecret, bobSecret, aliceKey, bobKey;
    
    // Calculate Alice's secret key
    aliceSecret = power(g, a, p);
    
    // Calculate Bob's secret key
    bobSecret = power(g, b, p);
    
    // Calculate the shared key for Alice and Bob
    aliceKey = power(bobSecret, a, p);
    bobKey = power(aliceSecret, b, p);
    
    printf("Alice's secret key: %d\n", aliceSecret);
    printf("Bob's secret key: %d\n", bobSecret);
    printf("Shared key: %d\n", aliceKey);
}

int main() {
    int p, g, a, b;
    
    printf("Enter a prime number (p): ");
    scanf("%d", &p);
    
    printf("Enter a primitive root of %d (g): ", p);
    scanf("%d", &g);
    
    printf("Enter the private key for Alice (a): ");
    scanf("%d", &a);
    
    printf("Enter the private key for Bob (b): ");
    scanf("%d", &b);
    
    diffieHellman(p, g, a, b);
    
    return 0;
}
