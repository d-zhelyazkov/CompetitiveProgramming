#include <cstdio>
#include <unordered_map>

using namespace std;

#define MAX_WORD_LENGTH 6

char WORD[MAX_WORD_LENGTH];

int main() {
    unsigned short m, n;
    scanf("%hu %hu\n", &m, &n);
    if (m < n) {
        printf("No");
        return 0;
    }

    unordered_map<string, unsigned short> availableWords;

    for (unsigned short magazine_i = 0; magazine_i < m; magazine_i++) {
        scanf("%s", WORD);
        string word = WORD;
        //cin >> word;
        availableWords[word]++;
        //printf("Mag %s %hu\n", word.c_str(), availableWords[word]);
    }

    for (unsigned short ransom_i = 0; ransom_i < n; ransom_i++) {
        scanf("%s", WORD);
        string word = WORD;
        //cin >> word;
        //printf("Ransm %s %hu\n", word.c_str(), availableWords[word]);
        if (!(availableWords[word]--)) {
            printf("No");
            return 0;
        }
    }

    printf("Yes");
    return 0;
}
