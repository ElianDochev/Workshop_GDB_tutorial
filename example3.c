#include <stdio.h>

struct Flags {
    unsigned int flag1 : 1;
    unsigned int flag2 : 1;
    unsigned int flag3 : 2;
};

union Data {
    int i;
    float f;
    char buffer[8];
};

int main() {
    struct Flags myFlags;

    myFlags.flag1 = 1;
    myFlags.flag2 = 0;
    myFlags.flag3 = 2;

    unsigned int result = myFlags.flag1 << 2; // Shifting left by 2 bits

    printf("Result of faulty bit shifting: %u\n", result);

    union Data data;

    data.i = 10;
    data.f = 220;

    if (data.i == 220) {
        printf("right\n");
    } else {
        printf("wrong\n");
    }
    return 0;
}
