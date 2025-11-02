class Solution:
    # @param A : list of integers
    # @param B : integer
    # @param C : integer
    # @return a list of integers
    def solve(self, A, B, C):

        i = B
        j = C 

        while i < j:
            temp = A[i]
            A[i] = A[j]
            A[j] = temp
            i += 1
            j -= 1
        return A
