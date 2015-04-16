/*
 Author: sakeven
 */
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>

using namespace std;

int ga[20010], gb[20010], gc[50000];

bool cmp(const int & a, const int &b){
    return a > b;
}

//二分查找，关键字key，右边界n，左边界默认-1
int b_search(int key, int n){
    int l = -1, r = n, m;
    while (l+1 < r) {
        m = (l+r)/2;
        if (ga[m] < key) {
            l = m;
        } else {
            r = m;
        }
    }
    return r;
}

int main(){
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, cost;
        scanf("%d%d", &n, &cost);
        for (int i = 0; i < n; i ++) {
            scanf("%d", &ga[i]);
            gc[i] = ga[i];
        }
        for (int i = 0; i < n; i ++) {
            scanf("%d", &gb[i]);
            gc[i+n] = gb[i];
        }
        if (n == 1) {
            printf("%d\n", ga[0] - gb[0]);
            continue;
        }
        sort(ga, ga+n);
        sort(gc, gc+2*n);
        sort(gb, gb+n, cmp);
        int maxn = -50000;
        for (int i = 1; i < 2*n; i ++) {
            int ab = b_search(gc[i], n);
            int ba = (2*n - i) - (n - ab);
            int mab = min(ab, ba);
            int fab = abs(ab-ba);
            int c = 2*mab + (fab-1)*fab;
            if (c <= cost) {
                maxn = max(maxn, gc[i]-gc[i-1]);
            }
        }
        if (maxn > 0) {
            printf("%d\n", maxn);
        } else {
            int ans = max(ga[cost/2]-gb[cost/2+1], ga[cost/2+1]-gb[cost/2]);
            printf("%d\n", ans);
        }
    }
    return 0;
}