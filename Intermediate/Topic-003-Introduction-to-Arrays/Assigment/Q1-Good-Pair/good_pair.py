import sys
class Solution:
    # @param A : list of integers
    # @param B : integer
    # @return an integer
    def solve(self, A, B):
        if (len (A) <= 1):
            return 0

        for i in range (0, len(A)):
            for j in range (0, len(A)):
                if i != j:
                    if (B == A[i] + A[j]):
                        return 1
        
        return 0
    
## Runner code
if __name__ == "__main__":
    input_array = list(map(int, input("Enter the elements of the array separated by spaces: ").strip().split()))
    target_sum = int(input("Enter the target sum (B): "))
    solution = Solution()
    result = solution.solve(input_array, target_sum)
    if result == 1:
        print(f"A good pair exists in the array for the target sum {target_sum}.")
    else:
        print(f"No good pair exists in the array for the target sum {target_sum}.")