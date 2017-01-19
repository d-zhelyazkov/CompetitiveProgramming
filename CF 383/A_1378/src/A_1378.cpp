//============================================================================
// Name        : A_1378.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cstdio>

char lastDigits[] = { 8, 4, 2, 6 };

int main() {
    unsigned n;
    scanf("%u", &n);
    if (!n) {
        printf("1");
    } else {
        n--;
        n %= 4;
        printf("%hhu", lastDigits[n]);
    }
    return 0;
}
