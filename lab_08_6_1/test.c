#include <stdio.h>
#include "cdio.h"

int main()
{
    int imax1, imax2 = 0;
    double a[] = { 10, 15, 17 };
    printf("%d", u1(a, a + 2) == 14.0);
    double b[] = { 0, 5, 10 };
    printf("%d", u1(b, b + 2) == 5.0);
    double c[] = { 0, 5, 10, 17 };
    printf("%d", u1(c, c + 3) == 8.0);
    double d[] = { 0, 5.0, 10.0, 17.0 };
    printf("%d", u1(d, d + 3) == 8.0);
    double e[] = { 4, 5.0, 10.0, 17.0 };
    printf("%d", u1(e, e + 3) == 9.0);
    
    find_max_diff(a, a + 2, 10, &imax1, 1);
    printf("%d %d\n", imax1, imax2);
    find_max_diff(b, b + 2, 10, &imax1, 1);
    printf("%d %d\n", imax1, imax2);
    find_max_diff(c, c + 3, 0.0, &imax1, 2);
    printf("%d %d\n", imax1, imax2);
    find_max_diff(d, d + 3, 0.0, &imax1, 2);
    printf("%d %d\n", imax1, imax2);
    find_max_diff(e, e + 3, 14.0, &imax1, 1);
    printf("%d %d\n", imax1, imax2);
    
    delete(a, a + 2, 0);
    output(a, a + 1);
    delete(b, b + 2, 1);
    output(b, b + 1);
    delete(c, c + 2, 0);
    output(c, c + 1);
    delete(d, d + 3, 2);
    output(d, d + 2);
    delete(e, e + 3, 1);
    output(e, e + 2);
    
    insert(a, a + 2, 1, 256.2);
    insert(b, b + 2, 0, 256.2);
    insert(c, c + 3, 2, 256);
    insert(d, d + 3, 0, 0);
    insert(e, e + 3, 1, 256);
    output(a, a + 2);
    output(b, b + 2);
    output(c, c + 3);
    output(d, d + 3);
    output(e, e + 3);
    
    printf("%d", max_arr(a, a + 2) == 256.2);
    printf("%d", max_arr(b, b + 2) == 256.2);
    printf("%d", max_arr(c, c + 3) == 256);
    printf("%d", max_arr(d, d + 3) == 17.0);
    printf("%d", max_arr(e, e + 3) == 256);
    
    move_1(a, a + 2);
    move_1(b, b + 2);
    move_1(c, c + 3);
    move_1(d, d + 3);
    move_1(e, e + 3);
    output(a, a + 2);
    output(b, b + 2);
    output(c, c + 3);
    output(d, d + 3);
    output(e, e + 3);
    
    double a1[4], b1[4], c1[3], d1[11], e1[13];
    input(a1, a1 + 3);
    input(b1, b1 + 3);
    input(c1, c1 + 2);
    input(d1, d1 + 10);
    input(e1, e1 + 12);
    
    return 0;
}
