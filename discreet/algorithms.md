# Algorithms

# 3.1 Intro to Algorithms

Algorithms:
  : Series of code to complete tasks.

 * Exists to accomplish some sort of goal and sub goals to complete a program
 * Definite, must be able to define
 * Correctness: results are to be 100% correct
 * Finite
 * Effective
 * Generality

Heuristic:
  : Algorithm that is not guaranteed to be correct.

*Sorting Out Sorting video*

Greedy algorithm:
  : algorithms that try to take what looks to be the next step that looks the
    best toward the completion.

A good greedy algorithm is when making change. We try to give the least amount
of change as possible.

# 3.2

Big-o:
  : Consider `f(x) = O(g(x))` "big-oh" if, x>n `f(x)<= g(x)`. In other words, g(x)
    will always be the *upper bound* of f(x) until x>n

Big-omega:
  : `f(x) is BigOm(g(x))` if x>n, f(x) >= C(g(x)). All about the *lower bound*

Big-theta:
  : `f(x) is BigTheta(g(x))` if `f(x) <--> both big-o and big-om g(x)`. All about the *lower bound*

 ******

| f1(x), f2(x)
| Each function has its own O(g(x))
| f1(x)+f2(x) = O(max(g1,g2))

| f1(x), f2(x)
| Each function has its own O(g(x))
| f1(x) * f2(x) = O( g1(x) * g2(x) )

# 3.2 / 8.3

Review

`f(n) is O(g(n)) if abs(f(n)) <= C abs(g(n))`

A for loop `(for i=0; i< a; i ++)` runs at `O(n)`

 ******

Greedy:
  : Try to make progress toward the solution in each step

Brute-force algorithm:
  : Efficency & resources be damned, try everything. After trying all possible
    solutions, determine the best one. **Try EVERYTHING**. This can sometimes
    be very inefficent

Different kinds of orders in order of increasing time:

 * O(1): Exact same time for all number of items
 * O(log n)
 * O(x^P) for any power greater than 0
 * O(x!)
 * O(x^x)

 ******

## 8.3

Using recursion

 * `T(N)`
 * `2T(N/2) + O(N^d)`

`T(N) = aT(N/b) + O(N^d log^c(N)`

 * a: subproblems
 * b: size ratio for sub problems
 * d: the division step
 * c: division steps log component growth

**Look at Masters Theorm!**
