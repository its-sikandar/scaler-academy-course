/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : 2D integer array 
 * @input n21 : Integer array's ( B ) rows
 * @input n22 : Integer array's ( B ) columns
 * 
 * @Output Long Array. You need to malloc memory, and fill the length in len1
 */
long long* rangeSum(int* A, int n1, int** B, int n21, int n22, int *len1) {

    // Create a prefix sum array

    long long *prefix = (long long *) malloc ( n1 * sizeof( long long));

    // update the prefix sum array

    prefix[0] = A[0];
    int i;
    for (i = 1; i < n1; i++) {
        prefix[i] = prefix[i - 1] + A[i];
    }

       // Create a result array

    long long *result = (long long *) malloc(n21 * sizeof(long long));

    //    answer the query
    for (i = 0; i < n21; i++) {
        int l = B[i][0];
        int r = B[i][1];

        if ( l == 0 ) {
            result[i] = prefix[r];
        } else {
            result[i] = prefix[r] - prefix[l - 1];
        }
    }
    //  Set length
    *len1 = n21;
    return result;
}
