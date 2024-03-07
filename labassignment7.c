#include <stdio.h>

#define SIZE1 9
#define SIZE2 9

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n, int swapCount[]) {
    int i, j;
    for (i = 0; i < n-1; i++)        
        for (j = 0; j < n-i-1; j++)  
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
                swapCount[arr[j+1]]++;
            }
}

void selectionSort(int arr[], int n, int swapCount[]) {
    int i, j, min_idx;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
        swap(&arr[min_idx], &arr[i]);
        if(min_idx != i) { 
            swapCount[arr[i]]++;
        }
    }
}

void printSwapCounts(int arr[], int n, int swapCount[]) {
    for(int i = 0; i < n; i++) {
        printf("%d: is swapped %d times.\n", arr[i], swapCount[arr[i]]);
    }
}

int main() {
    int barray1[SIZE1] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int sarray1[SIZE1] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int barray2[SIZE2] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int sarray2[SIZE2] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int bswapCount1[101] = {0};
    int bswapCount2[101] = {0};
    int sswapCount1[101] = {0};
    int sswapCount2[101] = {0};
    int btotalSwaps1 = 0, btotalSwaps2 = 0;
    int stotalSwaps1 = 0, stotalSwaps2 = 0;


    bubbleSort(barray1, SIZE1, bswapCount1);
    bubbleSort(barray2, SIZE2, bswapCount2);
    
    selectionSort(sarray1, SIZE1, sswapCount1);
    selectionSort(sarray2, SIZE2, sswapCount2);


    printf("array1 (Bubble):\n");
    printSwapCounts(barray1, SIZE1, bswapCount1);
    for(int i = 0; i < 101; i++) btotalSwaps1 += bswapCount1[i];
    printf("Total # of swaps: %d\n\n", btotalSwaps1/2);

    printf("array1 (Select):\n");
    printSwapCounts(sarray1, SIZE1, sswapCount1);
    for(int i = 0; i < 101; i++) stotalSwaps1 += sswapCount1[i];
    printf("Total # of swaps: %d\n\n", stotalSwaps1/2);

    printf("array2 (Bubble):\n");
    printSwapCounts(barray2, SIZE2, bswapCount2);
    for(int i = 0; i < 101; i++) btotalSwaps2 += bswapCount2[i];
    printf("Total # of swaps: %d\n", btotalSwaps2/2);

    printf("array2 (Select):\n");
    printSwapCounts(sarray2, SIZE2, sswapCount2);
    for(int i = 0; i < 101; i++) stotalSwaps2 += sswapCount2[i];
    printf("Total # of swaps: %d\n", stotalSwaps2/2);

    return 0;
}
