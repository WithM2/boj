#include <stdio.h>

#define MAX_SIZE 1000001 // 최대 배열 크기

int A[MAX_SIZE];  // 배열 (힙으로 사용할 배열)
int n = 0;        // 현재 배열에 저장된 키 개수 (입력받은 키 개수)

// 배열을 차례대로 출력하는 함수
void printArray() {
    for (int i = 0; i < n; i++) {
        printf("%d\n", A[i]);//네모가 띄어쓰기?
    }
    
}

// 하향 이동 (Down-Heap)
void downHeap(int i, int heapSize) {
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;
    int largest = i;

    // 왼쪽 자식이 있고, 자식이 부모보다 크면
    if (leftChild < heapSize && A[leftChild] > A[largest]) {
        largest = leftChild;
    }

    // 오른쪽 자식이 있고, 자식이 부모보다 크면
    if (rightChild < heapSize && A[rightChild] > A[largest]) {
        largest = rightChild;
    }

    // 가장 큰 자식과 부모를 교환하고, 하위 노드에 대해 다시 적용
    if (largest != i) {
        int temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;
        downHeap(largest, heapSize);  // 재귀적으로 하향 이동
    }
}

// 힙을 구성하는 함수 (상향식 힙 생성)
void buildHeap() {
    for (int i = n / 2 - 1; i >= 0; i--) {
        downHeap(i, n);
    }
}

// 힙 정렬 함수
void inPlaceHeapSort() {
    buildHeap();  // 힙을 먼저 구성

    for (int i = n - 1; i > 0; i--) {
        // 루트와 마지막 요소를 교환
        int temp = A[0];
        A[0] = A[i];
        A[i] = temp;

        // 교환 후 힙 크기를 줄이고 downHeap 수행
        downHeap(0, i);  // 힙 크기는 i로 줄이고 downHeap 호출
    }
}

int main() {
    // 첫 번째 라인: 키 개수 입력
    scanf("%d", &n);

    // 두 번째 라인: 키들 입력
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    // 힙 정렬 수행
    inPlaceHeapSort();

    // 정렬된 결과 출력
    printArray();

    return 0;
}
