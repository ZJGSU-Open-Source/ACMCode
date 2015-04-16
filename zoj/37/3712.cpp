/*
 Author: sakeven
 */
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int main() {
    int t;
    int a, b, c;
    scanf("%d", &t);
    while (t --) {
        scanf("%d %d %d", &a, &b, &c);
        printf("%d", 300*a*a+100*((a+b)*(a+b) - a*a) + 50*((a+b+c)*(a+b+c)-(a+b)*(a+b)));
        printf(" %d\n", 50*c*c+100*((c+b)*(c+b) - c*c) + 300*((a+b+c)*(a+b+c)-(c+b)*(c+b)));

    }
    return 0;
}