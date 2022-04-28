#include "kbn_print_banner.h"

int main()
{
    print_banner();
    int a, b;
    learn_settings(&a, &b);
    printf("a - %d, b - %d\n", a, b);
    return 0;
}