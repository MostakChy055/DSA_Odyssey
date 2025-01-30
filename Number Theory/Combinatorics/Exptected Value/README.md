# Expected Values: A Beginner's Guide

This guide explains the concept of expected values, how to calculate them, their applications in real-world scenarios and some related problems.

## What is Expected Value?

The **expected value** is a fundamental concept in probability and statistics. It represents the average outcome of a random event if the experiment is repeated many times. Mathematically, it is calculated as:

```math

E = \sum_{i=1}^{n} (p_i \cdot x_i)
```
Where:
- p<sub>i</sub> is the probability of outcome x<sub>i</sub>,
- x<sub>i</sub> is the value of the outcome.


## Calculating Expected Value

### Example 1: Rolling a Fair Die
When rolling a fair six-sided die, the expected value is:

```math
E = \frac{1}{6}(1) + \frac{1}{6}(2) + \frac{1}{6}(3) + \frac{1}{6}(4) + \frac{1}{6}(5) + \frac{1}{6}(6) = 3.5
```

### Example 2: Weighted Vertices in a Graph
If you have a graph with vertices of different weights, and you select a vertex uniformly at random, the expected weight is:

```math
E = \frac{\sum_{i=1}^{n} w_i}{n}
```

Where:
- w<sup>i</sup> is the weight of the *i*<sup>th</sup> vertex,
- *n* is the total number of vertices.

## Key Properties of Expected Value

1. **Linearity of Expectation**:
   - For any random variables *X* and *Y*:
     ```math
     E[X + Y] = E[X] + E[Y]
     ```
   - This holds even if *X* and *Y* are not independent!

2. **Applications in Real Life**:
   - Expected value is used in insurance, finance, and decision-making. For example, insurance companies calculate premiums based on the likelihood of certain events.

3. **Expected Value in Games**:
   - In games of chance, the expected value determines whether a game is fair or biased. For instance, most casino games have a negative expected value for the player.

4. **Expected Value and Variance**:
   - Variance measures how spread out the outcomes are. A high variance means outcomes can differ significantly from the expected value.

## Example: Marbles in a Bag

Suppose you have a bag of marbles with the following weights and probabilities:
- 2 red marbles, each with weight 3 probability =
  ```math
  ( \frac{2}{5} )
  ```
- 3 blue marbles, each with weight 5 probability =
  ```math
  \frac{3}{5}
  ```

The expected value of the weight of a randomly selected marble is:

```math
E = \left(\frac{2}{5} \times 3\right) + \left(\frac{3}{5} \times 5\right) = \frac{6}{5} + \frac{15}{5} = \frac{21}{5} = 4.2
```

## References

- [Probability and Statistics](https://en.wikipedia.org/wiki/Probability)
- [Expected Value in Decision-Making](https://en.wikipedia.org/wiki/Expected_value)

# Related Problems
- [D. New Year Santa Network](https://codeforces.com/problemset/problem/500/D)


  **Intuition:** In this problem we were asked to find the expected value. So, what we have to do is find all possible values. And as we are asked to find expected values so we have to divide it by it's probability of being
  chosen. If have to find *3* such warehouses. So, the possibilty of that is:
  ```math
  \binom{n}{3}
  ```
  - but the warehouses can be unordered. So the actual probabilty is *n (for the first one) * (n - 1) (all except the first one) * (n - 2) (all except the second and first one)*. Now one more thing, we are asked to find all
  possible values for *d(x<sub>1</sub>, x<sub>2</sub>), d(x<sub>1</sub>, x<sub>3</sub>), d(x<sub>2</sub>, x<sub>3</sub>)* The issue here is at one point in time we can calculate only one value. Luckily the formula here is of
  addition so, we can consider them individually. Or we can look at it differently first fix one vertex then select another one. Say these two vertices are *x<sub>1</sub>, x<sub>2</sub>*, now we have *d(x<sub>1</sub>, x<sub>2</sub>)*
  if we choose another one from *x<sub>2</sub>* then we also have *d(x<sub>2</sub>, x<sub>3</sub>)*. We can do this individually. If we do this our job is done. As we can have *d(x<sub1></sub>, x<sub>3</sub>)* from what we already have.
  ---
  **Solution:** We can just calculate *d(x<sub>2</sub>, x<sub>3</sub>)* or in other words each edge independently as first of the formula is additive and second of all they alll are of same structure. The question is for each edge
  how many triplets can be formed? What is the contribution? If the connects subtree *A* and subtree *B*. Then isn't the contribution just sizeof*(A) . *sizeof*(B) *?
  
