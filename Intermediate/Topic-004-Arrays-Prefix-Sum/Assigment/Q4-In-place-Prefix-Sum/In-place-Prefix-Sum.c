int* solve(int* A, int n1, int *len1) {
    int i;
    for ( i = 1; i < n1; i++) {
        A[i] = A[i - 1] + A[i];
    }

    *len1 = n1;
    return A;   // return the same modified array
}