# Chores
```cpp
    for(int i = 0; i < 20; i += 1){
        ncr[i][0] = ncr[i][i] = 1;
        for(int j = 1; j < i; j += 1) ncr[i][j] = ncr[i - 1][j] + ncr[i - 1][j - 1];
    }
```
```cpp
  ll get(ll n, ll nzRem){
    ll res = 0;
    for(int i = 0; i < nzRem + 1; i += 1) res += pw[i] * comb(n, i);

    return res;
  }
```
- The number of divisors of a number *t* is at most *O(3∛t)*. This bound comes from **number theory** and is derived based on the prime factorization of *t*.

## Möbius Function (μ(n))

The **Möbius function**, denoted as **μ(n)**, is an important number-theoretic function used in combinatorial number theory and the study of arithmetic functions. It is defined as:

**Definition**

The Möbius function **μ(n)** is defined as follows:

```math
\mu(n) =
\begin{cases}
  1, & \text{if } n = 1 \\
  0, & \text{if } n \text{ has a squared prime factor} \\
  (-1)^k, & \text{if } n \text{ is a product of } k \text{ distinct prime factors}
\end{cases}
```


### Important Properties

1. **Multiplicativity**: The Möbius function is **multiplicative**, meaning:
    ```math
    \mu(a \cdot b) = \mu(a) \cdot \mu(b), \quad \text{if } \gcd(a, b) = 1
    ```

2. **Summation Formula**:
    ```math
    \sum_{{d \mid n}} \mu(d) =
    \begin{cases}
      1, & \text{{if }} n = 1 \\
      0, & \text{{if }} n > 1
    \end{cases}
    ```

3. **Euler’s Totient Function Relation**:
    ```math
    \sum_{{d \mid n}} \mu(d) \cdot \frac{{n}}{d} = \phi(n)
    ```
    where \( \phi(n) \) is Euler's totient function.

4. **Dirichlet Convolution**:
    ```math
    \sum_{{d \mid n}} \mu(d) = [n = 1]
    ```

5. **Mertens Function**:
    ```math
    M(n) = \sum_{{k=1}}^{n} \mu(k)
    ```
## **Explanation**
1. **Divisors from Prime Factorization**  
   Suppose *t* is factored as:
   ```math
   t = p_1^{e_1} \cdot p_2^{e_2} \cdot p_3^{e_3} \cdots p_k^{e_k}
    ```
   where *p<sub>1</sub>, p<sub>2</sub>,.., p<sub>k</sub> are distinct prime numbers and e<sub>1</sub>, e<sub>2</sub>, .., e<sub>k</sub>* are their respective exponents.

2. **Formula for Number of Divisors:**  
   The number of divisors *d(t)* of *t* is given by:
   ```math
   d(t) = (e_1 + 1) \cdot (e_2 + 1) \cdot \dots \cdot (e_k + 1)
   ```
   Since each exponent e<sub>i</sub> contributes an extra factor to the number of divisors, the growth of *d(t)* is tied to how many prime factors *t* has and how large the exponents are.

3. **Worst-Case Estimation:**  
   - If *t* is **cube-free** (meaning no prime factor appears more than twice), then *e<sub>i</sub> &le; 2*
   - The maximum number of distinct prime factors in *t* is approximately *O(log t)*, but in practice, it is usually much smaller.
   - A common **upper bound** on the number of divisors is:
     ```math
     d(t) = O(3\sqrt[3]{t})
     ```
     This is derived from the assumption that the product of terms *e<sub>i</sub> + 1* in the divisor formula is maximized when *t* has many small prime factors.

4. **Tighter Bound:**  
   A more precise bound, established in number theory, is:
   ```math
   d(t) = O(t^{1/3} \log t)
   ```
   This is useful for computational estimates but is slightly looser than the *O(3∛t)* bound often used in problem-solving.

   ## Example Values

    <table>
  <tr>
    <th style="width:300px;">n</th>
    <th style="width:150px;">μ(n)</th>
  </tr>
  <tr><td>1</td><td>1</td></tr>
  <tr><td>2</td><td>-1</td></tr>
  <tr><td>3</td><td>-1</td></tr>
  <tr><td>4</td><td>0</td></tr>
  <tr><td>5</td><td>-1</td></tr>
  <tr><td>6</td><td>1</td></tr>
  <tr><td>7</td><td>-1</td></tr>
  <tr><td>8</td><td>0</td></tr>
  <tr><td>9</td><td>0</td></tr>
  <tr><td>10</td><td>1</td></tr>
</table>

## Implementation
```cpp
    for(int i = 0; i < n; i += 1){
        cin >> vc[i]; mul[vc[i]] = (mul[vc[i]] + mul[vc[i]]) % MOD;
    }
    for(int i = 1; i < N; i += 1){
        for(int j = i * 2; j < N; j += i) mul[i] = (mul[i] * mul[j]) % MOD;
    }
    mobius[1] = 1;
    ll ans = 0;
    for(int i = 1; i < N; i += 1){
        for(int j = 2 * i; j < N; j += i) mobius[j] = (mobius[j] - mobius[i] + MOD) % MOD;
    }
```

## Whispers of Wisdom
- There's no direct theorem for counting number of subarray's of *gcd = 1*. A way to get around that is use **Möbius function**.
# Related Problems
* [D. Yet Another Problem On a Subsequence](https://codeforces.com/contest/1000/problem/D)
  ## Intuition
    Here the constraint suggest we can either use an alogrithm of *O(n<sup>2</sup>)* or a *2D*-DP (as this is obviously a combinatorics problem and can't possibly couunt something that we have to do modulous by 998244353)
  ## Solution
    First we are asked to find number of subsequences which contain good subarray. Now each subsequence can contain number of good array and it is tough to count them all in one go right? and that too for each index. So how should we go on about this?
    Let's go through each element in the array. As we know *a<sub>1</sub> = k - 1* and *a<sub>1</sub> > 0*. So, all we have to worry about is the first element. The array has to be of *k = a<sub>1</sub> + 1* length right? Now let's choose
    *a<sub>1</sub> + 1* elements and there isn't any condition on the elements and we can leave elements as well as we can choose sub-sequences. So we can choose *a<sub>1</sub>* number of elements from if *i* is the index of *a<sub>1</sub>* then from *i + 1 + a<sub>1</sub>* to
    *n*. Then say we have chosen till the index *j - 1* now as a subsequence can contain multiple good arrays let's take that into consideration and count if next good array starts from *j*.

* [D. Lost Arithmetic Progression](https://codeforces.com/problemset/problem/1673/D)
  ## Intuition
    Here constraints doesn't suggest it'll be a dp problem neither does it feel like one. It will probably be a pure combinatorics problem.
  ## Solution
    *C* contains the common of arrray *A* and *B*. So, B must contain all the element of *C*. And as it an arithmetic progression so *p* (common difference of *C*) must be a divisor of *r*. Now it is true for the common difference *q* as well. But only the elements in *C* can be common for both *A* and *B*. So, *p* and *q* has to be co-prime of each other. So that *p . q = r* and both of them will only meet at *r*. And now all comes down
  when the result will be *-1?* Answer is pretty simple. Element of *B* is set. It has to contain the elements of *C* and can't contain any other element of *A*. So, number of element it can contain with in is pretty much constrained. Only freedom it has is at the front and at the back. We infer that if *c - r < b* then answer will be *-1* as we can have *c - r, c - 2r, ..* any of them as the first element for *B*. But if *c - r >= b* as *p . q = r* or *lcm(p, q) = r* it will meet at c - r which can't happen as it is not at *C*

* [C. Classy Numbers](https://codeforces.com/problemset/problem/1036/C)
  ## Intuition
  When considering range like l..r consider the conventional pref[r] - pref[l - 1]. This can be used here. And from the look of it. This looks like a conventional combinatorics problem. Subsequnce of places where digit will be non-zero. Classic.
    ## Solution
  Now, say i have to find numbers less than l. We know that the first position from the left (msb) where digits differ is less than what of l then we won't have to worry about rest of the digits right? How to calculate this? Say current digit is d then
  ```math
  (d - 1) \cdot \sum_{i = 0}^{2} \binom{x - 1}{i} \cdot g ^ i
  ```
  As there are *d* number of options *(1, 2, .. d - 1)* for the current position. And we can stil have at most 2 non-zero digits. Now there is one thing we haven't considered. There could have been non-zeros before the current position right? How to deal with it? Say there were *k* number of that.
  ```math
  (d - 1) \cdot \sum_{i = 0}^{3 - k + 1} \binom{x - 1}{i} \cdot g ^ i
  ```
  As we there were already *k* number of non-zeros in the prefix and we are taking one here. So, *k - 1* number of non-zeros in total is taken. We can take *3 - k + 1* more at most. And there is one more thing we haven't considered what if the current position is a zero digit? 
  ```math
  \sum_{i = 0}^{3 - k} \binom{x - 1}{i} \cdot g^i
  ```
  Now we just have to go through each position add these values. 
  ```math
  (d - 1) \cdot \sum_{i = 0}^{3 - k + 1} \binom{x - 1}{i} \cdot g ^ i + \sum_{i = 0}^{3 - k} \binom{x - 1}{i} \cdot g^i
  ```
* [D. Vanya and Triangles](https://codeforces.com/contest/552/problem/D)
  ## Intuition
  From what we can see here from the constraints we can go *O(n<sup>2</sup>)*, *2-DP*. But this doesn't look like a *2-DP* problem no matter how you look at it (Co-ordinates, even if you connect two points to form sides). To take a closer look at the *O(n<sup>2</sup>)* solution. What we know about triangle is if *a, b , c* are thre sides than *a + b > c*, if *c* is the largest side then this alone suffices. But can we do it with in the time frame? Probably no. Let's look at it from another angle in order for a traingle to be digenerate all it's point has to be on the same line right? And their slope is same right?
  ## Solution
  Initially there are *n* points. there are
  ```math
  \binom{n}{3}
  ```
  ways to choose to form traingle. Now we just have to subtract the points that are in the same line. As they have the same slope, count *dx / dy*.
* [E. Number of Simple Paths](https://codeforces.com/problemset/problem/1622/D)
  ## Intuition
  The constraints suggest that we can use code of *O(n<sup>2</sup>)* complexity. We are asked to find substrings of exactly *k* *1* characters. Now we can find all the such substrings easily n that time frame. Now
  the first issue is we can shuffle, and find the number of different resulting substrings. If a substring is of *n* length then how many different substring can be formed? Definitely not *n!*. There are only two
  distinct characters, according to this formula *0110 & 01110* are considered different as two *1*s can be of different positions. So what will be formula? *4C2* placcing *2 1s* in *4* different position.  
  
