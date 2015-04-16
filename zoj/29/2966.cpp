/*
 Author: sakeven
 kruskal 最小生成树、并查集
 */
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstring>

using namespace std;

struct node {
    int a, b, k;
};

bool cmp(const node &A, const node &B){
    return A.k < B.k;
}

int root[510];

void init(){
    for (int i = 0; i < 500; i ++) {
        root[i] = i;
    }
}

int find(int x){
    if (root[x] != x) {
        return find(root[x]);
    }
    return x;
}

int mrg(int a, int b){
    int fa = find(a), fb = find(b);
    if (fa == fb) {
        return 0;
    }
    root[fb] = fa;
    return 1;
}

node edge[125000];

int main(){
    int t;
    int n, e;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &e);
        for (int i = 0; i < e; i ++) {
            scanf("%d%d%d", &edge[i].a, &edge[i].b, &edge[i].k);
        }
        sort(edge, edge+e, cmp);
        init();
        int cost = 0;
        for (int i = 0; i < e; i ++) {
            if (mrg(edge[i].a, edge[i].b)) {
                cost += edge[i].k;
            }
        }
        printf("%d\n", cost);
    }
    return 0;
}
