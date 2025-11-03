/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */

 int maximum(int *A, int n1) {
     int max, idx;
     max = A[0];
     for (idx = 1; idx < n1; idx++) {
         if (A[idx] > max) {
             max = A[idx];
         }
     }
    return max;

 }
int solve(int* A, int n1) {

    int max = maximum(A, n1);
    int idx, count;
    for (idx = 0; idx < n1; idx++) {
        if (A[idx] < max) {
            count += 1;
        }
    }

    return count;
}