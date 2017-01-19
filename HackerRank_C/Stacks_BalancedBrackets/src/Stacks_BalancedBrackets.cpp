//============================================================================
// Name        : Stacks_BalancedBrackets.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cstdio>
#include <string>
#include <iostream>
#include <stack>
using namespace std;

#define LINE_MAX_LEN 1001

string LINE;

bool check();

int main() {

    unsigned short n;
    scanf("%hu\n", &n);
    while (n--) {
        cin >> LINE;

        if (check()) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }

    }

    return 0;
}

bool check() {
    if (LINE.length() & 1) {
        return false;
    }

    stack<char> bracketStack;

    for (char& c : LINE) {
        char toCheck = 0;
        switch (c) {
        case '(':
        case '[':
        case '{':
            bracketStack.push(c);
            break;
        case ')':
            toCheck = '(';
            break;
        case ']':
            toCheck = '[';
            break;
        case '}':
            toCheck = '{';
            break;
        }
        if (toCheck) {
            if (bracketStack.empty() || (toCheck != bracketStack.top())) {
                return false;
            }
            bracketStack.pop();
        }

    }

    return bracketStack.empty();
}
