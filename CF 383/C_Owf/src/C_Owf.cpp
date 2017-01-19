//============================================================================
// Name        : C_Owf.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cstdio>
using namespace std;

unsigned char indexes[100] = { 0 };
bool map[100] = { 0 };

unsigned gcd(unsigned a, unsigned b) {

    if (!b)
        return a;

    return gcd(b, a % b);
}

unsigned lcm(unsigned a, unsigned b) {
    return a * b / ((a < b) ? gcd(b, a) : gcd(a, b));
}

int main() {
    unsigned char n;
    scanf("%hhu\n", &n);
    for (unsigned char i = 0; i < n; i++) {
        scanf("%hhu", indexes + i);
        indexes[i]--;
    }

    unsigned T = 1;
    for (unsigned char i = 0; i < n; i++) {
        if (map[i])
            continue;
        map[i] = 1;

        unsigned t = 1;
        unsigned char j = indexes[i];
        while (true) {
            if (map[j]) {
                if (i == j) {
                    if (!(t & 1))
                        t >>= 1;
                    T = lcm(T, t);
                    break;
                } else {
                    printf("-1");
                    return 0;
                }
            } else {
                map[j] = 1;
                t++;
                j = indexes[j];
            }
        }
    }

    printf("%u", T);
    return 0;
}
