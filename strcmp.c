#include <stdio.h>
#include <string.h>

int strcmp(const char *str1, const char *str2);
/*
- str1: con trỏ đến string đầu tiên cần so sánh
- str2: con trỏ đến string thứ hai cần so sánh

- Hàm strcmp sẽ so sánh lần lượt các ký tự từ trái qua phải và trả về:
    + 0: nếu 2 xâu bằng nhau
    + giá trị âm (str1[i] - str2[i]) : nếu ký tự đầu khác nhau sâu 1 có thự tự từ điển NHỎ hơn ở sâu 2
    + giá trị dương (str1[i] - str2[i]): nếu ký tự đầu khác nhau sâu 1 có thự tự từ điển LỚN hơn ở sâu 2
*/

int main() {
    char *str1 = "hx\0zinh";
    char *str2 = "hxz1nh";
    int a = strcmp(str1, str2);
    printf("%d", a);
    return 0;
}
