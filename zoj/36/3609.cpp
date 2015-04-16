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
#include <map>
#include <stack>
#include <set>
#include <cmath>
#include <cstring>

using namespace std;

int extend_x, extend_y, extend_d;

void extend_Eulid(int n, int m) {
    if (m == 0) {
        extend_x = 1, extend_y = 0, extend_d = n;
    } else {
        extend_Eulid(m, n%m);
        int temp = extend_x;
        extend_x = extend_y;
        extend_y = temp - n/m*extend_y;
    }
}

int gcd(int a, int b) {
    int t;
    while (b) {
        t = b;
        b = a%b;
        a = t;
    }
    return a;
}

int main() {
    int t;
    int a, m;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &a, &m);
        if (gcd(a, m) != 1) {
            printf("Not Exist\n");
        } else {
            extend_Eulid(a, m);
            printf("%d\n", extend_x>0?extend_x:extend_x+m);
        }
    }
    return 0;
}