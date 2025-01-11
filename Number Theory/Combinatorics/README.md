# Related Problems
* [D. Yet Another Problem On a Subsequence](https://codeforces.com/contest/1000/problem/D)
  ## Intuition
    Here the constraint suggest we can either use an alogrithm of *O(n<sup>2</sup>) or a *2D*-DP (as this is obviously a combinatorics problem and can't possibly couunt something that we have to do modulous by 998244353)
  ## Solution
    First we are asked to find number of subsequences which contain good subarray. Now each subsequence can contain number of good array and it is tough to count them all in one go right? and that too for each index. So how should we go on about this?
    Let's go through each element in the array. As we know *a<sub>1</sub> = k - 1* and *a<sub>1</sub> > 0*. So, all we have to worry about is the first element. The array has to be of *k = a<aub>1</sub> + 1* length right? Now let's choose
    *a<sub>1</sub> + 1* elements and there isn't any condition on the elements and we can leave elements as well as we can choose sub-sequences. So we can choose *a<sub>1</sub>* number of elements from if *i* is the index of *a<sub>1</sub>* then from *i + 1 + a<sub>1</sub>* to
    *n*. Then say we have chosen till the index *j - 1* now as a subsequence can contain multiple good arrays let's take that into consideration and count if next good array starts from *j*. 
