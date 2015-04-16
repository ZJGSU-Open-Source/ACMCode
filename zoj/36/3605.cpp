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

struct node {
    int a, b;
}swaps[60];


int change(int a, int idx) {
    if (a == swaps[idx].a) {
        return swaps[idx].b;
    } else if (a == swaps[idx].b) {
        return swaps[idx].a;
    }
    return a;
}

int main() {
    int t;
    int n, m, k, s;
    long long dp[60][60][60];
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d %d", &n, &m, &k, &s);
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= m; i ++) {
            scanf("%d %d", &swaps[i].a, &swaps[i].b);
        }
        dp[0][0][s] = 1;
        for (int i = 1; i <= m; i ++) {
            for (int j = 0; j <= k; j ++) {
                for (int f = 1; f <= n; f ++) {
                    int tmp = change(f, i);
                    if (j > 0){
                        dp[i][j][f] += dp[i-1][j-1][tmp];
                    }
                    dp[i][j][f] += dp[i-1][j][f];
                }
            }
        }
        long long Max = 0;
        int idx = 0;
        for (int i = 1; i <= n; i ++) {
            if (dp[m][k][i] > Max) {
                Max = dp[m][k][i];
                idx = i;
            }
        }
        printf("%d\n", idx);
    }
    return 0;
}