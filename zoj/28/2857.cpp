/*
 Author: sakeven
 */
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <queue>
#include <cmath>
#include <cstring>

using namespace std;

int mat[150][150];

int main() {
    int n, m, a, cas = 0;
    while (scanf("%d%d", &n, &m), n+m) {
        memset(mat, 0, sizeof(mat));
        for (int k = 0; k < 3; k ++) {
            for (int i = 0; i < n; i ++) {
                for (int j = 0; j < m; j ++) {
                    scanf("%d", &a);
                    mat[i][j] += a;
                }
            }
        }
        printf("Case %d:\n", ++cas);
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m-1; j ++) {
                printf("%d,", mat[i][j] / 3);
            }
            printf("%d\n", mat[i][m-1] / 3);
        }
    }
    return 0;
}