#include <stdio.h>

int IsSep(int s) {
    return ((s == ' ') || (s == ',') || (s == '\t') || (s == '\n')) || (s == EOF);
}

int WordCounter(void) {
    int a = getchar(), b = getchar(), inWord = 0, ans = 0;
    while (a != '*' || b != '/') {
        if (b == EOF) {
            return 0;
        } else if (IsSep(a) == 0) {
            inWord = 1;
        } else if (inWord == 1) {
            ans += 1;
            inWord = 0;
        }
        a = b;
        b = getchar();
    }
    if (inWord == 1) {
        ans += 1;
    }
    return ans;
}

int main(void) {
    int totalAnswer = 0;
    while (1) {
        int symbol = getchar();
        if (symbol == EOF) {
            break;
        }
        if (symbol == '/' && getchar() == '*') {
            totalAnswer += WordCounter();
        }

    }
    printf("%d\n", totalAnswer);
    return 0;
}
