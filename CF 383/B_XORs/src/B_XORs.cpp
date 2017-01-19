//============================================================================
// Name        : B_XORs.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cstdio>
#include <unordered_map>
using namespace std;

double arithmeticProgressionSum(double a1, double an, unsigned n) {
    return n * (a1 + an) / 2;
}

int main() {
    unsigned n, x;
    scanf("%u %u\n", &n, &x);

    unordered_map<unsigned, unsigned> pool;
    while (n--) {
        unsigned a;
        scanf("%u", &a);
        pool[a]++;
    }

    unsigned long long sum = 0;
    while (pool.size()) {
        unordered_map<unsigned, unsigned>::iterator elemIt = pool.begin();
        unsigned elemCount = elemIt->second;
        if (!x) {
            if (elemCount > 1) {
                elemCount--;
                sum += arithmeticProgressionSum(1, elemCount, elemCount);
            }
        } else {
            unsigned elem2 = x ^ elemIt->first;
            unordered_map<unsigned, unsigned>::iterator elem2It = pool.find(
                    elem2);
            if (elem2It != pool.end()) {
                sum += elemCount * elem2It->second;
                pool.erase(elem2It);
            }
        }
        pool.erase(elemIt);
    }

    printf("%llu", sum);

    return 0;
}
