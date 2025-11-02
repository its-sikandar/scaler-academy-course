/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Integer
 * 
 * @Output Integer array. You need to malloc memory, and fill the length in len1
 */
#include <stdio.h>
#include <stdlib.h>

 int *reverse(int *arr, int i, int j) {
    int temp;


    while (i < j) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;

        i += 1;
        j -= 1;
    }

    return arr;
}


int* solve(int* A, int n1, int B, int *len1) {

    *len1 = n1;

    // Allocate the memory

    int *result = (int *)malloc(n1 * sizeof(int));
    int k;
    for (k = 0; k < n1; k++) {
        result[k] = A[k];
    }

    if (n1 <= 1) {
        return result;
    }

    // Note: Handle case where B > n1
    if ((B = B % n1) == 0) {
        return result;
    }

    // Efficient way,
    // 1. Reverse the whole array
    // 2. Reverse the first k element
    // 3. Reverse the N - K element
    // 4. Return result

    // 1. Reverse the whole array 

   
     // Reverse entire array
    result = reverse(result, 0 , n1 - 1);
     // Reverse first B elements
    result = reverse(result, 0 , B - 1);
    // Reverse remaining elements
    result = reverse(result, B , n1 - 1); 

    return result;
}


// Runner code


int main() {
    int A[] = {1, 2, 3, 4, 5};
    int n1 = 5;
    int B = 2;
    int len1;
    int *result = solve(A, n1, B, &len1);
    printf("Rotated array: ");
    for (int i = 0; i < len1; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    free(result);
    return 0;
}
