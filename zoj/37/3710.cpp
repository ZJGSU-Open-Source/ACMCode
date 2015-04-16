/*
 Author: sakeven
 */
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <queue>
#include <cstring>
#include <bitset>

using namespace std;

bitset<110>firends[110];

int main() {
    int t;
    int u, v;
    int n, m, k;
    scanf("%d", &t);
    while (t --) {
        scanf("%d %d %d", &n, &m, &k);
        for (int i = 0; i < n; i ++) {
            firends[i].reset();
        }
        for (int i = 0; i < m; i ++) {
            scanf("%d %d", &u, &v);
            firends[u].set(v);
            firends[v].set(u);
        }
        int ans = 0;
        int flag = 1;
        while (flag) {
            flag = 0;
            for (int i = 0; i < n; i ++) {
                for (int j = i+1; j < n; j ++) {
                    if (!firends[i][j]) {
                        if ((firends[i]&firends[j]).count() >= k) {
                            firends[i].set(j);
                            firends[j].set(i);
                            ans ++;
                            flag = 1;
                        }
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}