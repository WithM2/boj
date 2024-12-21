#include <stdio.h>

int main()
{
    int n, max = 0;
    double sum = 0;
    double arr[1000];
    char trash;
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &arr[i]);
        if (max < arr[i]) max = arr[i];
        if (i != n-1) scanf("%c", &trash);
    }
    
    for (int i = 0; i < n; i++) {
        arr[i] = (arr[i]/max)*100;
        sum += arr[i];
    }
    
    double avg = (double)sum/n;
    
    printf("%f", avg);
    
    return 0;
}