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

int main(){
    int t, n, m, k;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d", &n, &m, &k);
        if (n == 2|| m == 2) {
            for (int i = 0; i < n; i ++) {
                for (int j = 0; j < m-1; j ++) {
                    printf("0 ");
                }
                printf("0\n");
            }
            continue;
        }
        int row = k/(m-2)+2;
        int col = k%(m-2)+1;
        for (int i = 0; i < row; i ++) {
            for (int i = 0; i < m-1; i ++) {
                printf("0 ");
            }
            printf("0\n");
        }
        if (row == n) {
            continue;
        }
        for (int i = 0; i < col; i ++) {
            if (i == m-1) {
                printf("0\n");
            } else {
                printf("0 ");
            }
        }
        for (int i = col; i < m; i ++) {
            if (i == m-1) {
                printf("1\n");
            } else {
                printf("1 ");
            }
        }
        for (int i = row+1; i < n; i ++) {
            for (int j = 0; j < m-1; j ++) {
                printf("1 ");
            }
            printf("1\n");
        }
    }
    return 0;
}