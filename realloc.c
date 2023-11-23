#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void *realloc(void *ptr, size_t size);
/*
- ptr: là con trỏ trỏ tới địa chỉ của vùng nhớ đã được cấp phát trước đó bởi malloc()/calloc() cần được phân bổ lại
    + nếu *ptr là NULL thì realloc sẽ cấp phát vùng nhớ mới
- size: số bytes mà vùng nhớ cần được resize lại
- Hàm realloc() sẽ trả về: + địa chỉ của vùng nhớ mới nếu thực thi thành công
                           + NULL nếu thất bại
- realloc chỉ được dùng cho vùng nhớ được cấp phát động
*/


int main() {
    int *arr = (int*)malloc(sizeof(int));
    arr[0] = 0;
    arr = realloc(arr, 3 * sizeof(int));
    arr[1] = 1; arr[2] = 2;
    for(int i = 0; i < 3; i++) printf("%d ", arr[i]);
    return 0;
}
