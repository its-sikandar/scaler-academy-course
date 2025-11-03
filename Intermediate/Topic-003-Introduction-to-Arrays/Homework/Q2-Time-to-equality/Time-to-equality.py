def maximum(A):
    max = A[0]
    for i in range(1, len(A)):
        if A[i] > max :
            max = A[i]
    return max

class Solution:
    # @param A : list of integers
    # @return an integer
    def solve(self, A):
        max = maximum(A)
        time = 0
        for i in range(len(A)):
            time += (max - A[i])
        
        return time
