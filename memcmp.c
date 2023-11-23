#include <stdio.h>
#include <string.h>

int memcmp(const void *str1, const void *str2, size_t n);
/*
- str1: Con trỏ trỏ tới địa chỉ đầu tiên
- str2: Con trỏ trỏ tới địa chỉ thứ hai
- n: Số bytes được so sánh

- Hàm memcmp sẽ kiểm tra lần lượt từng block bytes  
- Khi thực thi hàm trả về:
    + 0: n block bằng nhau
    + -1: nếu block đầu tiên khác str1 < str2
    + 1: nếu block đầu tiêm khác str1 > str2
- Block ở đây sẽ có độ lớn tùy vào kiểu dữ liệu (char: 1 byte; int: 4 bytes; ...)
*/

int main() {
    char *str1 = "This_is_str2";
    char *str2 = "This_is_str2";
    int diff = memcmp(str1, str2, strlen(str1));
    printf("%d", diff);
    return 0;
}
