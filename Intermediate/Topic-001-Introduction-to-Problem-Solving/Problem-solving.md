# Introduction to Problem Solving - Technical Revision

## Key Problem Types

### 1. Count of Factors

**Problem**: Given N, find count of factors of N

**Examples**:
- N = 24 → Factors: 1,2,3,4,6,8,12,24 → Count = 8
- N = 10 → Factors: 1,2,5,10 → Count = 4

**Brute Force Approach**:
```c
count = 0;
for(i = 1; i <= N; i++) {
    if(N % i == 0) count++;
}
// Time Complexity: O(N)
// Space Complexity: O(1)
```

**Optimized Approach**:
```c
count = 0;
for(i = 1; i*i <= N; i++) {
    if(N % i == 0) {
        if(i*i == N) count++;  // Perfect square case
        else count += 2;       // Two factors: i and N/i
    }
}
// Time Complexity: O(√N)
// Space Complexity: O(1)
```

**Key Insight**: Factors come in pairs. For N=24: (1,24), (2,12), (3,8), (4,6)

### 2. Prime Numbers

**Definition**: Numbers with exactly 2 factors (1 and itself)

**Problem**: Check if N is prime

**Method**: Use factor counting
```c
if(N <= 1) return false;
if(count_factors(N) == 2) return true;
else return false;
```

**Examples**:
- 2, 3, 5, 7, 11, 13, 17, 19, 23... are prime
- 4, 6, 8, 9, 10, 12, 14, 15, 16... are not prime

## Performance Analysis

### Time Complexity Comparison
| Input Size | Brute Force O(N) | Optimized O(√N) |
|------------|------------------|-----------------|
| N = 10⁶    | 10⁶ iterations  | 10³ iterations  |
| N = 10⁹    | 10⁹ iterations  | ~31,623 iterations |
| N = 10¹²   | 10¹² iterations | 10⁶ iterations |

### Processing Speed Reference
- **1 second** = ~10⁸ iterations
- **10 seconds** = ~10⁹ iterations
- **317 years** = ~10¹⁸ iterations

### Why Optimization Matters
```
Brute Force: O(N)
- For N = 10¹⁸ → Takes 317 years

Optimized: O(√N)  
- For N = 10¹⁸ → Takes ~10 seconds
```

## Important Mathematical Concepts

### Factor Properties
- **Smallest factor**: Always 1
- **Largest factor**: Always N (for N > 1)
- **Perfect squares**: Have odd number of factors
- **Non-perfect squares**: Have even number of factors

### Iteration Analysis
```c
// Quiz Examples:
for(i = 1; i <= N; i++) {           // N iterations
    if(i == N) break;
}

for(i = 1; i*i <= N; i++) {         // √N iterations
    // operations
}

for(i = 1; i <= N; i++) {           // N iterations
    for(j = 1; j <= N; j++) {       // N×N = N² total iterations
        // operations
    }
}
```

### Range Notation
- `[a, b]` → Includes both a and b
- `[a, b)` → Includes a, excludes b  
- `(a, b]` → Excludes a, includes b
- `(a, b)` → Excludes both a and b

## Algorithm Comparison

### Why Use Iterations Instead of Time?
**Time depends on**:
- Hardware (Windows XP vs MacBook M2)
- Programming language (C vs Python)
- Environment conditions
- System load

**Iterations are**:
- Hardware independent
- Language independent
- Consistent measure
- Standard for algorithm analysis
