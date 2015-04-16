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

int mat[250][250];

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int ans[250];
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                scanf("%d", &mat[i][j]);
            }
            ans[i] = 1;
        }
        int nxt = 0;
        while (1) {
            if (nxt == n) {
                break;
            }
            int sum = 0;
            for (int j = 0; j < n; j ++) {
                sum += mat[nxt][j] * ans[j];
            }
            if (sum * ans[nxt] < 0) {
                ans[nxt] *= -1; //反置
                nxt = 0;        //重新开始计算
            } else {
                nxt ++;
            }
        }
        printf("Yes\n");
        for (int i = 0; i < n; i ++) {
            if (ans[i] == 1) {
                printf("+\n");
            } else {
                printf("-\n");
            }
        }
    }
    return 0;
}