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

double dp[510];

int main() {
    int t;
    int n;
    int k1, k2, k3;
    int a, b, c;
    double p[20];
    double A[600], B[600];
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d %d %d %d %d", &n, &k1, &k2, &k3, &a, &b, &c);
        double pa = 1.0/(k1*k2*k3);
        memset(p, 0, sizeof(p));
        for (int i = 1; i <= k1; i ++) {
            for (int j = 1; j <= k2; j ++) {
                for (int s = 1; s <= k3; s ++) {
                    if (i == a && j == b && s == c) {
                        p[0] += pa;
                    } else {
                        p[i+j+s] += pa;
                    }
                }
            }
        }
        int k = k1+k2+k3;
        for (int i = n; i >= 0; i --) {
            A[i] = p[0];
            B[i] = 1;
            for (int j = 1; j <= k; j ++) {
                if (i + j > n) {
                    continue;
                }
                A[i] += A[i+j]*p[j];
                B[i] += B[i+j]*p[j];
            }
        }
        double ans = B[0]/(1-A[0]);
        printf("%.10f\n", ans);
    }
    return 0;
}