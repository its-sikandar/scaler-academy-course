def is_perfect(A):
    total = 0
    for i in range(1, A//2 + 1):
        if (A%i == 0):
            total += i

    if total == A:
        return 1
    else:
        return 0



class Solution:
    # @param A : integer
    # @return an integer
    def solve(self, A):
        return is_perfect(A)

    
## Runner code
if __name__ == "__main__":
    number = int(input("Enter the positive integer: "))
    solution = Solution()
    result = solution.solve(number)
    if result == 1:
        print(f"{number} is a perfect number.")
    else:
        print(f"{number} is not a perfect number.")