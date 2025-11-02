/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */
int solve(int* A, int n1) {


    int min = A[0];
    int max = A[0];
    int i;
    for (i = 1; i < n1; i++) {
        if (A[i] < min) {
            min = A[i];
        }
        if (A[i] > max) {
            max = A[i];
        }
    }

    int total = min + max;
    return total;


}
