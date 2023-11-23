#include <stdio.h>
#include <string.h>

void * memmove(void *to, const void *from, size_t numBytes);
/*
- *to: con trỏ trỏ tới địa chỉ đích
- *from: con trỏ trỏ tới địa chỉ nguồn
- numBytes: số bytes được move

- Hàm memmove sẽ copy từng bytes theo cách copy từ *to -> *trung gian -> *from
 --> Vẫn sẽ copy được nếu hai địa chỉ *from và *to đè lên nhau
*/

int main() 
{ 
    char str[100] = "ExampleForMemmove"; 
    char *first, *second; 
    first = str; 
    second = str; 
    printf("Original string :%s\n", str); 
      
    memcpy(first + 8, first, 10); 
    printf("memcpy overlap : %s\n", str); 
  
    memmove(second + 8, first, 10); 
    printf("memmove overlap : %s\n", str); 
  
    return 0; 
}
