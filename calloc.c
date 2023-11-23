#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void *calloc (size_t number_of_block, size_t size_of_block);
/*
- number_of_block: số block bộ nhớ được cấp phát
- size_of_block: số bytes của mỗi block
- It's quite similar to the malloc() func
- Hàm calloc khi thực thi + thành công trả con trỏ trỏ tới địa chỉ bắt đầu của vùng nhớ vừa được cấp phát
                          + fails sẽ trả về NULL
- mỗi block được khởi tạo sẽ được gán giá trị '0'
*/

int main() {
    int *arr = (int*)calloc(128, sizeof(int));
    for(int i = 1; i <= 128; i++) printf("%d ", arr[i]);
    return 0; 
}
