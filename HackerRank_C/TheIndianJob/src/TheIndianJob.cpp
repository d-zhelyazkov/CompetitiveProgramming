//============================================================================
// Name        : TheIndianJob.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cstdio>
#include <vector>
#include <unordered_set>

using namespace std;

#define MAX_N 100

unsigned char N = 0;
unsigned char ARR[MAX_N + 1];
unsigned G = 0;

bool check();

int main() {
    unsigned char T;
    scanf("%hhu\n", &T);
    while (T--) {

        scanf("%hhu %u\n", &N, &G);

        for (unsigned char i = 0; i < N;) {
            unsigned char Ai;
            scanf("%hhu", &Ai);
            //filters zeroes
            if (Ai) {
                ARR[i++] = Ai;
            } else {
                N--;
            }
        }

        if (check()) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }

    }

    return 0;
}

bool check() {
    unsigned globalSum = 0;
    for (unsigned char i = 0; i < N; i++) {
        if (G < ARR[i])
            return false;

        globalSum += ARR[i];
    }
    //initial check
    if (globalSum <= G)
        return true;
    unsigned sumThresh = globalSum - G;
    if (G < sumThresh)
        return false;

    unordered_set<unsigned>* sums = new unordered_set<unsigned>();
    sums->insert(0);
    for (unsigned char i = 0; i < N; i++) {

        unordered_set<unsigned>* newSums = new unordered_set<unsigned>(*sums);
        for (unsigned sum : *sums) {
            unsigned newSum = sum + ARR[i];
            if (newSum <= G) {
                if (sumThresh <= newSum)
                    return true;

                newSums->insert(newSum);
            }

        }
        delete sums;
        sums = newSums;
    }

    return false;
}
