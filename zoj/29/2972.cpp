/*
 Author: sakeven
 */
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <string>
#include <iostream>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>

using namespace std;

const int inf = 100000000;

int main(){
    int t, n, m;
    int t1, t2, t3, f1, f2;
    int dp[120][120];
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j <= m; j ++) {
                dp[i][j] = inf;
            }
        }
        scanf("%d%d%d%d%d", &t1, &t2, &t3, &f1, &f2);
        dp[0][m] = min(t2, t3);
        if (m - f1 >= 0) {
            dp[0][m-f1] = t1;
        }
        int s;
        for (int i = 1; i < n; i ++) {
            scanf("%d%d%d%d%d", &t1, &t2, &t3, &f1, &f2);
            for (int j = 0; j <= m; j ++) {
                if (dp[i-1][j] == inf) {
                    continue;
                }
                if (j-f1 >= 0) {
                    dp[i][j-f1] = min(dp[i][j-f1], dp[i-1][j] + t1);
                }
                dp[i][j] = min(dp[i][j], dp[i-1][j]+t2);
                s = j+f2>m?m:j+f2;
                dp[i][s] = min(dp[i][s], dp[i-1][j]+t3);
            }
        }
        int ans = inf;
        for (int j = 0; j <= m; j++) {
            ans = min(ans, dp[n-1][j]);
        }
        printf("%d\n", ans);
    }
    return 0;
}