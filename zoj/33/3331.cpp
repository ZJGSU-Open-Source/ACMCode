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

const int inf = 100000000;
const int gap = 100;
int main() {
    int t, n;
    int A[110], B[110];
    int DP[110][210];
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i <= n; i ++) {
            for (int j = 0; j <= 200; j ++) {
                DP[i][j] = inf;
            }
        }
        for (int i = 1; i <= n; i ++) {
            scanf("%d %d", &A[i], &B[i]);
        }
        DP[0][100] = 0;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j <= 200; j ++) {
                if (DP[i][j] == inf) {
                    continue;
                }
                if (j >= 100) {
                    DP[i+1][gap+A[i+1]] = min(DP[i+1][gap+A[i+1]], DP[i][j]+A[i+1]);
                    DP[i+1][j-B[i+1]] = min(DP[i+1][j-B[i+1]], DP[i][j]+max(0, B[i+1]-j+gap));
                } else {
                    DP[i+1][A[i+1]+j] = min(DP[i+1][A[i+1]+j], DP[i][j]+max(0, A[i+1]+j-gap));
                    DP[i+1][gap-B[i+1]] = min(DP[i+1][gap-B[i+1]], DP[i][j]+B[i+1]);
                }
            }
        }
        int ans = inf;
        for (int i = 0; i <= 200; i ++) {
            ans = min(ans, DP[n][i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}