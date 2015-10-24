#include <stdio.h>
#include <stdlib.h>

int add(int, int);
int mul(int, int);
int power(int, int);
void skip_whitespaces(char*, int*);
int parse_atomic(char*, int*, int*);
int parse_power(char*, int*, int*);
int parse_multiplication(char*, int*, int*);
int parse_addition(char*, int*, int*);

int add(int a, int b) {
  //Implement add here
  return (a + b);
}

int mul(int a, int b) {
  //Implement mul here

  if (a == 1 && b != 1)
      return b;
  if (a != 1 && b == 1)
      return a;
  if (a == 0 || b == 0)
      return 0;
  int answer = 0;
  // Need to add together a, b times
  for (int i = 0; i < b; i++) {
      answer += add(a, 0);
  }
  return answer;
}

int power(int a, int b) {
  //Implement power here

  if (a == 0 && b == 0) {
      return 1;
  }
  if (a == 0 && b != 0) {
      return 0;
  }
  else {
  int answer = 1;
  // Multiply a * a, b times
  for (int i = 0; i < b; i++) {
   answer *= mul(a, 1);
  }
  return answer;
  }
}

void skip_whitespaces(char* expr, int* index) {
  while(expr[*index] == ' ' || expr[*index] == '\t')
    *index += 1;
}

int parse_atomic(char* expr, int* index, int* result) {
  if (expr[*index] == '(') {
    *index += 1;
    skip_whitespaces(expr, index);
    if (parse_addition(expr, index, result))
      return 1;
    skip_whitespaces(expr, index);
    if (expr[*index] == ')') {
      *index += 1;
      skip_whitespaces(expr, index);
      return 0;
    } else {
      return 1;
    }
  } else if (expr[*index] >= '0' && expr[*index] <= '9') {
    *result = 0;
    while(expr[*index] >= '0' && expr[*index] <= '9') {
      *result = *result*10 + expr[*index]-'0';
      *index += 1;
    }
    return 0;
  } else {
    return 1;
  }
}

int parse_power(char* expr, int* index, int* result) {
  if (parse_atomic(expr, index, result))
    return 1;
  skip_whitespaces(expr, index);
  int partial_result;
  switch(expr[*index]) {
    case '\0':
    case ')':
    case '+':
    case '*':
      return 0;
    case '^':
      *index += 1;
      skip_whitespaces(expr, index);
      if (parse_power(expr, index, &partial_result))
        return 1;
      *result = power(*result, partial_result);
      return 0;
    default:
      return 1;
  }
}

int parse_multiplication(char* expr, int* index, int* result) {
  if (parse_power(expr, index, result))
    return 1;
  skip_whitespaces(expr, index);
  int partial_result;
  switch(expr[*index]) {
    case '\0':
    case ')':
    case '+':
      return 0;
    case '*':
      *index += 1;
      skip_whitespaces(expr, index);
      if (parse_multiplication(expr, index, &partial_result))
        return 1;
      *result = mul(*result, partial_result);
      return 0;
    default:
      return 1;
  }
}

int parse_addition(char* expr, int* index, int* result) {
  if (parse_multiplication(expr, index, result))
    return 1;
  skip_whitespaces(expr, index);
  int partial_result;
  switch(expr[*index]) {
    case '\0':
    case ')':
      return 0;
    case '+':
      *index += 1;
      skip_whitespaces(expr, index);
      if (parse_addition(expr, index, &partial_result))
        return 1;
      *result = add(*result, partial_result);
      return 0;
    default:
      return 1;
  }
}

void parse_expression(char* expr) {
  int index = 0;
  int result;
  int i;
  skip_whitespaces(expr, &index);
  if (parse_addition(expr, &index, &result)) {
    for(i=0;i<index;i++)
      printf("_");
    printf("^ Error\n");
  } else {
    for(i=0;i<index;i++)
      printf("%c", expr[i]);
    printf(" = %d\n", result);
  }
}

int main() {
  char* expr;
  int size = 999;
  expr = (char*) malloc(size+1);
  do {
    int read = 0;
    while(read < size-1) {
      scanf("%c", expr+read);
      if (expr[read] == '\n') break;
      read++;
    }
    if(read < 2) break;
    expr[read] = '\0';
    parse_expression(expr);
  } while(1);
  return 0;
}
