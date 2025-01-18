# DSA_Odyssey 
This repository is a collection of DSA based problems that I have solved over the years. 
# Chores
```cpp
  #include<bits/stdc++.h>
  #include <ext/pb_ds/assoc_container.hpp>
  #include <ext/pb_ds/tree_policy.hpp>
  
  #define ll long long
  using namespace std;
  using namespace __gnu_pbds;
  
  template <typename T>
  using ordered_set = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;

  ordered_set<int>os;
  ordered_set<pair<int, int>>os;
```
To store in increasing order
```cpp
  using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
```
Can store any type of dataset.
```cpp
  value = os.find_by_order(position);
```
