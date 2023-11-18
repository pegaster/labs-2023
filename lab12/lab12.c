#include <stdbool.h>
#include <stdio.h>

int NumLen(int x) {
    int counter = 0;
    while (x > 0) {
        x = x / 10;
        counter++;
    }
    return counter;
}

int main() {
    int a;
    scanf("%d", &a);
    int length = NumLen(a);
    int middle = length / 2;
    int ans = 0;
    int power = 1;
    for (int i = 0; i < length; i++) {
        if (i != middle) {
            ans += (a % 10) * power;
            power = power * 10;
        }
        a = a / 10;
    }
    printf("%d\n", ans);
}
