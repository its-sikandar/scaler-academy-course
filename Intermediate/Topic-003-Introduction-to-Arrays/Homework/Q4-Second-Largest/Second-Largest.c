/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */

 int second_max(int *A, int n1) {

     if (n1 < 2) {
         return -1;
     }

     int idx;
     int max = INT_MIN;
     int next_max = INT_MIN;
     int found = 0 ;

     for (idx = 0; idx < n1; idx++) {
         if (A[idx] > max) {
            next_max = max;
             max = A[idx];
            
         } else if (A[idx] < max && A[idx] > next_max ) {
             next_max = A[idx];
         }
     }

    if ((next_max == INT_MIN)) {
        return -1;
    }
    return next_max;
 }
int solve(int* A, int n1) {

    int ret = second_max(A, n1);

    return ret;


}
