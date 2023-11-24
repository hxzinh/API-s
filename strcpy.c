#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* strcpy (char *dest, const char *src) {
  	return memcpy (dest, src, strlen (src) + 1);
}
/*
- dest: con trỏ tới địa chỉ đích
- src: con trỏ tới địa chỉ nguồn
- Hàm strcpy sẽ gọi hàm memcpy để copy n bytes = size của src vào dest
- Hàm sẽ copy lần lượt từng ký tự và có check NULL byte 

- Hàm strcpy không check size của hai thằng mà cứ thế copy vào -> Buffer Overflow
*/

int main() {
    char* src = "This_is_flag";
    char* dest;
    dest = (char*)malloc(strlen(src));
    strcpy(dest, src);
    printf("%s", dest);
    return 0;
}
