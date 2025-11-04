# Topic 004: Arrays - Prefix Sum

## A. What is Prefix Sum Array and How to Calculate It?

### Definition
**Prefix Sum Array**: An array where each element at index `i` contains the sum of all elements from index `0` to index `i` in the original array.

### Formula
```
P[0] = A[0]
P[i] = P[i-1] + A[i]  (for i = 1 to N-1)
```

### Example
```
Original Array: [ -3, 6, 2, 4, 5, 2, 8, -9, 3, 1 ]
Index:          [  0, 1, 2, 3, 4, 5, 6,  7, 8, 9 ]

Prefix Sum:     [ -3, 3, 5, 9, 14, 16, 24, 15, 18, 19 ]
```

### Real-World Example: Cricket Scores
```
Royal Challengers Bengaluru's runs in first 10 overs:
Runs per over: [ 10, 32, 6, 12, 20, 1, ? , ? , ? , ? ]
Index (Over):  [  1,  2, 3,  4,  5, 6, 7, 8, 9, 10 ]

Prefix Sum:    [ 10, 42, 48, 60, 80, 81, ?, ?, ?, ? ]
```

**Queries using Prefix Sum**:
- Runs scored in 7th over = A[6]
- Runs scored in 10th over = A[9] 
- Runs scored from 6-10th over = P[9] - P[5]
- Runs scored from 3-6th over = P[5] - P[2]
- Runs scored from 4-9th over = P[8] - P[3]

### Time & Space Complexity
- **Time Complexity**: O(N) for creation
- **Space Complexity**: O(N) for separate array, O(1) if modifying input array

### In-place Modification (Space Optimized)
```c
// Modify the same array to store prefix sum
// Only possible if updating input is allowed
A[0] = A[0];  // First element remains same
for (int i = 1; i < N; i++) {
    A[i] = A[i-1] + A[i];
}
// Now A[] contains prefix sum
```
**Space Complexity**: O(1) - No extra space needed

---

## B. Range Sum Queries

### Problem Statement
Given an array of N integers and Q queries, for each query calculate the sum of elements in the range [L, R].

**Constraints**: 1 ≤ N, Q ≤ 10^5

### Brute Force Approach
```c
// For each query
for (int i = 0; i < Q; i++) {
    int sum = 0;
    for (int j = L[i]; j <= R[i]; j++) {
        sum += A[j];
    }
    printf("%d\n", sum);
}
```
**Time Complexity**: O(Q × N)  
**Space Complexity**: O(1)

### Optimized Approach (Using Prefix Sum)
```c
// Create prefix sum array
P[0] = A[0];
for (int i = 1; i < N; i++) {
    P[i] = P[i-1] + A[i];
}

// Answer queries
for (int i = 0; i < Q; i++) {
    int L = left[i], R = right[i];
    if (L == 0) {
        printf("%d\n", P[R]);
    } else {
        printf("%d\n", P[R] - P[L-1]);
    }
}
```
**Time Complexity**: O(N + Q)  
**Space Complexity**: O(N)

### Key Formula for Range Sum
- Sum from index L to R = `P[R] - P[L-1]` (if L > 0)
- Sum from index 0 to R = `P[R]`

---

## C. Sum of Even Indexed Elements

### Problem Statement
Given an array and Q queries with start(s) and end(e) indices, for every query print sum of all even indexed elements from s to e.

### Approach
Create a prefix sum array only for even indexed elements:

```c
// Create prefix sum for even indices
P_even[0] = A[0];  // Index 0 is even
for (int i = 1; i < N; i++) {
    if (i % 2 == 0) {  // Even index
        P_even[i] = P_even[i-1] + A[i];
    } else {  // Odd index
        P_even[i] = P_even[i-1];
    }
}

// Answer queries
for (int i = 0; i < Q; i++) {
    int L = start[i], R = end[i];
    if (L == 0) {
        printf("%d\n", P_even[R]);
    } else {
        printf("%d\n", P_even[R] - P_even[L-1]);
    }
}
```

### Example
```
Array:     [ 2, 3, 1, 6, 4, 5 ]
Index:     [ 0, 1, 2, 3, 4, 5 ]
P_even:    [ 2, 2, 3, 3, 7, 7 ]
```

---

## D. Sum of Odd Indexed Elements

### Problem Statement
For all queries, find the sum of odd indexed elements from s to e.

### Approach
Create a prefix sum array only for odd indexed elements:

```c
// Create prefix sum for odd indices
P_odd[0] = 0;  // Index 0 is even, so no odd element yet
for (int i = 1; i < N; i++) {
    if (i % 2 == 1) {  // Odd index
        P_odd[i] = P_odd[i-1] + A[i];
    } else {  // Even index
        P_odd[i] = P_odd[i-1];
    }
}
```

### Example
```
Array:    [ 2, 3, 1, 6, 4, 5 ]
Index:    [ 0, 1, 2, 3, 4, 5 ]
P_odd:    [ 0, 3, 3, 9, 9, 14 ]
```

---

## E. Special Index Problem

### Problem Statement
Given an array, count the number of special indices. A **Special Index** is an index after removing which, the sum of even indexed elements equals the sum of odd indexed elements.

### Approach
1. Create two prefix sum arrays: one for even indices, one for odd indices
2. For each index i, calculate what would happen if we remove element at index i
3. After removal, elements shift, so indices change

### Algorithm
```c
// Create prefix sum arrays
P_even[0] = A[0];
P_odd[0] = 0;

for (int i = 1; i < N; i++) {
    if (i % 2 == 0) {
        P_even[i] = P_even[i-1] + A[i];
        P_odd[i] = P_odd[i-1];
    } else {
        P_even[i] = P_even[i-1];
        P_odd[i] = P_odd[i-1] + A[i];
    }
}

int count = 0;
for (int i = 0; i < N; i++) {
    int sum_even, sum_odd;
    
    if (i == 0) {
        sum_even = P_odd[N-1];  // After removal, odd becomes even
        sum_odd = P_even[N-1] - P_even[0];  // After removal, even becomes odd
    } else {
        sum_even = P_even[i-1] + (P_odd[N-1] - P_odd[i]);
        sum_odd = P_odd[i-1] + (P_even[N-1] - P_even[i]);
    }
    
    if (sum_even == sum_odd) {
        count++;
    }
}
```

### Example
```
Array: [ 4, 3, 2, 7, 6, -2 ]
Index: [ 0, 1, 2, 3, 4,  5 ]

P_even: [ 4, 4, 6, 6, 12, 12 ]
P_odd:  [ 0, 3, 3, 10, 10, 8 ]
```

### Step-by-Step Special Index Calculation

| i | Sum_even (Se) | Sum_odd (So) | Se == So? | Special? |
|---|---------------|--------------|-----------|----------|
| 0 | P_odd[N-1] = 8 | P_even[N-1] - P_even[0] = 12 - 4 = 8 | 8 == 8 | ✅ Yes |
| 1 | P_even[0] + (P_odd[N-1] - P_odd[1]) = 4 + (8 - 3) = 9 | P_odd[0] + (P_even[N-1] - P_even[1]) = 0 + (12 - 4) = 8 | 9 == 8 | ❌ No |
| 2 | P_even[1] + (P_odd[N-1] - P_odd[2]) = 4 + (8 - 3) = 9 | P_odd[1] + (P_even[N-1] - P_even[2]) = 3 + (12 - 6) = 9 | 9 == 9 | ✅ Yes |
| 3 | P_even[2] + (P_odd[N-1] - P_odd[3]) = 6 + (8 - 10) = 4 | P_odd[2] + (P_even[N-1] - P_even[3]) = 3 + (12 - 6) = 9 | 4 == 9 | ❌ No |
| 4 | P_even[3] + (P_odd[N-1] - P_odd[4]) = 6 + (8 - 10) = 4 | P_odd[3] + (P_even[N-1] - P_even[4]) = 10 + (12 - 12) = 10 | 4 == 10 | ❌ No |
| 5 | P_even[4] + (P_odd[N-1] - P_odd[5]) = 12 + (8 - 8) = 12 | P_odd[4] + (P_even[N-1] - P_even[5]) = 10 + (12 - 12) = 10 | 12 == 10 | ❌ No |

**Result**: Special indices are at positions 0 and 2. Total count = 2

### Explanation of Logic
When we remove element at index `i`:
- **Sum_even**: Elements before `i` that were at even positions + Elements after `i` that were at odd positions (they shift to even)
- **Sum_odd**: Elements before `i` that were at odd positions + Elements after `i` that were at even positions (they shift to odd)

**Formula**:
- If `i == 0`: 
  - `Se = P_odd[N-1]` (all odd indices become even)
  - `So = P_even[N-1] - P_even[0]` (all even indices except 0 become odd)
- If `i > 0`:
  - `Se = P_even[i-1] + (P_odd[N-1] - P_odd[i])`
  - `So = P_odd[i-1] + (P_even[N-1] - P_even[i])`

**Time Complexity**: O(N)  
**Space Complexity**: O(N)

---

## Key Takeaways

1. **Prefix Sum** is a powerful technique for range sum queries
2. **Even/Odd Index Prefix Sum** helps solve specific index-based problems
3. **Special Index** problems require careful handling of index shifts after removal
4. Always consider edge cases (L=0, single element arrays)
5. Prefix sum reduces query time from O(N) to O(1)

---

## Practice Problems
1. Range sum queries with updates
2. Maximum subarray sum using prefix sum
3. Count of subarrays with given sum
4. Equilibrium index problems

---

## Quiz Questions

### Q1: What happens to time complexity?
- **Brute Force**: O(Q × N) for Q queries
- **Prefix Sum**: O(N + Q) - O(N) for preprocessing + O(1) per query

### Q2: Space-Time Tradeoff
- **Extra Space**: O(N) for prefix array, but O(1) query time
- **In-place**: O(1) space, but modifies original array

### Q3: Edge Cases to Remember
- When L = 0 in range queries: Use P[R] directly
- Empty arrays or single element arrays
- Negative numbers in the array (prefix sum still works)
- Integer overflow for large sums

---

## Additional Examples

### Range Sum Calculation
```
arr[10] → [ -3, 6, 2, 4, 5, 2, 8, -9, 3, 1 ]
P[10]   → [ -3, 3, 5, 9, 14, 16, 24, 15, 18, 19 ]

Query: Sum from index 2 to 5
Answer: P[5] - P[1] = 16 - 3 = 13
Verification: 2 + 4 + 5 + 2 = 13 ✓
```