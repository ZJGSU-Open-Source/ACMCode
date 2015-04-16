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
#include <map>
#include <stack>
#include <set>
#include <cmath>
#include <cstring>

using namespace std;

int main() {
    int t, n;
    int price[1010];
    int coming_time[1010];
    int gap[1010];
    double value[1010], total[1010];
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i ++) {
            scanf("%d", &price[i]);
        }
        for (int i = 0; i < n; i ++) {
            scanf("%d", &coming_time[i]);
        }
        coming_time[n] = 1000000;
        gap[0] = coming_time[0];
        total[0] = price[0];
        value[0] = price[0];
        int cnt = 0;
        double Max = 0;
        if (coming_time[1] - coming_time[0]  > coming_time[0])
            Max = value[0];
        for (int i = 1; i < n; i ++) {
            gap[i] = max(gap[i-1],coming_time[i] - coming_time[i-1]);
            total[i] = price[i]+total[i-1];
            value[i] = total[i]/(i+1);
            if (Max < value[i] && gap[i] < coming_time[i+1]-coming_time[i]) {
                cnt = i;
                Max = value[i];
            }
        }
        printf("%.6f %.6f\n", (double)gap[cnt], value[cnt]);
    }
    return 0;
}