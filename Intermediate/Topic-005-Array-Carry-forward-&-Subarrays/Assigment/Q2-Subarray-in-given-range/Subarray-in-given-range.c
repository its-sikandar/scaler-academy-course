/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Integer
 * @input C : Integer
 * 
 * @Output Integer array. You need to malloc memory, and fill the length in len1
 */
int* solve(int* A, int n1, int B, int C, int *len1) {

    *len1 =(C - B + 1);
    int *result_array = (int *) malloc(*len1 * sizeof(A));


    int idx = 0;
    int j;

    for (idx = 0, j = B; idx <= *len1; idx++, j++ ) {
        result_array[idx] = A[j];
    }

 

    return result_array;
}
