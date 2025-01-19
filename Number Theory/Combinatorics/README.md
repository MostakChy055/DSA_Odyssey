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
  From what we can see here from the constraints we can go *O(n<sup>2</sup>)*, *2-DP*. But this doesn't look like a *2-DP* problem no matter how you look at it (Co-ordinates, even if you connect two points to form sides). To take a closer look at the *O(n<sup>2</sup>) solution. What we know about triangle is if *a, b , c* are thre sides than *a + b > c*, if *c* is the largest side then this alone suffices. But can we do it with in the time frame? Probably no. Let's look at it from another angle in order for a traingle to be digenerate all it's point has to be on the same line right? And their slope is same right?
  ## Solution
  Initially there are *n* points. there are
  ```math
  \binom{n}{3}
  ```
  ways to choose to form traingle. Now we just have to subtract the points that are in the same line. As they have the same slope, count dx / dy. 
