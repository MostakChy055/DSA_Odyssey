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
n = i . (p - 1) + j \n
n . a^{n} \pmod{p} = ((i . (p - 1) + j) a^{(i . (p - 1) + j)}) \pmod{p}
```
