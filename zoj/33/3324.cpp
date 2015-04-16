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

const int maxn = 20010;

struct action{
    char op;
    int l, r;
}actions[maxn];

int lisan[maxn<<2];//离散化，由于右边界比较大，而数据较小

struct node{
    int l, r;
    int left_depth, right_depth;//左右两侧深度
    int count;                      //深度为0的线段数
    int flag;                       //下压的次数，精妙之处，为0表示没有下压
}tree[maxn<<3];

void build(int idx, int l, int r){
    tree[idx].l = l;
    tree[idx].r = r;
    tree[idx].left_depth = tree[idx].right_depth = 0;
    tree[idx].count = 1;
    tree[idx].flag = 0;
    if (l == r) {
        return;
    }
    int mid = (l+r)/2;
    build(idx<<1, l, mid);
    build(idx<<1|1, mid+1, r);
}

void update(int idx, int l ,int r, int op){
    if (lisan[tree[idx].l] == l && lisan[tree[idx].r] == r) {
        tree[idx].left_depth += op;
        tree[idx].right_depth += op;
        tree[idx].flag += op;
        if (tree[idx].flag > 0) {                          //有下压，那么H-group的个数肯定为0
            tree[idx].count = 0;
        } else if(tree[idx].l == tree[idx].r){          //叶子节点
            tree[idx].count = 1;
        } else {                                                //这里是否可以省略？
            tree[idx].count = tree[idx<<1].count + tree[idx<<1|1].count
            - (tree[idx<<1].right_depth == 0 && tree[idx<<1|1].left_depth == 0);//左右相连
        }
        return;
    }
    int mid = (tree[idx].l+ tree[idx].r)/2;
    if (r <= lisan[mid]) {                    //更新左子树
        update(idx<<1, l, r, op);
    } else if (l > lisan[mid]) {            //更新右子树
        update(idx<<1|1, l, r, op);
    } else {
        update(idx<<1, l, lisan[mid], op);
        update(idx<<1|1, lisan[mid+1], r, op);
    }
    tree[idx].left_depth = tree[idx<<1].left_depth + tree[idx].flag;
    tree[idx].right_depth = tree[idx<<1|1].right_depth + tree[idx].flag;
    if (tree[idx].flag > 0) {
        tree[idx].count = 0;
    } else {
        tree[idx].count = tree[idx<<1].count + tree[idx<<1|1].count
        - (tree[idx<<1].right_depth == 0 && tree[idx<<1|1].left_depth == 0);//左右相连
    }
}

int main(){
    int  t, n, m;
    char op;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; cas++) {
        scanf("%d %d", &n, &m);
        int len  = 0;
        lisan[len++] = 0;
        lisan[len++] = n-1;
        for (int i = 0; i < m; i ++) {
            getchar();
            scanf("%c %d %d", &op, &actions[i].l, &actions[i].r);
            if (op == 'p') {
                actions[i].op = 1;
            } else {
                actions[i].op = -1;
            }
            lisan[len++] = actions[i].l;
            lisan[len++] = actions[i].r;
        }
        sort(lisan, lisan+len);
        len = (int) (unique(lisan, lisan+len)-lisan);
        /*
         离散的时候需要对不连续的相邻两点间加入一个点，这样可以避免这两点变成连续的
         */
        for (int i = 1, cnt = len; i < cnt; i ++) {
            if (lisan[i] != lisan[i-1]+1) {
                lisan[len++] = (lisan[i]+lisan[i-1])/2;
            }
        }
        sort(lisan, lisan+len);
        build(1, 0, len-1);
        printf("Case #%d:\n", cas);
        for (int i = 0; i < m; i ++) {
            update(1, actions[i].l, actions[i].r, actions[i].op);
            printf("%d\n", tree[1].count);
        }
    }
    return 0;
}