#include <cstdio>
//#include <vector>
#include <climits>
#include <cstdlib>

using namespace std;

#define FIBS_CNT 30

unsigned long long EVEN_FIBS[] = { 2, 8, 34, 144, 610, 2584, 10946, 46368,
        196418, 832040, 3524578, 14930352, 63245986, 267914296, 1134903170,
        4807526976, 20365011074, 86267571272, 365435296162, 1548008755920,
        6557470319842, 27777890035288, 117669030460994, 498454011879264,
        2111485077978050, 8944394323791464, 37889062373143906,
        160500643816367088, 679891637638612258, 2880067194370816120 };

unsigned long long FIBS_SUMS[] = { 2, 10, 44, 188, 798, 3382, 14328, 60696,
        257114, 1089154, 4613732, 19544084, 82790070, 350704366, 1485607536,
        6293134512, 26658145586, 112925716858, 478361013020, 2026369768940,
        8583840088782, 36361730124070, 154030760585064, 652484772464328,
        2763969850442378, 11708364174233842, 49597426547377748,
        210098070363744836, 889989708002357094, 3770056902373173214 };

unsigned char find(unsigned long long n, unsigned char startIX,
        unsigned char size);

int main() {
//    unsigned T;
//    scanf("%u\n", &T);
//
//    while (T--) {
//        unsigned long long N;
//        scanf("%llu", &N);
//
//        unsigned char ix = find(N, 0, FIBS_CNT);
//        printf("%llu\n", FIBS_SUMS[ix]);
//    }

    for (unsigned i = 0; i < 100000; i++) {
        unsigned long long N = (((unsigned long long) rand()) * rand())
                % 40000000000000001;
        unsigned char ix = find(N, 0, FIBS_CNT);
        printf("%llu -> %llu\n", N, FIBS_SUMS[ix]);
    }
}

unsigned char find(unsigned long long n, unsigned char startIX,
        unsigned char size) {
    if (size <= 2) {
        return startIX;
    }

    unsigned char halfSize = size >> 1;
    unsigned char centerIX = startIX + halfSize;
    if (EVEN_FIBS[centerIX] == n) {
        return centerIX;
    } else if (n < EVEN_FIBS[centerIX]) {
        if (EVEN_FIBS[centerIX - 1] <= n) {
            return centerIX - 1;
        } else {
            return find(n, startIX, halfSize);
        }
    } else {
        if (n < EVEN_FIBS[centerIX + 1]) {
            return centerIX;
        } else {
            centerIX++;
            return find(n, centerIX, size - centerIX);
        }

    }
}

/*
 int main() {
 unsigned long long n1 = 1;
 unsigned long long n2 = 2;
 unsigned long long currSum = 0;
 vector<unsigned long long> sums;
 for (unsigned char i = 0; i < FIBS_CNT; i++) {
 printf("%llu ", n2);
 currSum += n2;
 sums.push_back(currSum);

 n1 += n2;
 n2 += n1;
 n1 += n2;
 swap(n1, n2);
 }
 printf("\n");
 for (unsigned long long& sum : sums) {
 printf("%llu ", sum);
 }

 }
 */
