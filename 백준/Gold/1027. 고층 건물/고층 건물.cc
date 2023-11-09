#include <iostream>
#include <vector>
using namespace std;

int n;

int left(int* h, int k) {
    if (k<2) return k;
    double slope = h[k]-h[k-1];
    int cnt = 1;
    for (int i = k-2; i >= 0; i--) {
        if ((double)(h[k]-h[i])/(k-i) < slope) {
            cnt++;
            slope = (double)(h[k]-h[i])/(k-i);
        }
    }
    return cnt;
}

int right(int* h, int k) {
    if (n-k < 3) return n-k-1;
    double slope = h[k+1]-h[k];
    int cnt = 1;
    for (int i = k+2; i < n; i++) {
        if ((double)(h[i]-h[k])/(i-k) > slope) {
            cnt++;
            slope = (double)(h[i]-h[k])/(i-k);
        }
    }
    return cnt;
}

int main() {
    int tower[50];
    int max = 0;
    char trash;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &tower[i]);
        if (i!=n-1) scanf("%c", &trash);
    }
    if (n<3) {
        printf("%d", n-1);
        return 0;
    }
    for (int i = 0; i < n; i++) {
        int tmp = left(tower, i) + right(tower, i);
        if (tmp > max) {
            max = tmp;
        }
    }
    printf("%d", max);
    return 0;
}