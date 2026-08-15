# Summation of Geometric Series

Programs for summation of the series:

**1 + X + X² + X³ + … + Xⁿ**

## Method 1 – Using Geometric Series Formula

### Algorithm: `SumGeoSeries(a, r, n)`

1. Initialize `sum = 0`
2. Calculate the sum using the formula:
   `sum = a * (rⁿ - 1) / (r - 1)`
3. Return `sum`

**Time Complexity:** `O(1)`

**Space Complexity:** `O(1)`

---

## Method 2 – Using Iteration

### Algorithm: `SumGeoSeries(a, r, n)`

1. Initialize `sum = 0`
2. For `i = 0` to `n`:

   * `sum = sum + a * r^i`
3. Return `sum`

**Time Complexity:** `O(n)`

**Space Complexity:** `O(1)`

---

## Comparison

|  Method  | Approach                 | Time Complexity | Space Complexity |
| :------: | :----------------------- | :-------------- | :--------------- |
| Method 1 | Geometric Series Formula | `O(1)`          | `O(1)`           |
| Method 2 | Iteration                | `O(n)`          | `O(1)`           |

### Note

For `r = 1`, the formula in Method 1 becomes undefined. In that case, the sum is:

`sum = a × (n + 1)`
