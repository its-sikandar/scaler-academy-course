/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */

 int maximum(int *A, int n1) {
     int idx;
     int max = A[0];
     for ( idx = 1; idx < n1; idx++) {
         if (A[idx] > max) {
             max = A[idx];
         }

     }

     return max;
 }
int solve(int* A, int n1) {

    int max = maximum(A, n1);
    int idx, time;

    for (idx = 0; idx < n1; idx++) {
        time += (max - A[idx]) ;
    }


    return time;

}