class Solution:
    # @param A : list of integers
    # @param B : integer
    # @param C : integer
    # @return a list of integers
    def solve(self, A, B, C):
        # subArray = A[B:C+1] // Shortcut

        length = C - B + 1
        subArray = [0] * length

        i  = 0
        j = B

        while ( i < length ):
            subArray[i] = A[j]
            i += 1
            j += 1
            
        return subArray
