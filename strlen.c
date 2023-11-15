#include<stdio.h>
#include<string.h>

size_t strlen(const char *str);
/*
+ Hàm truyền vào string và trả về độ dài của string
+ Hàm str len sẽ duyệt từng char:
    - Nếu là '\0' thì trả về độ dài hiện tại
    - Nếu khác '\0' thì tăng độ dài và tiếp tục duyệt
*/

int main() {
    char *str = "This is\0 a string";
    int len = strlen(str);
    printf("%d", len);
    //Output: 7
    return 0;
}
