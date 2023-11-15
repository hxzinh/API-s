#include<stdio.h>
#include<string.h>

void* memset( void* obj, int val, size_t num);
/*
+ obj: con trỏ trỏ đến địa chỉ ô nhớ bắt đầu
+ val: giá trị cần set với mỗi block
+ num: số byte cần set
*/

//Ta có thể hiểu đơn giản hàm hoạt động như sau:
void *Memset(void *s, int c, size_t n) {
    unsigned char *p = s;  
    while (n-- > 0) {
        *p++ = (unsigned char)c;  // set giá trị cho byte hiện tại và nhảy đến byte kế tiếp
        //printf("%x ", p);
    }
    return s;  
}

int main() {
    int a[100];
    memset(a, 0x3f, sizeof(a));

    int len = sizeof(a);
    printf("%d \n", len);
    for(int i = 1; i <= 100; i++) printf("%x ", a[i]);
    /*
    a[0] = 0x3f3f3f3f
    a[1] = 0x3f3f3f3f
    .
    .
    a[100] = 0x3f3f3f3f
    */
    
    return 0;
} 
