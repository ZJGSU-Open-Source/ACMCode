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

const int MAXN = 1010;
vector<int>edge[MAXN];

vector<vector<int> >path_from_node[MAXN];

bool cmp(const int &a, const int &b) {
    int len = (int)min(path_from_node[a].size(), path_from_node[b].size());
    for (int i = 0; i < len; i ++) {
        if (path_from_node[a][i] != path_from_node[b][i]) {
            return path_from_node[a][i] < path_from_node[b][i];
        }
    }
    return path_from_node[a].size() > path_from_node[b].size();
}

void dfs(int v) {
    if (edge[v].empty()) {
        path_from_node[v].push_back(vector<int>());
        return;
    }
    for (vector<int>::iterator it = edge[v].begin(); it != edge[v].end(); it ++){
        dfs(*it);
    }
    sort(edge[v].begin(), edge[v].end(), cmp);
    int label = 0;
    for (vector<int>::iterator it = edge[v].begin(); it != edge[v].end(); it ++, label ++){
        for (vector<vector<int> >::iterator vit = path_from_node[*it].begin(); vit != path_from_node[*it].end(); vit++) {
            vit->insert(vit->begin(), label);
            path_from_node[v].push_back(*vit);
        }
        path_from_node[*it].clear();
    }
}


int main() {
    int t;
    int n, m;
    int a, b, c;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i <= n; i ++) {
            edge[i].clear();
            path_from_node[i].clear();
        }
        for (int i = 0; i < n-1; i ++) {
            scanf("%d %d", &a, &b);
            edge[a].push_back(b);
        }
        dfs(0);
        vector<vector<int> > &ans = path_from_node[0];
        while (m--) {
            scanf("%d", &c);
            if (c > ans.size()) {
                printf("Out of range.\n");
            } else {
                c --;
                int size = (int)ans[c].size();
                for (int i = 0; i < size; i ++) {
                    if (i != 0) {
                        printf(" ");
                    }
                    printf("%d", ans[c][i]);
                }
                printf("\n");
            }
        }
        printf("\n");
    }
    return 0;
}