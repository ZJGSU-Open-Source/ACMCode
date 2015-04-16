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

const int mod = 1000000007;
const int MAXN = 250;

int main(){
    int t, n, m, q;
    long long x[110][110], B[110][110], CC[110], P[110][110], C[110];
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i ++) {
            scanf("%lld", &C[i]);
            for (int j = 0; j < m; j ++) {
                scanf("%lld", &P[i][j]);
            }
        }
        scanf("%d", &q);
        while (q--) {
            for (int i = 0; i < m; i ++) {
                scanf("%lld", &x[i][1]);
                x[i][0] = 1;
                for (int j = 2; j < MAXN; j ++) {
                    x[i][j] = x[i][j-1]*x[i][1] % mod;
                }
            }
            for (int i = 0; i < n; i ++) {
                B[i][m] = 1;
                for (int j = m-1; j >= 0; j --) {
                    B[i][j] = B[i][j+1] * x[j][P[i][j]] % mod;
                }
            }
            
            for (int i = 0; i < n; i ++) {
                CC[i] = C[i];
            }
            
            for (int i = 0; i < m; i ++) {
                long long sum = 0;
                for (int j = 0; j < n; j ++) {
                    if (P[j][i]) {
                        sum += CC[j] * B[j][i+1] % mod * P[j][i] % mod * x[i][ P[j][i]-1 ]% mod;
                        sum %= mod;
                    }
                    CC[j] = CC[j] * x[i][ P[j][i] ]%mod;    //巧妙的一步
                }
                if (i != m-1) {
                    printf("%lld ", sum);
                } else {
                    printf("%lld\n", sum);
                }
            }
        }
        if (t != 0) {
            printf("\n");
        }
    }
    return 0;
}