/*
 Author: Sakenven
 */
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>

using namespace std;

const int maxn = 50010;
const int inf = 1000000;
int n, m;
vector<int> edge[maxn];

int dfn[maxn], low[maxn], tim;
stack<int>s;
bool instack[maxn];
int belong[maxn], minId[maxn], num[maxn];
int cnt;

void init(){
    for(int i = 0; i <= n; i++)edge[i].clear();
    while(!s.empty())s.pop();
    memset(instack, 0, sizeof(instack));
    memset(num, 0, sizeof(num));
    memset(low, 0, sizeof(low));
    memset(dfn, 0, sizeof(dfn));
    fill(minId, minId+maxn, inf);
    cnt = tim = 0;
}

void tarjan(int u){
    dfn[u] = low[u] = ++tim;
    s.push(u);
    instack[u] = 1;
    int len = edge[u].size();
    for(int i = 0; i < len; i++){
        int v = edge[u][i];
        if(dfn[v] == 0){
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (instack[v] == 1){
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u]){
        int v;
        cnt ++;
        do {
            v = s.top();s.pop();
            instack[v] = 0;
            
            belong[v] = cnt;//这点缩给哪个新点
            num[cnt]++;//缩了多少点
            minId[cnt] = min(minId[cnt], v);//缩点的最小点标号
        }while(u != v);
    }
}

vector<int> newEdge[maxn];
void build(){
    for(int i = 0; i <= n; i ++)newEdge[i].clear();
    for(int u = 1; u <= n; u++){
        int len = edge[u].size();
        for(int i = 0; i < len; i++){
            int v = edge[u][i];
            if(belong[u] != belong[v]){
                newEdge[belong[u]].push_back(belong[v])    ;
            }
        }
    }
}

int vis[maxn];
int dp[maxn];
int tail[maxn];

void init_new(){
    for(int i = 0; i <= cnt; i++) newEdge[i].clear();
    memset(vis, 0, sizeof(vis));
    memset(dp, 0, sizeof(dp));
}

void dfs(int u){
    vis[u] = 1;
    dp[u] = num[u];
    tail[u] = u;
    int len = newEdge[u].size();
    for(int i = 0; i < len; i++){
        int v = newEdge[u][i];
        if(vis[v] == 0){
            dfs(v);
        }
        if(dp[u] < dp[v]+num[u]){
            dp[u] = dp[v]+num[u];
            tail[u] = tail[v];
        } else if( dp[u] == dp[v]+num[u]){
            if(minId[tail[u]] > minId[tail[v]])
                tail[u] = tail[v];
        }
    }
}

int main(){
    int t;
    int a, b;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &m);
        init();
        
        for(int i = 0; i <m; i++){
            scanf("%d%d", &a, &b);
            edge[a].push_back(b);
        }
        for(int i = 1; i <= n; i++){
            if(dfn[i] == 0){
                tarjan(i);
            }
        }
        int ans = 0;
        init_new();
        build();
        for(int i = 1; i <= cnt; i ++){
            if(vis[i] == 0){
                dfs(i);
            }
        }
        pair<int, int> res = make_pair(inf, inf);
        for(int i = 1; i <= cnt; i ++){
            a = minId[tail[i]], b = minId[i];
            pair<int, int> tmp = make_pair(a, b);
            if(dp[i] > ans){
                ans = dp[i];
                res = tmp;
            } else if( dp[i] == ans ) {
                if ( (tmp < res && res.first != res.second) || tmp.first == tmp.second ){
                    res = tmp;
                }
            }
        }
        if(res.first == res.second) {
            res = make_pair(1, 2);
        }
        printf("%d\n%d %d\n", ans, res.first, res.second);
    }
}
/*
 In:
 5
 5 5
 1 3
 2 3
 4 3
 3 5
 5 4
 
 5 4
 1 3
 2 3
 3 4
 3 5
 
 6 6
 1 3
 2 3
 4 3
 3 5
 5 4
 5 6
 
 6 7
 1 3
 2 3
 4 3
 3 5
 5 4
 5 6
 6 2
 
 2 0
 
 Out:
 4
 3 1
 3
 4 1
 5
 6 1
 6
 2 1
 1
 1 2
 */