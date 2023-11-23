#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void* malloc(size_t size);
/*
- size: kích thước mà hàm malloc cấp phát (bytes)
- hàm malloc sẽ trả về địa chỉ đầu tiên của vùng được cấp phát hàm thực thi nếu thành công
  ngược lại trả về NULL
- vùng nhớ được cấp phát sẽ ở trong Heap stack
- vùng nhớ được cấp phát bởi hàm malloc() là cấp phát động nên cần được giải phóng bằng hàm free()
*/ 

int main() {
    int *arr = (int*)malloc(128 * sizeof(int));
    memset(arr, 0x3f, 128);
    for(int i = 1; i <= 12; i++) printf("%d\n", arr[i]);
    return 0;
}
