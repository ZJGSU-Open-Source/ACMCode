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

struct node {
    int a, b;
    bool operator < (const node & A) const{
        return b < A.b;
    }
};

int main(){
    int t, n, m;
    int dp[260][260];
    scanf("%d", &t);
    while (t --> 0) {
        scanf("%d %d", &n, &m);
        node tree[260];
        for (int i = 1; i <= n; i ++) {
            scanf("%d", &tree[i].a);
        }
        for (int i = 1; i <= n; i ++) {
            scanf("%d", &tree[i].b);
        }
        sort(tree+1, tree+n+1);
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= i; j ++) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-1] + tree[i].a + tree[i].b*(j-1));
            }
        }
        printf("%d\n", dp[n][m]);
    }
    return 0;
}