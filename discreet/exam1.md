# Chapter 1 Proposition Logic

# Sorting and Time Compleity

## Insertion sort

Look at first unsorted element (second card) and place in its correct location
by pulling the other cards out and place the card in its correct spot. This can
take a long time if you need to move many items.

For n cards, we apply this sort n times --- once per card.

Later on the sort we have to move up to n cards to make space --- n/2 on average

## Quick sort (A Faster Method)

Choose the middle element and the place the others around to give the cards an
*approximate* sorted order

For n cards, we apply the overal strategy about log2(n) **base 2** times

No possible "movement penalty" as the cards are only swapped. n/2 swaps are
possible in each step

This method starts taking longer than an insertion sort, but it does not grow as
fast.
