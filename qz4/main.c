#include <stdio.h>
#include <stdlib.h>

void swap_func(int* i, int* j) {
    int tmp;
    tmp = *i;
    *i = *j;
    *j = tmp;
    printf("after swap, n = %d, m = %d\n", *i, *j);
}

void swapArray(int* source, int* dest, int size) {
    for(int i=0; i<size; i++) {
        int tmp;
        tmp = *(source+i);
        *(source+i) = *(dest+i);
        *(dest+i) = tmp;
    }
}

int printArray(int* array, int size) {
    for(int i=0; i<size; i++) {
        if(i == (size-1)) {
            printf("%d]\n", *(array+i));
            break;
        }
        printf("%d, ", *(array+i));
    }
}



int main() {
    int n, m;
    n = 1; 
    m = 2;
    int size = 10;
    int source[10] = {0, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int dest[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    char str[] = "IU!IU!IU!IU!";
    char* cp_str = copy_string(str);
    printf("No.1 -------------------\n");
    swap_func(&n, &m);
    printf("No.2 -------------------\n");
    swapArray(source, dest, size);
    printf("after swap array, source array = [");
    printArray(source, size);
    printf("after swap array, dest array = [");
    printArray(dest, size);
    printf("No.3 -------------------\n");
    char* cp_str = copy_string(str);
    
    return 0;
}
