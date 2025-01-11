# Fermat's theorem

If *m* is a prime number then fermat's theorem dictates that:
```math
a^{m-1} \equiv 1\pmod{m}
```
This is an important formula that can be extended to differnt usecases:
## Usecases

### Congruence Equation
If a given equation is:
``` math
n . a^{n} \equiv b\pmod{p}
```
where p is a prime number.
This equation can be broken down into simpler form using fermat's theorem:
```math
n = i . (p - 1) + j = n . a^{n} \pmod{p}
```
```math
((i . (p - 1) + j) a^{(i . (p - 1) + j)}) \pmod{p}
```

# Related Problems
* [Arpa and a list of numbers](https://codeforces.com/problemset/problem/850/B)
  
  Here we are asked to find array by deleting or increasing elements of the array and resulant array's gcd would be greater than *1*. What does this imply? If *gcd* is *g* then all the element is divisible by *g*. Now if *g = 1* then there can be multiple subarray whoose gcd is greater than *1* and now which subarray to choose? One top of the mind solution can be taking the subarray with more number of elements. But this doesn't ensure optimal answer another solution can be taking the subarray with minimum gcd where *g > 1*. And this too doesn't ensure optimal answer. So what we have to do is go thorugh all the numbers 1 to 1e6 as if they are gcd and then go thrugh the array and make it good. But ofcourse this would be too slow. We can go O(logn) though. Now let's go through a *d* and make the array's gcd equal to *g* or *d*. How to do so? We can take a range *0..d, d..2d,..*.
  In each range say *0..d* we have to make *1..d-1* either equal to *0* or *d* right? First have to count number of elements with in that range right?
```cpp
  for(int i = 0; i < n; i += 1){
    int a; cin >> a; 
    pre[a] += a; cnt[a] += 1;
  }
  for(int i = 1; i < N; i += 1) pre[i] += pre[i - 1], cnt[i] += cnt[i - 1];
```
