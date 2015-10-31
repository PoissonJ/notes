// Chapter 7
short float is not legal

printf(c) is illegal if c is a char

int -> unsigned int -> long int -> unsigned long int

float -> double -> long double

if converting from float to int, you may have an issue if the int cannot hold
the value of the float

// Scrabble letter calculator
while (letter != '\n') {
    scanf("%c", & letter);
    letter = toupper(letter);
    switch...
}

// Chapter 8
To use a digit in character form for array subscript, do a['1'-'0'] for example

When declaring arrays a[3] = {1} gives [1,0,0]

// Chapter 9
void function(double) is valid!!!! WTF

// Chapter 10
void f() {
    static int i = 0;
    i++;
    printf("%d", i);
}
Declaring the static int will only declare itself once
