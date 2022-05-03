#include <stdio.h>

int _sum(int x, int y) {
    return x+y;    
}

int _sub(int x, int y) {
    return x-y;
}

int _mult(int x, int y) {
    return x*y;
}

int _div(int x, int y) {
    if(y == 0) return 0;
    else return x/y;
}

int _power(int x, int y) {
    int power = 1;
    if(y==0) return power;
    while(y) {
        power *= x;
        y--;
    } return power;
}

int main() {
    int x, y, choice;
    int (*ope[4])(int, int);
    ope[0] = _sum;
    ope[1] = _sub;
    ope[2] = _mult;
    ope[3] = _div;
    ope[4] = _power;
    
    printf("Enter two integer： ");
    scanf("%d%d", &x, &y);
    
    printf("Enter 0 to +, 1 to -, 2 to *, 3 to /, or 4 to ^：");
    scanf("%d", &choice);
    
    printf("%d", ope[choice](x, y));
    
    return 0;
}
