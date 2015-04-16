/*
 Author: sakeven
 */
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int inf = 100000000;
int bestFriend[110];
int candies[110];
int votes[110];

//按需要candies的数量从小到大排序
bool cmp(const int &a, const int &b){
    return candies[a] < candies[b];
}

int main(){
    int t;
    int n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        memset(votes, 0, sizeof(votes));
        for (int i = 2; i <= n; i ++) {
            scanf("%d", &bestFriend[i]);
            votes[bestFriend[i]]++;//统计每个人的得票数
        }
        for (int i = 2; i <= n; i ++) {
            scanf("%d", &candies[i]);
        }

        int ans = inf;
        for (int exp = votes[1]; exp < n; exp ++) {
            int id[110]={0}, visit[110] = {0};
            int need = 0, get = votes[1];//需要多少糖，得到多少票
            int cnt = 0;
            memset(visit, 0, sizeof(visit));
            for (int j = 2; j <=n; j ++) {
                if (votes[j] >= exp) {//如果j的票比1号期望的还多，那么就让j多出的票分给1号
                    cnt = 0;
                    for (int k = 2; k <= n; k ++) {
                        if (bestFriend[k] == j) {
                            id[cnt++] =k;
                        }
                    }
                    sort(id, id+cnt, cmp);
                    for(int k = 0; k < votes[j] - (exp-1); k++){
                        need += candies[id[k]];
                        visit[id[k]] = 1;
                    }
                    get += votes[j]-(exp-1);
                }
            }
            if (get > exp) {//票拉的太多，不是最优解，继续枚举
                continue;
            }
            //票少了，则需要从别人在拉一些票
            cnt = 0;
            for (int i = 2; i <= n; i ++) {
                if (!visit[i]) {//还没有被拉
                    id[cnt++] = i;
                }
            }
            sort(id, id+cnt, cmp);
            for (int j = 0; j < exp-get; j++) {
                need += candies[id[j]];
            }
            ans = min(ans, need);
        }
        printf("%d\n", ans);
    }
    return 0;
}