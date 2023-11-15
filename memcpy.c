#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void *memcpy(void *to, const void *from, size_t numBytes);
/**
- void *to: con trỏ trỏ tới địa chỉ đích nơi mà dât sẽ được copy tới.
- const void *from: con trỏ trỏ tới địa chỉ nguồn
- size_t numBytes: số byte được copy

Express: 
- Hàm memcpy copy numBytes liên tiếp từ địa chỉ nguồn đến địa chỉ đích
- Hàm memcpy thực hiện việc copy numBytes mà không kiểm tra thêm điều kiện nào 
    --> Hàm sẽ copy đủ numBytes 
    --> Nếu memory địa chỉ đích không đủ lớn có thể dẫn đến Buffer Overflow 
**/

int main() {
    char *a = "This is memcpy";
    char *s;

    s = (char*)malloc((2) * sizeof(char));
    int len = strlen(a);

    //This lead to Buffer Overflow
    memcpy(s, a, strlen(a));
    printf("%d %s", len, s);
    return 0;
}
