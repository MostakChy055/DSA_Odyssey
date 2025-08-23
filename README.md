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
## Hashing Function
Things to consider while building a hash function:
- Avalnache Effect: The avalanche effect is a fundamental property of a good hash function or cryptographic algorithm. It means that a small change in the input (even flipping a single bit) causes a dramatic, seemingly random change in the output (about half of the output bits flip).

Think of it like a real avalanche on a mountainside: a tiny noise (the input change) can trigger a massive, unpredictable shift of snow (the output hash).

### Why is it important?
- Prevents Predictability: If changing one bit in the input only changed one bit in the output, an attacker could easily learn how the function works and find collisions or reverse it.
- Ensures Uniform Distribution: It helps guarantee that hash values are spread evenly across all possible buckets in a hash table, which is crucial for maintaining O(1) average access time.

- Reversible
- Chaos?

```cpp
  struct custom_hash {
      static uint64_t splitmix64(uint64_t x) {
          x += 0x9e3779b97f4a7c15;
          x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
          x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
          return x ^ (x >> 31);
      }
  
      size_t operator()(uint64_t x) const {
          static const uint64_t FIXED_RANDOM = 
              chrono::steady_clock::now().time_since_epoch().count();
          return splitmix64(x + FIXED_RANDOM);
      }
  };
  unordered_map<long long, int, custom_hash> mp;
```
### Reasoning: 
1. The Golden Ratio and its Magic Numbers
```cpp
  x += 0x9e3779b97f4a7c15;
```
This is the most fascinating part. The constant 0x9e3779b97f4a7c15 is an integer approximation of the fractional part of the Golden Ratio, (φ = (1 + √5)/2 ≈ 1.618033...), scaled up to 64 bits.

- Why the Golden Ratio? The Golden Ratio is an irrational number known for its extreme irrationality. This means its continued fraction representation converges slower than any other irrational number. In practical terms, when you use it as a basis for a hash or a random number generator, it helps to maximize dispersion.

- When you add this value to a number, it effectively "scrambles" the starting point. It provides a good, well-distributed initial state for the mixing process that follows. It's like adding a "seed" of chaos to the input.

- This specific constant (0x9e3779b97f4a7c15) is famously used in the "Tiny Encryption Algorithm (TEA)" and its derivatives for the same reason—it provides excellent avalanche properties.

How is it helping here? It ensures that even if the input x is zero or a very small number, the mixing function doesn't start from a weak state. It guarantees the input to the subsequent operations has high entropy.

2. The Mixing Function: splitmix64
Step 1: Initial Scramble
```cpp
  x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
```
- This function is the core engine that thoroughly scrambles the bits of the input. It's a series of XOR-shifts and multiplications by large, odd constants. Each step is designed to avalanche changes in the input bits across the entire 64-bit output.

- x >> 30: Shifts the bits right, bringing the higher-order bits into a position where they can interact with the lower-order bits.

- x ^ (x >> 30): XORs the original number with its shifted version. This is a classic technique to propagate information from higher bits to lower bits. A change in a high bit will affect the result of the XOR at a lower bit position.

-  ... * 0xbf58476d1ce4e5b9: Multiplies the result by a large, odd constant. Multiplication is excellent for diffusion because it combines the bits of the multiplier and the multiplicand in a non-linear way. The constant is chosen to be odd to make the multiplication reversible modulo 2^64 (a bijection), meaning every input maps to a unique output.

Step 2: Further Mixing
```cpp
  x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
```
This is the same pattern as the first step but with different shift and multiplication constants. The shift value (27) is chosen to be different from the first (30) to target different bit interactions. The new large, odd constant continues the non-linear mixing.

3. The Random Seed: Defending Against Attacks
```cpp
  size_t operator()(uint64_t x) const {
      static const uint64_t FIXED_RANDOM =
          chrono::steady_clock::now().time_since_epoch().count();
      return splitmix64(x + FIXED_RANDOM);
  }
```
This is the critical security feature of the hash functor.

The Problem: If an adversary knows the hash function you are using (e.g., the default std::hash), they can precompute a large set of keys that all collide into the same bucket. This is a Denial-of-Service (DoS) attack.

The Solution: The hash function is randomized per program run.

FIXED_RANDOM: This is a static const variable, meaning it is initialized only once when the function is first called and retains its value for the entire program run.

chrono::steady_clock::now().time_since_epoch().count(): This generates a high-resolution timestamp to use as a random seed. It's not cryptographically secure, but it's unpredictable enough for this purpose between different runs of the program.

How it works: By adding this random value to the input x before passing it to splitmix64, the entire hash function is effectively shifted by an unknown offset.

splitmix64(1 + RANDOM_VALUE) will produce a completely different result in one program run versus another.

An attacker cannot predict the hash values their keys will produce, making a hash flooding attack impossible to execute.
2. Why Multiplication by an Odd Constant is Reversible (a Bijection)

This is a subtle but brilliant mathematical trick. Let's break down the statement: "The constant is chosen to be odd to make the multiplication reversible modulo 2^64 (a bijection)."

    Modulo 2^64: We're working with 64-bit integers (uint64_t). When a multiplication result exceeds 64 bits, the extra bits are simply chopped off. We only care about the result within this 64-bit universe. This is arithmetic "modulo 2^64".

    Reversible (Bijection): A function is reversible (bijective) if every possible output value is produced by exactly one input value. There are no collisions within the function itself. If y = f(x), you can always find x given y.

Why does an odd multiplier make it reversible?
The key is that an odd number is coprime with 2^64 (meaning they share no common prime factors). A fundamental theorem in number states that a number has a multiplicative inverse modulo m if and only if it is coprime with m.
Simple Example (using 3-bit numbers, modulo 8):
Let's see what happens when we multiply all possible 3-bit numbers by an odd constant vs. an even constant.

Odd Constant (e.g., 3):
Input (x)	y = (x * 3) mod 8
0	(0 * 3) % 8 = 0
1	(1 * 3) % 8 = 3
2	(2 * 3) % 8 = 6
3	(3 * 3) % 8 = 1
4	(4 * 3) % 8 = 4
5	(5 * 3) % 8 = 7
6	(6 * 3) % 8 = 2
7	(7 * 3) % 8 = 5

Look at the output column: 0, 3, 6, 1, 4, 7, 2, 5. Every number from 0 to 7 appears exactly once! This is a bijection. No collisions. If I give you the output 6, you know the input must have been 2.

Even Constant (e.g., 4):
Input (x)	y = (x * 4) mod 8
0	(0 * 4) % 8 = 0
1	(1 * 4) % 8 = 4
2	(2 * 4) % 8 = 0	COLLISION!
3	(3 * 4) % 8 = 4	COLLISION!
4	(4 * 4) % 8 = 0	COLLISION!
5	(5 * 4) % 8 = 4	COLLISION!
6	(6 * 4) % 8 = 0	COLLISION!
7	(7 * 4) % 8 = 4	COLLISION!

The outputs are only 0 and 4. This is a terrible mixing function—it creates countless collisions immediately.

How this helps in the hash function:
By using an odd multiplier, the mixing step x * constant is guaranteed to not lose information. Every unique internal state x leads to a unique next state. This property helps ensure the overall hash function has a low probability of final collisions.
3. Why Right Shifts? Why 30, 27, and 31?

Why Right Shifts?
You are absolutely right that a left shift would also propagate information! However, right shifts are used for a specific reason: to mix higher-order bits into the lower-order bits.

    The Problem: In a simple multiplication or addition, the lower bits can influence the higher bits (through carries in addition and multiplication), but the higher bits cannot influence the lower bits. Operations on lower bits are "local."

    The Solution: A right shift x >> N brings the high, more significant bits down into the lower, less significant positions. When we then XOR this with the original x (x ^ (x >> N)), we are directly mixing the high bits into the low bits. This is crucial for the avalanche effect—a change in a high bit will now affect the low bits in the next operation (like the multiplication).

Why these specific numbers (30, 27, 31)?
There is both science and art here. The designers of this algorithm (and similar ones like MurmurHash) arrived at these values through extensive testing and analysis.

    They are large, but not too large: Shifting by 60 would only mix 4 bits. Shifting by 16 might not mix enough high bits. Shifts around ~30 mix a good chunk of the high half into the low half.

    They are asymmetric and prime-like: Using different, irregular shift values (30, then 27, then 31) prevents patterns from emerging. If they used 30 every time, the mixing might have blind spots or predictable cycles. Using different values ensures the bits are folded and mixed in non-uniform ways, which is key to creating chaos.

    Empirical Results: Ultimately, these specific values were chosen because they performed well on statistical tests for avalanche and collision when the algorithm was developed. Other good hash functions use similar but different values (e.g., 13, 17, 16). The exact values are often found by trial and error to optimize the avalanche effect.

In summary, the right shifts are used to break the locality of operations by forcing high bits to affect low bits, and the specific values are "magic constants" fine-tuned to create the maximum amount of chaos and diffusion.
