/*
 Author: sakeven
 */
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <bitset>

using namespace std;

struct node {
    int a, b;
}trans[510];

bool cmp(const node &A, const node &B) {
    if (A.a == B.a) {
        return A.b < B.b;
    }
    return A.a < B.a;
}
int main() {
    int t;
    int u[510], v[510];
    int n, m;
    scanf("%d", &t);
    while (t --) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < m; i ++) {
            scanf("%d", &u[i]);
        }
        for (int i = 0; i < m; i ++) {
            scanf("%d", &v[i]);
        }
        for (int i = 0; i < m; i ++) {
            trans[i].a = min(u[i], v[i]);
            trans[i].b = max(u[i], v[i]);
        }
        sort(trans, trans+m, cmp);
        int ans = 1;
        for (int i = 1; i < m; i ++) {
            if (trans[i].a != trans[i-1].a || trans[i].b != trans[i-1].b) {
                ans ++;
            }
        }
        printf("%.3f\n", ans*1.0/n);
    }
    return 0;
}