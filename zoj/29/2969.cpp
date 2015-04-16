/*
 Author: sakeven
 */
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>

using namespace std;

int main(){
    int t, n, a, c[110];
    scanf("%d", &t);
    while (t --) {
        scanf("%d", &n);
        memset(c, 0, sizeof(c));
        for (int i = 0; i <= n; i ++) {
            scanf("%d", &a);
            c[i] = a*(n-i);
        }
        if (n == 0) {
            printf("%d\n", c[0]);
            continue;
        }
        for (int i = 0; i < n-1 ; i ++) {
            printf("%d ", c[i]);
        }
        printf("%d\n", c[n-1]);
    }
    return 0;
}