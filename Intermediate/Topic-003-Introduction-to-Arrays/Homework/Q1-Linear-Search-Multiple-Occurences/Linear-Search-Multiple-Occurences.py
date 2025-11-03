class Solution:
    # @param A : list of integers
    # @param B : integer
    # @return an integer
    def solve(self, A, B):
        occur = 0
        for i in range(len(A)):
            if (B == A[i]):
                occur += 1
        
        return occur
