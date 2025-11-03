def maximum(A):
    max = A[0]

    for i in range(len(A)):
        if (A[i] > max):
            max = A[i]
    return max

class Solution:
    # @param A : list of integers
    # @return an integer
    def solve(self, A):
        max = maximum(A)
        count = 0
        for i in range (len(A)):
            if (A[i] < max):
                count += 1
        return count
