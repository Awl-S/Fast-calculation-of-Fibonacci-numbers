#include <iostream>
using namespace std;

unsigned long long fibonachi(unsigned long long n)
{
    if (n < 2)
        return n;
    unsigned long long mask = 1, m = n;
    while (m > 1) {
        m >>= 1;
        mask <<= 1;
    }
    unsigned long long fn = 1, fn1 = 1, gn, gn1;
    while (mask > 1) {
        mask >>= 1;
        gn = fn;
        gn1 = fn1;
        if (n & mask) {
            fn = gn1 * gn1 + gn * gn;
            fn1 = gn1 * gn1 + 2 * gn * gn1;
        }
        else {
            fn = 2 * gn * gn1 - gn * gn;
            fn1 = gn1 * gn1 + gn * gn;
        }
    }
    return fn;
}

int main()
{
    for (int i = 0; i < 100; i++)
        cout <<i << "\t" << fibonachi(i) << "\n ";
    return 0;
}
