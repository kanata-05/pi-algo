#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

unsigned long long modPow(unsigned long long base, unsigned long long exp, unsigned long long mod) {
    unsigned long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

long double bbpIter(int terms) {
    long double pi = 0.0;
    double power = 1.0;
    long double term;

    for (int k = 0; k < terms; k++) {
        term = power * (4.0/(8*k + 1) - 2.0/(8*k + 4) - 1.0/(8*k + 5) - 1.0/(8*k + 6));
        pi += term;
        power /= 16.0;
    }
    return pi;
}

int bbpDigit(int n) {
    long double S(int j, int n) {
        long double s = 0.0;
        for (int k = 0; k < n; k++) {
            int r = 8 * k + j;
            s += (long double)modPow(16, n - k, r) / r;
        }
        s -= floor(s);

        long double t = 0.0;
        int k = n;
        while (1) {
            int r = 8 * k + j;
            long double term = powl(16.0L, (long double)(n - k)) / r;
            if (term < 1e-15L) break;
            t += term;
            k++;
        }

        return s + t;
    }

    long double x = 4 * S(1, n) - 2 * S(4, n) - S(5, n) - S(6, n);
    x -= floor(x);
    int digit = (int)(x * 16);
    if (digit < 0) digit = 0;
    return digit;
}
