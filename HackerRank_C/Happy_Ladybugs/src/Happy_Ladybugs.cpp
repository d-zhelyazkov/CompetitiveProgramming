#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ALPHA_CHARS 26

bool check(char* b, unsigned char n);

int main() {
    int Q;
    scanf("%d", &Q);
    for (int a0 = 0; a0 < Q; a0++) {
        int n;
        scanf("%d", &n);
        char* b = (char *) malloc((n + 1) * sizeof(char));
        scanf("%s", b);

        printf("%s\n", (check(b, n)) ? "YES" : "NO");
    }
    return 0;
}

bool check(char* b, unsigned char n) {

    unsigned char occurances[ALPHA_CHARS] = { 0 };

    unsigned char unhappyBugs = 0;
    unsigned char spaces = 0;
    for (unsigned char i = 0; i < n; i++) {
        switch (b[i]) {
        case '_':
            spaces++;
            break;
        default:
            occurances[b[i] - 'A']++;
            if (!(((0 < i) && (b[i - 1] == b[i]))
                    || (((i + 1) < n) && (b[i + 1] == b[i]))))
                unhappyBugs++;
        }
    }

    if (!unhappyBugs)
        return true;

    if (!spaces)
        return false;

    for (unsigned char i = 0; i < ALPHA_CHARS; i++)
        if (occurances[i] == 1)
            return false;

    return true;
}
