/*
 Author: sakeven
 */
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int main() {
    int t;
    int n, m;
    int java[500];
    scanf("%d", &t);
    while (t --) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i ++) {
            scanf("%d", &java[i]);
            java[i+n] = java[i];
        }
        int maxx = 0, sum = 0;
        for (int j = 0; j < m; j ++) {
            sum += java[j];
        }
        maxx = sum;
        for (int i = m; i < 2*n; i ++) {
            sum = sum - java[i-m]+java[i];
            maxx = max(maxx, sum);
        }
        printf("%d\n", maxx);
    }
    return 0;
}