#include <stdio.h>
#include <stdbool.h>


int IsSeparator(char c) {
    return (c == ' ') || (c == ',') || (c == '\n') || (c == EOF) || (c == '\t');
}

long long Abs(long long x) {
    if (x < 0) {
        return -x;
    }
    return x;
}

long long Length(long long n) {
    long long r = 0;
    while(n > 0) {
        r++;
        n /= 10;
    }
    return r - 1;
}

long long Iter(long long x) {
    long long res = 1;
    while(x >= 1) {
        res *= 10;
        x -= 1;
    }
    return res;
}


int main() {
    while(1) {
        long long number;
        scanf("%lld", &number);
        number = Abs(number);
        long long discharge = Length(number);
        long long iterator = Iter(discharge);
        long long res = 0;
        while(discharge > 0) {
            if(discharge % 2 != 0){
                res *= 10;
                res += (number / iterator) % 10;
            }
            discharge--;
            iterator /= 10;
        }
        if(res != 0) {
            printf("%lld", res);
        }
        
        int c = getchar();
        if (c == EOF) {
            break;
        }
    }

    return 0;
}