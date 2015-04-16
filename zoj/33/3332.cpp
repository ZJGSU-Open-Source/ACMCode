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

vector<int> edge[110];

int visit[110];
int ans[110];
int n;

int dfs(int s, int cnt){
    if (cnt == n) {
        return 1;
    }
    for (int i = 0; i < edge[s].size(); i ++) {
        int u = edge[s][i];
        if (!visit[u]) {
            visit[u] = 1;
            ans[cnt] = u;
            if (dfs(u, cnt+1)){
                return 1;
            }
            visit[u] = 0;
        }
    }
    return 0;
}

int main() {
    int t;
    int a, b;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i ++) {
            edge[i].clear();
        }
        for (int i = 0; i < n*(n-1)/2; i ++) {
            scanf("%d %d", &a, &b);
            edge[a].push_back(b);
        }
        memset(visit, 0, sizeof(visit));
        for (int i = 1; i <= n; i ++) {
            ans[0] = i;
            visit[i] = 1;
            if (dfs(i, 1)) {
                break;
            }
            visit[i] = 0;
        }
        for (int i = 0; i < n-1; i ++) {
            printf("%d ", ans[i]);
        }
        printf("%d\n", ans[n-1]);
    }
    return 0;
}