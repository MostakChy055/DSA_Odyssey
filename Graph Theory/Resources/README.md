# LCA - Lowest Common Ancestor
This utilizes the strategy of Binary Search. For each vertex we store it's 1<sup>st</sup> parent, 2<sup>nd</sup>, 4<sup>th</sup>.. parent. By this:
```cpp
for(int i = 1; i < lm + 1; i += 1) ancestor[u][1] = ancestor[ancestor[u][i - 1]][i - 1];
```
Then use binary search's tactic. As we have to find the **lowest** common ancestor. We start of from *right = root* and then close in on the *left = u* as long as *right* is also *v's* ancestor. If it isn't then we
increase *left* and then again try to decrease *right*
