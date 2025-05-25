#include <math.h>
#include <cstdlib>
#include <iostream>
#include <sstream>
using namespace std;

unsigned int GCD(unsigned int a, unsigned int b) {
    while (b != 0) {
        unsigned int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
 
unsigned int Inverse(unsigned int x, unsigned int m) {
    int m0 = m;
    int y = 0, x1 = 1;
    
    while (m != 0) {
        int q = x / m;
        int temp = m;
        m = x % m;
        x = temp;
        int temp_y = y;
        y = x1 - q * y;
        x1 = temp_y;
    }
    
    if (x1 < 0) {
        x1 += m0;
    }
    
    return x1;
}

unsigned int QuickPower(unsigned int a, unsigned int n, unsigned int m) {
    unsigned long long result = 1;
    unsigned long long base = a % m;
    
    while (n > 0) {
        if (n % 2 == 1) {
            result = (result * base) % m;
        }
        base = (base * base) % m;
        n /= 2;
    }
    
    return result;
}

string Task1 (unsigned int* source, unsigned int sourceSize, unsigned int p, unsigned int q, bool encryptionMode) {
    stringstream functionOutput;
    
    unsigned int n = p * q;
    
    unsigned int p_minus_1 = p - 1;
    unsigned int q_minus_1 = q - 1;
    unsigned int lambda_n = (p_minus_1 * q_minus_1) / GCD(p_minus_1, q_minus_1);
    
    unsigned int e = 10;
    while (e < lambda_n && GCD(e, lambda_n) != 1) {
        e++;
    }
    
    unsigned int d = Inverse(e, lambda_n);
    
    for (unsigned int i = 0; i < sourceSize; i++) {
        unsigned int m = source[i];
        unsigned int result;
        
        if (encryptionMode) {
            result = QuickPower(m, e, n);
        } else {
            result = QuickPower(m, d, n);
        }
        
        functionOutput << result;
        if (i < sourceSize - 1) {
            functionOutput << " ";
        }
    }
    
    return functionOutput.str();
}
