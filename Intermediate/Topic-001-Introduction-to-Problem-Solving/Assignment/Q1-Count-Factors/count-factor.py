import sys

def count_factors(n):
    if n <= 0:
        return 0
    
    count = 0


    for i in range (1, int(n**0.5) + 1):
        if n % i == 0:
            # Perfect square case
            if i * i == n:
                count += 1
            else:
                count += 2 

    return count

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python count-factor.py <positive_integer>")
        sys.exit(1)

    try:
        number = int(sys.argv[1])
        if number <= 0:
            raise ValueError
    except ValueError:
        print("Please provide a valid positive integer.")
        sys.exit(1)

    factors_count = count_factors(number)
    print(f"The number of factors of {number} is: {factors_count}")