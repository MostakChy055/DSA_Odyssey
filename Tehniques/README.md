# Related Problem
* [A - Inside or Outside](https://atcoder.jp/contests/arc190/tasks/arc190_a)
  ## Intuition
  First it gave me an impression that it might be an implementation problem (which is true but didn't consider that there would be answer constraint) which made me realize that it can be dp as i don't exactly know which one to
  do *operation 1* on and which one to *operation 2*. But let's leave that aside for a while. Another solution can be tree? The thing that made me think this is upon doing *operation 2* we are going through another edge but
  there's a lot of issue with this line of thinkig. Too many children, and no way to connect to two halves of the segment due to *operation 2* and ensure we don't go through with it's original *l..r*. So, this takes us back to
  dp and implmentaion type problem. Let's try implmentation, as dp here would be really painful.
  ## Solution
  Sorting based on other arrays, *l<sub>1</sub> < l<sub>2</sub>..., r<sub>1</sub> > r<sub>2</sub>..*
  ```cpp
  sort(idx.begin(), idx.end(), [&](auto &i, auto &j) -> bool{
        if(l[i] != l[j]) return l[i] < l[j];
        else return r[j] > r[i];
  });
  ```
  These gives us index of the maximum and minimum
  ```cpp
  int i = min_element(r.begin(), r.end()) - r.begin();
  int j = max_element(l.begin(), l.end()) - l.begin();
  ```
  Read the code for range type iterative logic
