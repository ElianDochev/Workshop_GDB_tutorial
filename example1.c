#include <stdio.h>
#include <stdlib.h>

int increment(void) {
    static int x;
    return x++;
}

void func_1();

void func_3() {
    printf("func_3\n");
    func_1();
}

void func_2() {
    printf("func_2\n");
    func_3();
}


void func_1() {
    printf("func_1\n");
    func_2();
}


int main() {
    char *str = "Hello, GDB!";
    str[0] = 'h';

    char *str_two;
    str[0] = 'h';

    char *str_three = malloc(8);
    str_three[8] = 'h';


    int i, sum = 0;
    for (i = 0; i < 10; ++i) {
        sum += i;
    } // sum should from 1 to 10
    printf("Sum of numbers from 1 to 10: %d\n", sum);

    int result = increment();
    printf("result: %d\n", result);

    int uninitialized_var;
    if (uninitialized_var == 0) {
        printf("uninitialized_var is 0\n");
    } else {
        printf("uninitialized_var is not 0\n");
    }

    func_1();

    void (*funcPtr)();
    funcPtr = (void (*)())0xDEADBEEF;
    funcPtr();

    return 0;
}