#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void calc_sum() {
        long long a, b;
        scanf("%lld %lld", &a, &b);
        long long sum = a + b;

        printf("%lld\n", sum);
}

void calc_sub() {
        long long a, b;
        scanf("%lld %lld", &a, &b);
        long long sub = a - b;

        printf("%lld\n", sub);
}

void calc_mul() {
        int a, b;
        scanf("%d %d", &a, &b);
        long long res = 1LL * a * b;

        printf("%lld\n", res);
}

void calc_div() {
        double a, b;
        scanf("%a %a", &a, &b);

        double res = a / b;
        printf("%a\n", res);
}

int main() {
        printf("1) Sum of 2 numbers \n");
        printf("2) Subtract of 2 numbers \n");
        printf("3) Multiple of 2 numbers \n");
        printf("4) Divide of 2 numbers \n");

        int t = -1, cnt = 0;
        while(true) {
                printf("Choose one option: ");
                scanf("%d", &t);
                if(t < 1 || t > 4) {
                        printf("Invalid input. \n");
                        if(++cnt == 4) return 0;
                }

                if(t == 1) calc_sum();
                if(t == 2) calc_sub();
                if(t == 3) calc_mul();
                if(t == 4) calc_div();

                char ok;
                printf("Continue? Insert [Y/N] ");
                scanf("%c", &ok);
                if(ok != 'Y'&& ok != 'y') break;
        }

        //Em dang bi bug

        return 0;
}
