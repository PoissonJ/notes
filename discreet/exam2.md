# Chapter 2

# 2.1 Sets

*Sets vs Lists*

 Set                    List
 ---                    ----
 Unordered              Ordered
 No duplicates          Duplicates Allowed

*Set Examples*

 * `S = {0,1,2,3,4,5} == {0,1,1,1,1,1,1,1,2,3,4,5}`

 * `S = {x: x>0}`

 * `N` (fancy N) refers to the natural numbers `{0,1,2,3,4}

 * *`Z` (fancy Z) refers to all numbers {-2,-1,0,1,2}. You can specify `Z+` to only
   refer to the positive.*

 * *`R` (fancy R) refers to all the real numbers `{x: x is a real number}`*

 * `Q` (fancy Q) refers to all rationals

 * `C` (fancy C) refers to all complex numbers

 ******

**Quick Review**

`A C C`  A is a proper subset of B because the are not equivalent and all of A
is in C. a `C underline` means that A is in C and they might be equlivalent
(not proper).

`|A|` means the magnitude of the set. A.K.A the size. Or *Cardinality*

# 2.2 Comparing Sets

Venn-diagrams can be used to represent sets.

The intersection of the venn diagram is the intersection of the sets denoted as
`A n B`.

`A n B  =  {x|x e A ^ x e B}`. The intersection of A and B such that x is in A
and B

`A U B`:
  : A union B =  `{x|x e A v x e B}`. Notice the "or" difference here. There
  could be the case that A and B are not intersecting at all.

`Bar over A`:
  : "Everything not in A"

To capture only B even though A and B intersect... `B-A = {x|x !e A ^ x e B}.

 ******

`Bar over AUE` === `Bar over A n Bar over B`

`Bar over AnE` === `Bar over A U Bar over B`

 ******

`A = {-2,-1,0,1,2}`

`B = {-1,0,1}`

*We can say*

 * `A n !B` = -2, 2
 * `!A U B` = all `x e z, z != -2, 2`

# 2.3 Functions

`f(x) = 3x^2 - 5x + 1`

`f: R -> R` this function maps values from the reals to the reals

 ******

One to one function:
  : For all x and y `x != y -> f(x) != f(y)`

Onto:
  : For all b in the domain with `f: a -> b`, there exists `f(a) = b` (All
    right side if covered)

*A function's inverse only exists if there is a one to one and onto*

 ******
`f: A -> B`

`g: B -> C`

Therefore...

`f o g: A -> C` or `f(g(a)) = C`

 ******

`x e R`

`|-x-|: R -> Z === ceil(x)`
`|_x_|: R -> Z === floor(x)`
