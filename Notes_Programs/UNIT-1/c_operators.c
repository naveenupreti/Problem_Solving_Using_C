/*
===============================================================================
                    C OPERATORS — COMPLETE EXAMPLE
             Expression + Explanation + Expected Output
===============================================================================

This program demonstrates the major operators in C.

The expected output of each expression is written as an INLINE COMMENT.

IMPORTANT:
-----------
C has no separate boolean data type in the traditional/basic sense.
Relational and logical expressions produce an int:

    0       -> false
    1       -> true

Any non-zero value is considered TRUE in a condition.

===============================================================================
*/

#include <stdio.h>


/* Function used to demonstrate the function-call operator (). */
int add(int a, int b)
{
    return a + b;
}


/* Structure used to demonstrate . and -> operators. */
struct Student
{
    int age;
    float marks;
};


int main(void)
{
    /*
    ===========================================================================
    1. ARITHMETIC OPERATORS
    ===========================================================================
    
        +    Addition
        -    Subtraction
        *    Multiplication
        /    Division
        %    Remainder
    */

    int a = 10;
    int b = 3;

    printf("========== ARITHMETIC OPERATORS ==========\n");

    printf("%d\n", a + b);       // 10 + 3 = 13
    printf("%d\n", a - b);       // 10 - 3 = 7
    printf("%d\n", a * b);       // 10 * 3 = 30

    /*
    INTEGER DIVISION:
    
    Both operands are int, so the result is also an integer.

        10 / 3 = 3

    The fractional part .333... is discarded.
    C truncates integer division toward ZERO.
    */

    printf("%d\n", a / b);       // 10 / 3 = 3


    /*
    % gives the remainder.

        10 = (3 * 3) + 1

    Therefore:

        10 % 3 = 1
    */

    printf("%d\n", a % b);       // 10 % 3 = 1


    /*
    ===========================================================================
    2. INTEGER DIVISION WITH NEGATIVE NUMBERS
    ===========================================================================
    
    C truncates integer division toward ZERO.

        -10 / 3  = -3
         10 / -3 = -3
        -10 / -3 =  3

    This is different from Python's floor division.

    Python:
        -10 // 3 = -4

    C:
        -10 / 3 = -3
    */

    printf("%d\n", -10 / 3);      // -10 / 3 = -3
    printf("%d\n", 10 / -3);      // 10 / -3 = -3
    printf("%d\n", -10 / -3);     // -10 / -3 = 3


    /*
    ===========================================================================
    3. REMAINDER WITH NEGATIVE NUMBERS
    ===========================================================================
    
    In C, the remainder has the sign of the DIVIDEND
    (the left-hand operand).

        -10 % 3  = -1
         10 % -3 =  1
        -10 % -3 = -1

    Relationship:

        (a / b) * b + (a % b) = a
    */

    printf("%d\n", -10 % 3);      // -10 % 3 = -1
    printf("%d\n", 10 % -3);      // 10 % -3 = 1
    printf("%d\n", -10 % -3);     // -10 % -3 = -1


    /*
    IMPORTANT:
    
        10 / 0
        10 % 0

    are UNDEFINED BEHAVIOR.

    Never divide by zero.
    */


    /*
    ===========================================================================
    4. FLOATING-POINT DIVISION
    ===========================================================================
    */

    float x = 10.0f;
    float y = 3.0f;

    printf("%.2f\n", x / y);      // 10.0 / 3.0 = 3.33


    /*
    ===========================================================================
    5. UNARY + AND -
    ===========================================================================
    
        +a  -> unary plus
        -a  -> unary minus
    */

    printf("%d\n", +a);           // +10 = 10
    printf("%d\n", -a);           // -10 = -10


    /*
    ===========================================================================
    6. INCREMENT OPERATOR ++
    ===========================================================================
    
        ++i = PRE-INCREMENT
        i++ = POST-INCREMENT
    */

    int n = 5;

    printf("%d\n", ++n);           // ++n: n becomes 6 first; output = 6

    n = 5;

    printf("%d\n", n++);           // n++: old value used first; output = 5
    printf("%d\n", n);             // n after n++ = 6


    /*
    ===========================================================================
    7. DECREMENT OPERATOR --
    ===========================================================================
    */

    n = 5;

    printf("%d\n", --n);           // --n: n becomes 4 first; output = 4

    n = 5;

    printf("%d\n", n--);           // n--: old value used first; output = 5
    printf("%d\n", n);             // n after n-- = 4


    /*
    IMPORTANT SPECIAL CASE:
    
    Avoid expressions such as:

        i = i++ + ++i;

    because modifying the same scalar object multiple times without the
    required sequencing results in undefined behavior.

    Keep ++ and -- operations simple and separate.
    */


    /*
    ===========================================================================
    8. RELATIONAL OPERATORS
    ===========================================================================
    
        <     Less than
        >     Greater than
        <=    Less than or equal
        >=    Greater than or equal
        ==    Equal to
        !=    Not equal to
    
    Result:
        1 = true
        0 = false
    */

    printf("%d\n", 10 < 20);       // 10 < 20 = 1
    printf("%d\n", 10 > 20);       // 10 > 20 = 0
    printf("%d\n", 10 <= 10);      // 10 <= 10 = 1
    printf("%d\n", 10 >= 20);      // 10 >= 20 = 0
    printf("%d\n", 10 == 10);      // 10 == 10 = 1
    printf("%d\n", 10 != 20);      // 10 != 20 = 1


    /*
    VERY IMPORTANT:
    
        =   -> assignment
        ==  -> comparison
    
        x = 5;       // assigns 5 to x
        x == 5;      // checks whether x is 5
    */

    int value = 5;

    printf("%d\n", value == 5);     // value == 5 = 1


    /*
    ===========================================================================
    9. LOGICAL OPERATORS
    ===========================================================================
    
        &&    Logical AND
        ||    Logical OR
        !     Logical NOT
    */

    printf("%d\n", 1 && 1);         // 1 && 1 = 1
    printf("%d\n", 1 && 0);         // 1 && 0 = 0
    printf("%d\n", 0 && 5);         // 0 && 5 = 0

    printf("%d\n", 1 || 1);         // 1 || 1 = 1
    printf("%d\n", 1 || 0);         // 1 || 0 = 1
    printf("%d\n", 0 || 5);         // 0 || 5 = 1
    printf("%d\n", 0 || 0);         // 0 || 0 = 0

    printf("%d\n", !0);              // !0 = 1
    printf("%d\n", !5);              // !5 = 0
    printf("%d\n", !-10);            // !(-10) = 0


    /*
    ===========================================================================
    10. NON-ZERO VALUES ARE TRUE
    ===========================================================================
    
    In C:

        0      -> false
        any non-zero value -> true

    */

    printf("%d\n", 100 && 200);      // 100 && 200 = 1
    printf("%d\n", -5 || 0);         // -5 || 0 = 1
    printf("%d\n", !100);            // !100 = 0


    /*
    ===========================================================================
    11. SHORT-CIRCUIT EVALUATION
    ===========================================================================
    
    For:

        A && B

    If A is FALSE, B is NOT evaluated.

    For:

        A || B

    If A is TRUE, B is NOT evaluated.
    */

    int denominator = 0;

    /*
    denominator != 0 is FALSE.

    Therefore:

        100 / denominator

    is NOT evaluated.

    This prevents division by zero.
    */

    if (denominator != 0 && 100 / denominator > 2)
        printf("Condition is true\n");
    else
        printf("Short-circuit prevented division by zero\n");
    // Output = Short-circuit prevented division by zero


    /*
    ===========================================================================
    12. BITWISE OPERATORS
    ===========================================================================
    
        &    Bitwise AND
        |    Bitwise OR
        ^    Bitwise XOR
        ~    Bitwise NOT
        <<   Left shift
        >>   Right shift
    
    Example:

        5 = 0101
        3 = 0011

        5 & 3 = 0001 = 1
        5 | 3 = 0111 = 7
        5 ^ 3 = 0110 = 6
    */

    int p = 5;
    int q = 3;

    printf("%d\n", p & q);           // 5 & 3 = 1
    printf("%d\n", p | q);           // 5 | 3 = 7
    printf("%d\n", p ^ q);           // 5 ^ 3 = 6


    /*
    BITWISE NOT:
    
        ~5

    flips all bits.

    On the usual two's-complement systems:

        ~5 = -6
    */

    printf("%d\n", ~p);              // ~5 = -6 (on usual two's-complement systems)


    /*
    ===========================================================================
    13. LEFT SHIFT <<
    ===========================================================================
    
        5 = 0101

        5 << 1 = 1010 = 10

    For suitable non-negative values, shifting left by one position
    corresponds to multiplying by 2.
    */

    printf("%d\n", p << 1);           // 5 << 1 = 10


    /*
    ===========================================================================
    14. RIGHT SHIFT >>
    ===========================================================================
    
        5 = 0101

        5 >> 1 = 0010 = 2

    For positive integers this gives 2 here.

    For negative signed integers, the result of right shift is
    implementation-defined in C.
    */

    printf("%d\n", p >> 1);           // 5 >> 1 = 2


    /*
    ===========================================================================
    15. ASSIGNMENT OPERATOR =
    ===========================================================================
    */

    int r;

    r = 20;

    printf("%d\n", r);                // r = 20 -> r contains 20


    /*
    ===========================================================================
    16. COMPOUND ASSIGNMENT OPERATORS
    ===========================================================================
    
        +=
        -=
        *=
        /=
        %=
        &=
        |=
        ^=
        <<=
        >>=
    */

    r = 10;

    r += 5;
    printf("%d\n", r);                // r += 5  -> 15

    r -= 3;
    printf("%d\n", r);                // r -= 3  -> 12

    r *= 2;
    printf("%d\n", r);                // r *= 2  -> 24

    r /= 3;
    printf("%d\n", r);                // r /= 3  -> 8

    r %= 3;
    printf("%d\n", r);                // r %= 3  -> 2


    /*
    BITWISE COMPOUND ASSIGNMENT
    */

    r = 5;

    r &= 3;
    printf("%d\n", r);                // 5 &= 3 -> 1

    r = 5;

    r |= 3;
    printf("%d\n", r);                // 5 |= 3 -> 7

    r = 5;

    r ^= 3;
    printf("%d\n", r);                // 5 ^= 3 -> 6

    r = 5;

    r <<= 1;
    printf("%d\n", r);                // 5 <<= 1 -> 10

    r = 10;

    r >>= 1;
    printf("%d\n", r);                // 10 >>= 1 -> 5


    /*
    ===========================================================================
    17. CONDITIONAL / TERNARY OPERATOR ?:
    ===========================================================================
    
        condition ? expression1 : expression2
    
    If condition is true:
        expression1 is selected.
    
    Otherwise:
        expression2 is selected.
    */

    int marks = 75;

    printf("%s\n", marks >= 40 ? "PASS" : "FAIL");
    // marks >= 40 is true -> output = PASS


    int larger;

    larger = (a > b) ? a : b;

    printf("%d\n", larger);
    // 10 > 3 is true -> larger = 10


    /*
    ===========================================================================
    18. sizeof OPERATOR
    ===========================================================================
    
    sizeof gives the size in bytes of a type or object.

    The exact sizes of most C types depend on the implementation.

    sizeof(char) is always 1.
    */

    printf("%zu\n", sizeof(char));     // sizeof(char) = 1 byte

    printf("%zu\n", sizeof(short));    // sizeof(short) = implementation-dependent
    printf("%zu\n", sizeof(int));      // sizeof(int) = implementation-dependent
    printf("%zu\n", sizeof(long));     // sizeof(long) = implementation-dependent

    printf("%zu\n", sizeof(float));    // sizeof(float) = implementation-dependent
    printf("%zu\n", sizeof(double));   // sizeof(double) = implementation-dependent


    /*
    ===========================================================================
    19. sizeof WITH AN ARRAY
    ===========================================================================
    */

    int arr[5] = {10, 20, 30, 40, 50};

    printf("%zu\n", sizeof(arr));
    // sizeof(arr) = 5 * sizeof(int) bytes

    printf("%zu\n", sizeof(arr) / sizeof(arr[0]));
    // number of elements = 5


    /*
    IMPORTANT SPECIAL CASE:

    sizeof(arr) gives the size of the COMPLETE array.

    In most other expressions, an array is converted to a pointer
    to its first element.

    sizeof is one of the important exceptions to this conversion.
    */


    /*
    ===========================================================================
    20. COMMA OPERATOR ,
    ===========================================================================
    
    The comma operator:

        1. evaluates the left expression
        2. then evaluates the right expression
        3. result = value of the right expression
    */

    int first, second;

    first = 10;

    second = (first += 5, first * 2);

    printf("%d\n", first);
    // first += 5 -> first = 15

    printf("%d\n", second);
    // (15, 15 * 2) -> second = 30


    /*
    Another example:

        (10, 20, 30)

    10 is evaluated.
    20 is evaluated.
    30 is evaluated.

    The value of the entire comma expression is 30.
    */

    printf("%d\n", (10, 20, 30));
    // (10, 20, 30) -> 30


    /*
    IMPORTANT:
    
    The commas separating function arguments are NOT comma operators.

        printf("%d %d", 10, 20);

    Here commas separate function arguments.
    */


    /*
    ===========================================================================
    21. TYPE CAST OPERATOR
    ===========================================================================
    
        (type) expression

    explicitly converts an expression to another type.
    */

    int total = 5;
    int count = 2;

    printf("%d\n", total / count);
    // 5 / 2 = 2  (integer division)

    printf("%.1f\n", (float)total / count);
    // (float)5 / 2 = 2.5


    /*
    Casting does NOT permanently change the declared type of total.

        total

    is still an int.
    */


    /*
    ===========================================================================
    22. ADDRESS-OF OPERATOR &
    ===========================================================================
    
        &variable

    gives the memory address of the variable.
    */

    int number = 100;

    printf("%p\n", (void *)&number);
    // &number = address of number (actual address varies every run)


    /*
    ===========================================================================
    23. POINTER DECLARATION AND DEREFERENCE *
    ===========================================================================
    */

    int *ptr;

    ptr = &number;

    printf("%d\n", *ptr);
    // *ptr = value stored at the address in ptr = 100


    /*
    Change number through the pointer.
    */

    *ptr = 200;

    printf("%d\n", number);
    // *ptr = 200 -> number becomes 200


    /*
    IMPORTANT:
    
        int *ptr;       -> * means pointer declaration

        ptr = &number;  -> & means address-of

        *ptr            -> * means dereference

        a & b           -> & means bitwise AND
    */


    /*
    ===========================================================================
    24. ARRAY SUBSCRIPT OPERATOR []
    ===========================================================================
    */

    printf("%d\n", arr[2]);
    // arr[2] = 30

    printf("%d\n", *(arr + 2));
    // *(arr + 2) = 30

    /*
    IMPORTANT:

        arr[i]

    is equivalent to:

        *(arr + i)
    */


    /*
    ===========================================================================
    25. STRUCTURE MEMBER OPERATOR .
    ===========================================================================
    */

    struct Student s = {20, 85.5f};

    printf("%d\n", s.age);
    // s.age = 20

    printf("%.1f\n", s.marks);
    // s.marks = 85.5


    /*
    ===========================================================================
    26. STRUCTURE POINTER OPERATOR ->
    ===========================================================================
    */

    struct Student *sp = &s;

    printf("%d\n", sp->age);
    // sp->age = 20

    printf("%.1f\n", sp->marks);
    // sp->marks = 85.5


    /*
    IMPORTANT:

        sp->age

    is equivalent to:

        (*sp).age

    */

    printf("%d\n", (*sp).age);
    // (*sp).age = 20


    /*
    ===========================================================================
    27. FUNCTION CALL OPERATOR ()
    ===========================================================================
    */

    printf("%d\n", add(10, 20));
    // add(10, 20) = 30


    /*
    ===========================================================================
    28. OPERATOR PRECEDENCE
    ===========================================================================
    
    Operators have different precedence levels.

        * has higher precedence than +

    Therefore:

        2 + 3 * 4

    is evaluated as:

        2 + (3 * 4)
        = 2 + 12
        = 14
    */

    printf("%d\n", 2 + 3 * 4);
    // 2 + 3 * 4 = 14


    /*
    Parentheses have higher precedence and can change the grouping.
    */

    printf("%d\n", (2 + 3) * 4);
    // (2 + 3) * 4 = 20


    /*
    ===========================================================================
    29. COMBINING RELATIONAL AND LOGICAL OPERATORS
    ===========================================================================
    */

    int age = 25;

    printf("%d\n", age >= 18 && age <= 60);
    // 25 >= 18 && 25 <= 60 = 1


    printf("%d\n", age < 18 || age > 60);
    // 25 < 18 || 25 > 60 = 0


    /*
    ===========================================================================
    30. ASSIGNMENT IS ALSO AN EXPRESSION
    ===========================================================================
    
    Assignment associates from RIGHT to LEFT.

        i = j = 10;

    First:

        j = 10

    Then:

        i = j
    */

    int i, j;

    i = j = 10;

    printf("%d\n", i);
    // i = 10

    printf("%d\n", j);
    // j = 10


    /*
    ===========================================================================
    31. COMMONLY CONFUSED OPERATORS
    ===========================================================================
    
        =       assignment
        ==      equality comparison

        &       bitwise AND
        &&      logical AND

        |       bitwise OR
        ||      logical OR

        !       logical NOT
        ~       bitwise NOT

        ++i     pre-increment
        i++     post-increment

        &x      address of x
        *p      value pointed to by p

        .       structure member
        ->      structure member through pointer
    */


    /*
    ===========================================================================
    32. OPERATOR PRECEDENCE EXAMPLE
    ===========================================================================
    */

    int result;

    result = 10 + 2 * 3;

    printf("%d\n", result);
    // 10 + 2 * 3 = 16
    // First: 2 * 3 = 6
    // Then:  10 + 6 = 16


    result = (10 + 2) * 3;

    printf("%d\n", result);
    // (10 + 2) * 3 = 36


    /*
    ===========================================================================
    33. IMPORTANT UNDEFINED-BEHAVIOR EXAMPLES
    ===========================================================================
    
    NEVER write:

        int x = 10;
        int y = x / 0;      // UNDEFINED BEHAVIOR

        int z = x % 0;      // UNDEFINED BEHAVIOR


    Also avoid:

        i = i++ + ++i;      // UNDEFINED BEHAVIOR

    Do not depend on the order in which such modifications happen.
    */


    /*
    ===========================================================================
    34. IMPORTANT SHIFT RESTRICTIONS
    ===========================================================================
    
    A shift count must be valid for the width of the promoted left operand.

    For example, if int has 32 bits, a shift count of 32 or greater
    is invalid/undefined.

    Also:

        negative shift count

    is undefined behavior.

    Therefore avoid things such as:

        x << -1
        x << 32       // assuming x is a 32-bit int

    */


    /*
    ===========================================================================
    35. COMPLETE OPERATOR SUMMARY
    ===========================================================================

    ARITHMETIC
        +   -   *   /   %

    UNARY
        +   -   ++  --  !   ~

    RELATIONAL
        <   >   <=  >=  ==  !=

    LOGICAL
        &&  ||  !

    BITWISE
        &   |   ^   ~   <<  >>

    ASSIGNMENT
        =   +=  -=  *=  /=  %=
        &=  |=  ^=  <<= >>=

    CONDITIONAL
        ?:

    SPECIAL / OTHER IMPORTANT OPERATORS
        sizeof
        ,
        &
        *
        []
        .
        ->
        ()

    TYPE CAST
        (type)

    ===========================================================================
    */


    printf("\n========== END OF PROGRAM ==========\n");

    return 0;
}