/*
 Author: sakeven
 */
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <string>
#include <iostream>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;


struct node{
    int a, b, c;
};

bool cmp(const node &A, const node &B){
    if (A.c == B.c) {
        if (A.a == B.a) {
            return A.b < B.b;
        }
        return A.a < B.a;
    }
    return A.c < B.c;
}

int root[110];

void init(){
    for (int i = 0; i < 110; i ++) {
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
    if (fa != fb) {
        root[fb] = fa;
        return 1;
    }
    return 0;
}


int main(){
    int t, n, c;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        node edge[5010];
        int k = 0;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                scanf("%d", &c);
                if (i < j && c != 0) {
                    edge[k].c = c;
                    edge[k].a = i+1;
                    edge[k].b = j+1;
                    k++;
                }
            }
        }
        sort(edge, edge+k, cmp);
        node res[110];
        int cnt = 0;
        init();
        for (int i = 0; i < k; i ++) {
            if (mrg(edge[i].a, edge[i].b)) {
                res[cnt].a = edge[i].a;
                res[cnt].b = edge[i].b;
                res[cnt].c = 0;
                cnt ++;
            }
        }
        if (cnt != n-1) {
            printf("-1\n");
            continue;
        }
        sort(res, res+cnt, cmp);
        for (int i = 0; i < cnt-1; i ++) {
            printf("%d %d ", res[i].a, res[i].b);
        }
        printf("%d %d\n", res[cnt-1].a, res[cnt-1].b);
    }
    return 0;
}
