#include <stdio.h>

/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Integer
 * @input C : Integer
 * 
 * @Output Integer array. You need to malloc memory, and fill the length in len1
 */
int* solve(int* A, int n1, int B, int C, int *len1) {


    *len1 = n1;
    int k;

    // Allocate the new array
    int *result = (int *)malloc(n1 * sizeof(int));
    for ( k =0; k < n1 ; k++) {
        result[k] = A[k];
    }

    // Validate indices
    if ( B < 0 || C > n1 || B >= C) {
        return result;
    }
    int i = B;
    int j = C;

// Reverse the subarray [B, C-1]
    while (i < j) {
        result[i] = result[i] + result[j];
        result[j] = result[i] - result[j];
        result[i] = result[i] - result[j];

        i += 1;
        j -= 1;
    }

    return result;
}


// Runner code
int main() {
    int A[] = {1, 2, 3, 4, 5};
    int n1 = 5;
    int B = 2;  
    int C = 4;
    int len1;
    int *result = solve(A, n1, B, C, &len1);
    printf("Reversed subarray: ");
    for (int i = 0; i < len1; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    free(result);
    return 0;
}