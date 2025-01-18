#include <iostream>
#include <vector>
using namespace std;

char map[51][51];

int color(int x, int y) {
    int w = 0, b = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if((i+j)%2) {
                if(map[x+i][y+j]=='W') {
                    w++;
                }
                else b++;
            }
            else {
                if (map[x+i][y+j]=='B') {
                    w++;
                }
                else b++;
            }
        }
    }
    return (w<b)?w:b;
}

int main() {
    
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", map[i]);
    }
    
    int min = 64;
    
    for (int i = 0; i < n-7; i++) {
        for (int j = 0; j < m-7; j++) {
            int tmp = color(i, j);
            if (min > tmp) {
                min = tmp;
            }
        }
    }
    
    printf("%d", min);
    
    return 0;
}