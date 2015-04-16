/*
 Author: sakeven
 */
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <string>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>

using namespace std;


int main() {
    int t;
    double a, b, c, d, e, f;
    scanf("%d", &t);
    while (t--) {
        scanf("%lf %lf %lf %lf %lf %lf", &a, &b, &c, &d, &e, &f);
        if (a == c) {
            printf("circle\n");
        } else if (a != c && a*c > 0) {
            printf("ellipse\n");
        } else if (a == 0 || c == 0) {
            printf("parabola\n");
        } else if (a*c < 0){
            printf("hyperbola\n");
        }
    }
    return 0;
}