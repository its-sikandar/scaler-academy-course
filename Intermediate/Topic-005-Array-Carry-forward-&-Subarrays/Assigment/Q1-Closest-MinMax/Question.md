# Q1. Closest MinMax

## Problem Description

Given an array A, find the size of the smallest subarray such that it contains at least one occurrence of the maximum value of the array and at least one occurrence of the minimum value of the array.

## Problem Constraints

1 <= |A| <= 2000

## Input Format

First and only argument is vector A

## Output Format

Return the length of the smallest subarray which has at least one occurrence of minimum and maximum element of the array

## Example Input

**Input 1:**
```
A = [1, 3, 2]
```

**Input 2:**
```
A = [2, 6, 1, 6, 9]
```

## Example Output

**Output 1:**
```
2
```

**Output 2:**
```
3
```

## Example Explanation

**Explanation 1:**
Array: [1, 3, 2]
- Min = 1 (at index 0), Max = 3 (at index 1)
- Smallest subarray containing both min and max: [1, 3] from index 0 to 1
- Length = 2

**Explanation 2:**
Array: [2, 6, 1, 6, 9]
- Min = 1 (at index 2), Max = 9 (at index 4)
- Smallest subarray containing both min and max: [1, 6, 9] from index 2 to 4
- Length = 3

## Solutions

- **C Solution:** [Closest-MinMax.c](./Closest-MinMax.c)
- **Python Solution:** [Closest-MinMax.py](./Closest-MinMax.py)