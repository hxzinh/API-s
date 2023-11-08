#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>

const int SIZE = 20000;
int *a;

void get_sum() {
        char filename[] = "input.txt";
        char *a, *b;
        FILE *file = fopen(filename, "r");

        if(file == NULL) {
                printf("Error!");
                return;
        }

        a = calloc(SIZE, sizeof(int));

        char *line;
        line = (char*)malloc(SIZE * sizeof(char));
        while(fgets(line, SIZE * sizeof(char), file) != NULL) {
                int len = strlen(line) - 1, carry = 0;
                for(int i = 0; i < len; i++) {
                        int u = a[SIZE - i - 1] + (int)(line[len - i - 1] - '0') + carry;

                        if(u > 10) {
                                carry = 1;
                                u -= 10;
                        }
                        else 
                                carry = 0;

                        a[SIZE - i - 1] = u;
                }

                int curId = len;
                while(carry > 0) {
                        int u = a[SIZE - curId - 1] + carry;
                        if(u > 10) {
                                carry = 1;
                                u -= 10;
                        }
                                carry = 0;

                        a[SIZE - curId - 1] = u;
                        curId++;
                }

        }
        free(line);

        bool ok = false;
        for(int i = 0; i < SIZE; i++) {
                if(a[i] != 0) ok = true;
                if(ok) printf("%d", a[i]);
        }

        free(a);

        return;
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

                get_sum();
                break;
        }

        //Em van dang bi bug

        return 0;
}
