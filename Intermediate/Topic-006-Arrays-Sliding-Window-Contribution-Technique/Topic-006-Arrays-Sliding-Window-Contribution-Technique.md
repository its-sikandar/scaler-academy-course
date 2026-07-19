# Topic 006: Arrays - Sliding Window & Contribution Technique

## Quick Revision Tips 📝
- **Sliding Window:** Fixed-size window that slides across array - O(N) instead of O(N²)
- **Two Types:** Fixed-size window vs Variable-size window
- **Contribution Technique:** Calculate total contribution of each element across all subarrays
- **Subarray Formula:** Element at index i appears in (i+1) × (N-i) subarrays
- **Time Complexity:** Sliding Window = O(N), Brute Force = O(N²)

---

## 1. Sliding Window Technique

### Definition
**Sliding Window** is an optimization technique where we maintain a window (subarray) that slides through the array one element at a time, updating the result efficiently.

### When to Use?
- Problems involving consecutive elements (subarrays)
- Finding max/min sum of k consecutive elements
- Finding longest/shortest subarray with a condition
- Pattern matching in strings/arrays

### Types of Sliding Window

#### A. Fixed-Size Window
Window size remains constant (k elements)

**Problem:** Find maximum sum of k consecutive elements

**Brute Force:** O(N × K)
```c
int maxSum = INT_MIN;
for (int i = 0; i <= N - K; i++) {
    int sum = 0;
    for (int j = i; j < i + K; j++) {
        sum += arr[j];
    }
    maxSum = max(maxSum, sum);
}
```

**Optimized (Sliding Window):** O(N)
```c
// Calculate sum of first window
int windowSum = 0;
for (int i = 0; i < K; i++) {
    windowSum += arr[i];
}
int maxSum = windowSum;

// Slide the window
for (int i = K; i < N; i++) {
    windowSum = windowSum - arr[i - K] + arr[i];  // Remove left, add right
    maxSum = max(maxSum, windowSum);
}
```

**Python:**
```python
# First window
window_sum = sum(arr[:k])
max_sum = window_sum

# Slide window
for i in range(k, n):
    window_sum = window_sum - arr[i - k] + arr[i]
    max_sum = max(max_sum, window_sum)
```

**💡 Memory Trick:** "Remove left, Add right" - Slide by removing leftmost and adding rightmost

---

#### B. Variable-Size Window
Window size changes based on conditions

**Problem:** Find smallest subarray with sum ≥ S

```c
int left = 0, sum = 0, minLen = INT_MAX;
for (int right = 0; right < N; right++) {
    sum += arr[right];  // Expand window
    
    // Shrink window while condition is met
    while (sum >= S) {
        minLen = min(minLen, right - left + 1);
        sum -= arr[left];
        left++;
    }
}
```

---

## 2. Classic Sliding Window Problems

### A. Maximum Sum of K Consecutive Elements
```c
int maxSumKConsecutive(int arr[], int N, int K) {
    if (N < K) return -1;
    
    // First window
    int windowSum = 0;
    for (int i = 0; i < K; i++) {
        windowSum += arr[i];
    }
    int maxSum = windowSum;
    
    // Slide window
    for (int i = K; i < N; i++) {
        windowSum += arr[i] - arr[i - K];
        maxSum = max(maxSum, windowSum);
    }
    
    return maxSum;
}
```

### B. First Negative in Every Window of Size K
```c
void firstNegative(int arr[], int N, int K) {
    for (int i = 0; i <= N - K; i++) {
        int found = 0;
        for (int j = i; j < i + K; j++) {
            if (arr[j] < 0) {
                printf("%d ", arr[j]);
                found = 1;
                break;
            }
        }
        if (!found) printf("0 ");
    }
}
```

**Optimized using Queue:** O(N)
```python
from collections import deque

def first_negative_window(arr, k):
    negatives = deque()  # Store indices of negative numbers
    result = []
    
    # Process first window
    for i in range(k):
        if arr[i] < 0:
            negatives.append(i)
    
    # First window result
    if negatives:
        result.append(arr[negatives[0]])
    else:
        result.append(0)
    
    # Slide window
    for i in range(k, len(arr)):
        # Remove elements outside window
        while negatives and negatives[0] <= i - k:
            negatives.popleft()
        
        # Add new element if negative
        if arr[i] < 0:
            negatives.append(i)
        
        # Add result
        if negatives:
            result.append(arr[negatives[0]])
        else:
            result.append(0)
    
    return result
```

---

## 3. Contribution Technique

### Concept
Instead of iterating through all subarrays, calculate how many times each element appears in all subarrays and compute its total contribution.

### Key Formula
**For an element at index i in array of size N:**
- Number of subarrays containing arr[i] = `(i + 1) × (N - i)`

**Derivation:**
- Subarrays can start from index 0 to i (i+1 choices)
- Subarrays can end from index i to N-1 (N-i choices)
- Total = (i+1) × (N-i)

### Example
```
Array: [1, 2, 3, 4]
Index:  0  1  2  3
N = 4

Element at index 1 (value = 2):
- Can start from: 0, 1 → (1+1) = 2 choices
- Can end at: 1, 2, 3 → (4-1) = 3 choices  
- Total subarrays containing 2 = 2 × 3 = 6

Subarrays: [2], [1,2], [2,3], [1,2,3], [2,3,4], [1,2,3,4]
Count = 6 ✓
```

---

## 4. Sum of All Subarray Sums

### Problem
Given an array, find the sum of sums of all subarrays.

**Example:**
```
Array: [1, 2, 3]
Subarrays and their sums:
[1] = 1
[2] = 2
[3] = 3
[1,2] = 3
[2,3] = 5
[1,2,3] = 6

Total = 1 + 2 + 3 + 3 + 5 + 6 = 20
```

### Brute Force: O(N³)
```c
int totalSum = 0;
for (int i = 0; i < N; i++) {
    for (int j = i; j < N; j++) {
        int subarraySum = 0;
        for (int k = i; k <= j; k++) {
            subarraySum += arr[k];
        }
        totalSum += subarraySum;
    }
}
```

### Optimized with Prefix Sum: O(N²)
```c
// Create prefix sum
int prefix[N];
prefix[0] = arr[0];
for (int i = 1; i < N; i++) {
    prefix[i] = prefix[i-1] + arr[i];
}

int totalSum = 0;
for (int i = 0; i < N; i++) {
    for (int j = i; j < N; j++) {
        if (i == 0) {
            totalSum += prefix[j];
        } else {
            totalSum += prefix[j] - prefix[i-1];
        }
    }
}
```

### Optimized with Contribution: O(N)
```c
int totalSum = 0;
for (int i = 0; i < N; i++) {
    // Element arr[i] appears in (i+1) × (N-i) subarrays
    int contribution = arr[i] * (i + 1) * (N - i);
    totalSum += contribution;
}
```

**Python:**
```python
def sum_of_subarrays(arr):
    n = len(arr)
    total = 0
    for i in range(n):
        # Contribution of arr[i]
        contribution = arr[i] * (i + 1) * (n - i)
        total += contribution
    return total
```

**💡 Memory Trick:** "Left choices × Right choices" - (i+1) ways to start, (N-i) ways to end

---

## 5. Maximum Subarray Sum (Kadane's Algorithm)

### Problem
Find the contiguous subarray with the maximum sum.

### Kadane's Algorithm: O(N)
```c
int maxSubarraySum(int arr[], int N) {
    int maxSoFar = arr[0];
    int maxEndingHere = arr[0];
    
    for (int i = 1; i < N; i++) {
        maxEndingHere = max(arr[i], maxEndingHere + arr[i]);
        maxSoFar = max(maxSoFar, maxEndingHere);
    }
    
    return maxSoFar;
}
```

**Python:**
```python
def max_subarray_sum(arr):
    max_so_far = arr[0]
    max_ending_here = arr[0]
    
    for i in range(1, len(arr)):
        max_ending_here = max(arr[i], max_ending_here + arr[i])
        max_so_far = max(max_so_far, max_ending_here)
    
    return max_so_far
```

**Logic:**
- At each position, decide: start new subarray or extend current?
- If current sum + element > element alone, extend
- Otherwise, start fresh from current element

---

## 6. Minimum Subarray Sum

### Problem
Find the minimum sum among all subarrays.

### Approach: O(N)
```c
int minSubarraySum(int arr[], int N) {
    int minSoFar = arr[0];
    int minEndingHere = arr[0];
    
    for (int i = 1; i < N; i++) {
        minEndingHere = min(arr[i], minEndingHere + arr[i]);
        minSoFar = min(minSoFar, minEndingHere);
    }
    
    return minSoFar;
}
```

---

## 7. Length of Longest Subarray with Sum K

### Problem
Find length of longest subarray with sum equal to K.

### Brute Force: O(N²)
```c
int maxLen = 0;
for (int i = 0; i < N; i++) {
    int sum = 0;
    for (int j = i; j < N; j++) {
        sum += arr[j];
        if (sum == K) {
            maxLen = max(maxLen, j - i + 1);
        }
    }
}
```

### Optimized with Hash Map: O(N)
```python
def longest_subarray_sum_k(arr, k):
    prefix_sum = 0
    max_len = 0
    sum_map = {0: -1}  # {prefix_sum: index}
    
    for i in range(len(arr)):
        prefix_sum += arr[i]
        
        # If we need prefix_sum - k, check if it exists
        if (prefix_sum - k) in sum_map:
            length = i - sum_map[prefix_sum - k]
            max_len = max(max_len, length)
        
        # Store first occurrence only
        if prefix_sum not in sum_map:
            sum_map[prefix_sum] = i
    
    return max_len
```

---

## Key Concepts Summary

1. **Fixed-Size Sliding Window:** Maintain sum, remove left, add right - O(N)
2. **Variable-Size Window:** Expand with right pointer, shrink with left pointer
3. **Contribution Technique:** Element at index i appears in (i+1) × (N-i) subarrays
4. **Kadane's Algorithm:** Max subarray sum in O(N)
5. **Prefix Sum + HashMap:** Find subarray with target sum in O(N)

---

## Common Mistakes to Avoid ❌

- ❌ Forgetting to handle K > N in fixed window problems
- ❌ Not removing leftmost element when sliding window
- ❌ Confusing (i+1) × (N-i) formula for contribution
- ❌ In Kadane's, forgetting to compare with element itself (not just sum + element)
- ❌ In variable window, forgetting to update window bounds properly
- ❌ Not handling negative numbers in sum problems

---

## Pattern Recognition 🎯

- **"K consecutive elements"** → Fixed-size sliding window
- **"Subarray with sum = K"** → Variable window or prefix sum + hash map
- **"Maximum/Minimum in every window"** → Deque-based sliding window
- **"Sum of all subarrays"** → Contribution technique
- **"Maximum subarray sum"** → Kadane's algorithm
- **"Contains both min and max"** → Two pointers with position tracking

---

## Complexity Cheat Sheet

| Technique | Time | Space | Use Case |
|-----------|------|-------|----------|
| Brute Force | O(N²) or O(N³) | O(1) | Small inputs |
| Fixed Sliding Window | O(N) | O(1) | K consecutive elements |
| Variable Window | O(N) | O(1) | Dynamic size with condition |
| Contribution | O(N) | O(1) | Sum across all subarrays |
| Kadane's | O(N) | O(1) | Max/min subarray sum |
| Prefix + HashMap | O(N) | O(N) | Subarray with target sum |