# Q3. Special Subsequences "AG" - 2

## Problem Description

You have given a string A having Uppercase English letters.

You have to find the number of pairs (i, j) such that A[i] = 'A', A[j] = 'G' and i < j.

## Problem Constraints

1 <= length(A) <= 10^5

## Input Format

First and only argument is a string A.

## Output Format

Return a long integer denoting the answer.

## Example Input

**Input 1:**
```
A = "ABCGAG"
```

**Input 2:**
```
A = "GAB"
```

## Example Output

**Output 1:**
```
3
```

**Output 2:**
```
0
```

## Example Explanation

**Explanation 1:**
String: "ABCGAG"
Indices: 0 1 2 3 4 5

Subsequence "AG" appears 3 times with the following pairs:
- (0, 3): A[0] = 'A', A[3] = 'G'
- (0, 5): A[0] = 'A', A[5] = 'G' 
- (4, 5): A[4] = 'A', A[5] = 'G'

**Explanation 2:**
String: "GAB"
There is no subsequence "AG" in the given string because 'A' appears after 'G', violating the condition i < j.

## Solutions

- **C Solution:** [Special-Subsequences-"AG"-2.c](./Special-Subsequences-"AG"-2.c)
- **Python Solution:** [Special-Subsequences-"AG"-2.py](./Special-Subsequences-"AG"-2.py)