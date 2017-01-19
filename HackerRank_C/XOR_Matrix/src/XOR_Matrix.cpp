//============================================================================
// Name        : XOR_Matrix.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include <vector>

using namespace std;

#define MAX_COL 100000

unsigned int N;
unsigned long long M;

unsigned CURR[MAX_COL];
unsigned NEW[MAX_COL] = { 0 };
bool IXs[MAX_COL] = { 0 };

void init();
void process();
void print(unsigned* arr, unsigned int size);

int main() {
    scanf("%u %llu", &N, &M);

    init();
//    printf("Row    0 |");
//    print(CURR, N);
    unsigned long long m = M;
    for (unsigned long long i = 0; i < m; i++) {
        M = i;
        process();
        printf("Row %2d | ", i);
        print(NEW, N);
        printf("\n");
    }

    return 0;
}

void process() {
    unsigned long long lastRow = M - 1;
    for (unsigned long long i = 0; i < M; i++) {
        if ((i & lastRow) == i) {
            IXs[i % N] ^= 1;
        }
    }

    vector<unsigned> ixs;
    for (unsigned i = 0; i < N; i++) {
        if (IXs[i])
            ixs.push_back(i);
        NEW[i] = 0;
    }

    for (unsigned i = 0; i < N; i++) {
        for (unsigned ix : ixs) {
            NEW[i] ^= CURR[(i + ix) % N];
        }
    }
}

void init() {
    for (unsigned i = 0; i < N; i++) {
        CURR[i] = i;
        //scanf("%u", CURR + i);
    }
}

void print(unsigned* arr, unsigned int size) {
    for (unsigned i = 0; i < size; i++) {
        printf("%2u ", arr[i]);
    }
    //printf("\n");
}
