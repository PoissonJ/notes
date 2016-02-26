#include <stdio.h>

#include "list.h"

#define NUM_TESTS 6

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"

int test_create_node() {
  struct Node* n = create_node(5);
  return (n && n->val == 5);
}

int test_is_ordered() {
  struct Node* a = create_node(1),
    *b = create_node(2),
    *c = create_node(3);

  /* check that an ordered list returns 1 */
  a->next = b;
  b->next = c;

  if(!is_ordered(a)) {
    return 0;
  }

  /* check that an unordered list returns 0 */
  a->next = c;
  c->next = b;
  b->next = NULL;

  if(is_ordered(a)) {
    return 0;
  }

  return 1;

}

int test_insert_first() {
  struct Node* b = create_node(2),
      *c = create_node(3);
  b->next = c;
  c->next = NULL;
  struct Node* a = insert_ordered(b, 1);
  if (!is_ordered(a)) {
      return 0;
  }
  if (a->next->val != b->val) {
      return 0;
  }
  return 1;
}

int test_insert_middle() {
  struct Node* a = create_node(1),
      *c = create_node(3);
  a->next = c;
  c->next = NULL;
  a = insert_ordered(a, 2);
  if (!is_ordered(a)) {
      return 0;
  }
  if (a->next->val != 2) {
      return 0;
  }
  return 1;
}

int test_insert_last() {
  struct Node* a = create_node(1),
      *b = create_node(2);
  a->next = b;
  b->next = NULL;
  a = insert_ordered(a, 3);
  if (!is_ordered(a)) {
      return 0;
  }

  if (b->next->val != 3) {
      return 0;
  }
  return 1;
}

int test_insert_into_empty_list() {
  struct Node* a = NULL;
  a = insert_ordered(a, 1);
  if (a->val != 1) {
      return 0;
  }
  return 1;
}

int main() {
  int passed = 0;
  if(test_create_node()) {
    passed += 1;
    printf(ANSI_COLOR_GREEN "test_create_node()" ANSI_COLOR_RESET "\n");
  } else {
    printf(ANSI_COLOR_RED "test_create_node()" ANSI_COLOR_RESET "\n");
  }

  if(test_is_ordered()) {
    passed += 1;
    printf(ANSI_COLOR_GREEN "test_is_ordered()" ANSI_COLOR_RESET "\n");
  } else {
    printf(ANSI_COLOR_RED "test_is_ordered()" ANSI_COLOR_RESET "\n");
  }

  /* add tests here. You can copy the code that runs test_create_node() */
  if(test_insert_first()) {
    passed += 1;
    printf(ANSI_COLOR_GREEN "test_insert_first()" ANSI_COLOR_RESET "\n");
  } else {
    printf(ANSI_COLOR_RED "test_insert_first()" ANSI_COLOR_RESET "\n");
  }

  if(test_insert_middle()) {
    passed += 1;
    printf(ANSI_COLOR_GREEN "test_insert_middle()" ANSI_COLOR_RESET "\n");
  } else {
    printf(ANSI_COLOR_RED "test_insert_middle()" ANSI_COLOR_RESET "\n");
  }

  if(test_insert_last()) {
    passed += 1;
    printf(ANSI_COLOR_GREEN "test_insert_last()" ANSI_COLOR_RESET "\n");
  } else {
    printf(ANSI_COLOR_RED "test_insert_last()" ANSI_COLOR_RESET "\n");
  }

  if(test_insert_into_empty_list()) {
    passed += 1;
    printf(ANSI_COLOR_GREEN "test_insert_into_empty_list()" ANSI_COLOR_RESET "\n");
  } else {
    printf(ANSI_COLOR_RED "test_insert_into_empty_list()" ANSI_COLOR_RESET "\n");
  }

  /* do not modify this part */
  if(passed == NUM_TESTS) {
    printf(ANSI_COLOR_GREEN "Passed: %d/%d" ANSI_COLOR_RESET "\n", passed, NUM_TESTS);
  } else {
    printf(ANSI_COLOR_RED "Passed: %d/%d" ANSI_COLOR_RESET "\n", passed, NUM_TESTS);
  }

  return 0;
}
