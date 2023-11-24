#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* strncpy(char *restrict destination, char *restrict source, size_t n) {
    size_t size = __strnlen(source, n);
    /*
    - Hàm strnlen trả về số bytes của *source kể cả '\0' nhưng max là n bytes
    */
    if (size != n) memset (destination + size, '\0', n - size);
    return memcpy (destination, source, size);
}
/*
- destination: con trỏ tới địa chỉ được copy tới
- sources: con trỏ tới địa chỉ của ký tự đầu tiên của xâu được copy
- n: số ký tự được copy từ sources đến destination

- Hàm sẽ kiểm tra xem kích thước hai xâu có bằng nhau không:
    + n > size src: copy như bình thường và fill những bytes lớn hơn size bằng '\0'
    + n <= size src: copy như bình thường (gọi hàm memcpy)
    --> Hàm strncpy copy n bytes mà không check size của dest --> có thể ghi tràn ra địa chỉ khác
*/

int main() {
    return 0;
}
