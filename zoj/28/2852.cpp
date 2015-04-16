/*
 Author: sakeven
DP
利用滚动数组降低空间
 */
#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int getValue(char c){
    if (c >= '2' && c <= '9') {
        return c-'0';
    }
    switch (c) {
        case 'A': return 1;
        case 'T':
        case 'J':
        case 'Q':
        case 'K': return 10;
        case 'F': return 0;
        default:
            return 0;
    }
}

int main(){
    int n;
    char c;
    int dp[2][32][32][32];
    while (scanf("%d", &n), n) {
        memset(dp, -1, sizeof(dp));
        dp[0][0][0][0] = 0;
        int ans = 0;
        for (int i = 0, f = 0, nf; i <= n; i ++, f = nf) {
            if (i < n) {
                cin >> c;
            } else {
                c = 0;
            }
            int v = getValue(c);
            nf = f^1;
            for (int j = 0; j < 31; j ++) {
                for (int k = 0; k < 31; k ++) {
                    for (int g = 0; g < 31; g ++) {
                        if (dp[f][j][k][g] == -1) {
                            continue;
                        }
                        ans = max(ans, dp[f][j][k][g]);
                        if ((v == 0 && j < 21) || j + v == 21) {
                            dp[nf][0][k][g] = max(dp[nf][0][k][g], dp[f][j][k][g] + 150);
                        } else if (j < 21){
                            dp[nf][j+v][k][g] = max(dp[nf][j+v][k][g], dp[f][j][k][g] + 50);
                        }
                        if ((v == 0 && k < 21) || k + v == 21) {
                            dp[nf][j][0][g] = max(dp[nf][j][0][g], dp[f][j][k][g] + 250);
                        } else if (k < 21){
                            dp[nf][j][k+v][g] = max(dp[nf][j][k+v][g], dp[f][j][k][g] + 50);
                        }
                        if ((v == 0 && g < 21) || g + v == 21) {
                            dp[nf][j][k][0] = max(dp[nf][j][k][0], dp[f][j][k][g] + 350);
                        } else if (g < 21){
                            dp[nf][j][k][g+v] = max(dp[nf][j][k][g+v], dp[f][j][k][g] + 50);
                        }
                    }
                }
            }
            memset(dp[f], -1, sizeof(dp[f]));//注意这句的位置
        }
        printf("%d\n", ans);
    }
    return 0;
}