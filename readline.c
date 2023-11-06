#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int main() {
        char filename[] = "input.txt";
        FILE *file = fopen(filename, "r");

        char *line;
        line = (char*)malloc((int)128 * sizeof(char));
        while(fgets(line, sizeof line, file) != NULL) {
                printf("%s", line);
        }

        int len = sizeof(line);
        printf("%d", len);
        return 0;
}
