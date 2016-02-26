COP4600 Exercise 5
==================

`list.c` implements a simple linked list storing integers. The
function `insert_ordered` inserts a new element into a list such that
the order of the elements is preserved.

You can assume that the functions `create_node` and `is_ordered` work
correctly.

# Testing

For completeness I implemented 4 tests

## test_insert_first()

Tests inserting an element that belongs in the first position of a 3 element
list. The test will fail if the list is not ordered, or if the first elements
value is not equal to the value that was inserted into the list.

## test_insert_middle()

Tests inserting an element that belongs in the middle of a 3 element list. The
test will fail if the list is not ordered, or if the seconds elements' value is
not equal to the value that was inserted into the list.

## test_insert_last()

Tests inserting an element that belongs at the end of a 3 element list. The
test will fail if the list is not ordered, or if the third elements' value is
not equal to the value that was inserted into the list.

## test_insert_into_empty_list()

Tests inserting an element into a list that is empty. This test addresses the
bug that occurred with insert_ordered. Before, when a user gave a NULL value
for the head of the inserted list, the program would crash. Now the program
will create a 1 element list of the inserted value. The test checks if the
value of the returned node is equal to the inserted value.
