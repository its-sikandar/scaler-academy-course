class Solution:
    # @param A : list of integers
    # @param B : list of list of integers
     # @return an list of long
    def rangeSum(self, A, B):
        # Create an array p to store the prefix sum array
        p = [0] * len(A)

        p[0] = A[0]

        # create prefix sum array
        for i in range(1, len(A)):
            p[i] = p[i -1] + A [i]

        
        # Query the Answer
        sum = [0] * len(B)
        for i in range(len(B)):
            l = B[i][0] 
            r = B[i][1]

            if  l == 0 :
                sum[i] = p[r]
            else :
                 sum [i] = p[r] - p[l -1]
        return sum

