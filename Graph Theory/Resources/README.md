# LCA - Lowest Common Ancestor
## Intuition
This utilizes the strategy of Binary Search. For each vertex we store it's 1<sup>st</sup> parent, 2<sup>nd</sup>, 4<sup>th</sup>.. parent. By this:
```cpp
for(int i = 1; i < lm + 1; i += 1) ancestor[u][1] = ancestor[ancestor[u][i - 1]][i - 1];
```
Then use binary search's tactic. As we have to find the **lowest** common ancestor. We start of from *right = root* and then close in on the *left = u* as long as *right* is also *v's* ancestor. If it isn't then we
increase *left* and then again try to decrease *right*
## History
Let $G$  be a tree. For every query of the form (u, v) we want to find the lowest common ancestor of the nodes u and v, i.e. we want to find a node w that lies on the path from u to the root node, that lies on the path from v to the root node, and if there are multiple nodes we pick the one that is farthest away from the root node. In other words the desired node w is the lowest ancestor of u and v. In particular if u is an ancestor of v, then u is their lowest common ancestor.

The algorithm described in this article will need  
$O(N \log N)$  for preprocessing the tree, and then  $O( \log N)$  for each LCA query.
