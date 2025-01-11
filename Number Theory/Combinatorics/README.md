# Related Problems
* [D. Yet Another Problem On a Subsequence](https://codeforces.com/contest/1000/problem/D)
  ## Intuition
    Here the constraint suggest we can either use an alogrithm of *O(n<sup>2</sup>)* or a *2D*-DP (as this is obviously a combinatorics problem and can't possibly couunt something that we have to do modulous by 998244353)
  ## Solution
    First we are asked to find number of subsequences which contain good subarray. Now each subsequence can contain number of good array and it is tough to count them all in one go right? and that too for each index. So how should we go on about this?
    Let's go through each element in the array. As we know *a<sub>1</sub> = k - 1* and *a<sub>1</sub> > 0*. So, all we have to worry about is the first element. The array has to be of *k = a<aub>1</sub> + 1* length right? Now let's choose
    *a<sub>1</sub> + 1* elements and there isn't any condition on the elements and we can leave elements as well as we can choose sub-sequences. So we can choose *a<sub>1</sub>* number of elements from if *i* is the index of *a<sub>1</sub>* then from *i + 1 + a<sub>1</sub>* to
    *n*. Then say we have chosen till the index *j - 1* now as a subsequence can contain multiple good arrays let's take that into consideration and count if next good array starts from *j*.

* [D. Lost Arithmetic Progression](https://codeforces.com/problemset/problem/1673/D)
## Intuition
  Here constraints doesn't suggest it'll be a dp problem neither does it feel like one. It will probably be a pure combinatorics problem.
## Solution
  *C* contains the common of arrray *A* and *B*. So, B must contain all the element of *C*. And as it an arithmetic progression so *p* (common difference of *C*) must be a divisor of *r*. Now it is true for the common difference *q* as well. But only the elements in *C* can be common for both *A* and *B*. So, *p* and *q* has to be co-prime of each other. So that *p . q = r* and both of them will only meet at *r*. And now all comes down
when the result will be *-1?* Answer is pretty simple. Element of *B* is set. It has to contain the elements of *C* and can't contain any other element of *A*. So, number of element it can contain with in is pretty much constrained. Only freedom it has is at the front and at the back. We infer that if *c - r < b* then answer will be *-1* as we can have *c - r, c - 2r, ..* any of them as the first element for *B*. But if *c - r >= b* as *p . q = r* or *lcm(p, q) = r* it will meet at c - r which can't happen as it is not at *C*
