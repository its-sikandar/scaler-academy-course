# Time Complexity

## 1. Log Basics

**Logarithm**: log₂ N = x means 2ˣ = N

### Examples:
- log₂ 64 = 6 (since 2⁶ = 64)
- log₃ 27 = 3 (since 3³ = 27)
- log₂ 32 = 5 (since 2⁵ = 32)

### Key Problem:
**How many times can we divide N by 2 until it reaches 1?**
- Answer: log₂ N times
- Time Complexity: O(log N)

## 2. Iteration Problems & Analysis

### Quiz 1: Division by 2
```c
i = N;
while(i > 1) {
    i = i / 2;
}
```
**TC: O(log N)** - We divide by 2 until reaching 1

### Quiz 2: Multiplication by 2
```c
for(i = 1; i < N; i = i * 2) {
    // operations
}
```
**TC: O(log N)** - We multiply by 2 until reaching N

### Quiz 3: Infinite Loop
```c
for(i = 0; i <= N; i = i * 2) {
    // operations
}
```
**TC: Infinite** - Starting from 0, multiplying by 2 never increases

### Quiz 4: Constant Outer Loop
```c
for(i = 1; i <= 10; i++) {
    for(j = 1; j <= N; j++) {
        // operations
    }
}
```
**TC: O(N)** - Outer loop runs 10 times (constant), inner runs N times

### Quiz 5: Nested Linear Loops
```c
for(i = 1; i <= N; i++) {
    for(j = 1; j <= N; j++) {
        // operations
    }
}
```
**TC: O(N²)** - Both loops run N times

### Quiz 6: Outer Linear, Inner Logarithmic
```c
for(i = 1; i <= N; i++) {
    for(j = 1; j <= N; j = j * 2) {
        // operations
    }
}
```
**TC: O(N log N)** - Outer runs N times, inner runs log N times

### Quiz 7: Triangular Pattern (Small)
```c
for(i = 1; i <= 4; i++) {
    for(j = 1; j <= i; j++) {
        // operations
    }
}
```
**TC: O(1)** - Fixed iterations: 1+2+3+4 = 10

### Quiz 8: Triangular Pattern (Variable)
```c
for(i = 1; i <= N; i++) {
    for(j = 1; j <= i; j++) {
        // operations
    }
}
```
**TC: O(N²)** - Total iterations: 1+2+3+...+N = N(N+1)/2

### Quiz 9: Exponential Inner Loop
```c
for(i = 1; i <= N; i++) {
    for(j = 1; j <= 2^i; j++) {
        // operations
    }
}
```
**TC: O(2ⁿ)** - Total iterations: 2¹+2²+2³+...+2ⁿ = 2ⁿ⁺¹-2

## 3. Time Complexity - Big O Notation

### Definition
**Time Complexity** measures how the number of operations grows with input size.

### Big O Rules:
1. **Calculate iterations** based on input size
2. **Ignore lower order terms**: 5N² + 3N + 1 → O(N²)
3. **Ignore constant coefficients**: 100N → O(N)

### Common Time Complexities (Best to Worst):
- O(1) - Constant
- O(log N) - Logarithmic
- O(N) - Linear
- O(N log N) - Linearithmic
- O(N²) - Quadratic
- O(N³) - Cubic
- O(2ⁿ) - Exponential

### Why Ignore Constants?
For large inputs, the **rate of growth** matters more than constant factors.

## 4. Why TLE (Time Limit Exceeded)?

### Processing Capacity:
- **1 second = 10⁸ operations** (approximate)
- Each iteration ≈ 10-100 instructions

### TLE Analysis:
- **Constraint: N ≤ 10⁵**
  - O(N²) = (10⁵)² = 10¹⁰ operations → **TLE**
  - O(N) = 10⁵ operations → **Safe**
  - O(N log N) = 10⁵ × 17 ≈ 1.7 × 10⁶ → **Safe**

### Rule of Thumb:
- **10⁸ operations or less** → Usually passes
- **More than 10⁸ operations** → Likely TLE

### Optimization Strategy:
1. Read constraints carefully
2. Choose algorithm with appropriate time complexity
3. Aim for operations ≤ 10⁸ per second
