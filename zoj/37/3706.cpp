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

int n, m;

int cal(int a, int b, int c){
    int hash[510];
    memset(hash, 0, sizeof(hash));
    hash[a] = 1;
    hash[b] = 1;
    hash[c] = 1;
    hash[a+b] = 1;
    hash[a+c] = 1;
    hash[b+c] = 1;
    hash[a+b+c] = 1;
    if (a-c > 0) {
        hash[a-c] = 1;
    } else {
        hash[c-a] = 1;
    }
    if (b-c > 0) {
        hash[b-c] = 1;
    } else {
        hash[c-b] = 1;
    }
    if (a-b > 0) {
        hash[a-b] = 1;
    } else {
        hash[b-a] = 1;
    }
    if (a-b-c > 0) {
        hash[a-b-c] = 1;
    }
    if (a+b-c > 0) {
        hash[a+b-c] = 1;
    }
    if (a+c-b > 0) {
        hash[a+c-b] = 1;
    }
    if (b+c-a > 0) {
        hash[b+c-a] = 1;
    }
    if (b-a-c > 0) {
        hash[b-a-c] = 1;
    }
    if (c-a-b > 0) {
        hash[c-a-b] = 1;
    }
    int ans = 0;
    for (int i = 1; i <= n+m; i ++) {
        if (hash[i]) {
            ans ++;
        }
    }
    return ans;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t --) {
        scanf("%d %d", &n, &m);
        int maxx = 0;
        for (int i = 1; i <= n/2; i ++) {
            maxx = max(maxx,cal(i, n-i, m));
        }
        for (int i = 1; i <= m/2; i ++) {
            maxx = max(maxx,cal(i, m-i, n));
        }

        printf("%d\n", maxx);
    }
    return 0;
}
