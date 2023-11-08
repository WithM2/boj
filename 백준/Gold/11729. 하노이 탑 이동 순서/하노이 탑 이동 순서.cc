#include <iostream>
#include <vector>
using namespace std;

void move(int n, int a, int b, int c) {
    if (n==2) {
        printf("%d %d\n", a, c);
    }
    else {
        move(n-1, a, c, b);
        printf("%d %d\n", a, c);
        move(n-1, b, a, c);
    }
}

void hanoi(int n, int a, int b, int c) {
    move(n, a, c, b);
    printf("%d %d\n", a, c);
    move(n, b, a, c);
}

int main() {
    int n;
    scanf("%d", &n);
    int sum = 0;
    int tmp = 0;
    for (int i = 0; i < n; i++) {
        tmp = 2*tmp + 1;
        sum = tmp;
    }
    printf("%d\n", sum);
    if(n==1) {
        printf("1 3");
        return 0;
    }
    hanoi(n, 1, 2, 3);
    
    return 0;
}