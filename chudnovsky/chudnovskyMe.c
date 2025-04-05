#include <stdio.h>
#include <math.h>
#include <stdint.h>

typedef struct {
    float Pab;
    float Qab;
    float Rab;
    float Pam;
    float Qam;
    float Ram;
    float Pmb;
    float Qmb;
    float Rmb;
    long double P1n;
    long double Q1n;
    long double R1n;
} binarySplitT;

binarySplitT binarySplit(int a, int b) {
    binarySplitT val;

    if (b == a + 1) {
        val.Pam = val.Pmb = 0;
        val.Qam = val.Qmb = 0;
        val.Ram = val.Rmb = 0;

        val.Pab = -(6*a - 5) * (2*a - 1) * (6*a - 1);
        val.Qab = 10939058860032000.0 * pow(a, 3);
        val.Rab = val.Pab * (545140134 * a + 13591409);
    } else {
        int m = (int)ceil((a + b) / 2.0);

        binarySplitT left = binarySplit(a, m);
        binarySplitT right = binarySplit(m, b);

        val.Pam = left.Pab;
        val.Qam = left.Qab;
        val.Ram = left.Rab;

        val.Pmb = right.Pab;
        val.Qmb = right.Qab;
        val.Rmb = right.Rab;

        val.Pab = val.Pam * val.Pmb;
        val.Qab = val.Qam * val.Qmb;
        val.Rab = val.Qmb * val.Ram + val.Pam * val.Rmb;
    }
    return val;
}

long double chudnovsky(int n) {
    binarySplitT val = binarySplit(1, n);

    long double sqrtF = sqrtl(10005.0L);
    long double C = 426880.0L * sqrtF;
    long double numerator = C * val.Qab;
    long double denominator = 13591409.0L * val.Qab + val.Rab;

    return numerator / denominator;
}

int main() {
    printf("%.30Lf", chudnovsky(2));
    return 0;
}
