/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Integer
 * 
 * @Output Integer
 */
int solve(int* A, int n1, int B) {

    int max, idx;

    max = 0;

    for (idx = 0; idx < n1; idx++) {
        if (B == A[idx]) {
            max += 1;
        }
    }
    return max;
}
