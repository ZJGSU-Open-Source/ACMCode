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

using namespace std;

int pc[510][510];
int n, m;
struct virus{
    int x, y;
    int t, d;
    virus(){}
    virus(int _x, int _y,int _t):x(_x), y(_y), t(_t), d(0){}
    bool operator < (const virus &A) const{
        if (d != A.d){
            return d > A.d;
        }
        return t > A.t;
    }
};

bool check(int x, int y){
    return (x >= 0 && x < n)&&(y >= 0 && y < m)&& pc[x][y] > 0;
}

priority_queue<virus> q;

int tp[250000];
const int inf = 10000000;
int dirt[][2] = {{-1,0}, {0, -1}, {1, 0}, {0, 1}};
void bfs(){
    while(!q.empty()){
        virus cur = q.top();
        q.pop();
        int d = inf;
        for(int i = 0; i < 4; i ++){
            int _x = cur.x+dirt[i][0], _y = cur.y+dirt[i][1];
            if(check(_x, _y)) {
                if(pc[_x][_y] <= cur.d){
                    pc[_x][_y] = 0;
                    tp[cur.t] ++;
                    q.push(virus(_x, _y, cur.t));
                } else { //有防御力比其传染力强的，取防御力最弱值
                    d = min(pc[_x][_y], d);
                }
            }
        }
        if( d != inf){//此时病毒必须等到传染力大于附近最弱防御力才能继续传播
            cur.d = d;
            q.push(cur);
        }
    }
}

int main(){
    int a;
    while (scanf("%d %d", &n, &m) != EOF) {
        while(!q.empty())q.pop();
        memset(pc, 0, sizeof(pc));
        memset(tp, 0, sizeof(tp));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                scanf("%d", &a);
                if(a > 0){
                    q.push(virus(i, j, a));
                    tp[a] ++;
                } else {
                    pc[i][j] = -a;
                }
            }
        }
        bfs();
        int q;
        scanf("%d", &q);
        for(int i = 0; i < q; i++){
            scanf("%d", &a);
            printf("%d\n", tp[a]);
        }
    }
    return 0;
}