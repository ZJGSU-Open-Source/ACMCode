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

char FuWa[] = "BJHYN";

int main() {
    int t;
    char fuwa[260][260];
    
    scanf("%d", &t);
    while (t --> 0) {
        int n, m;
        scanf("%d%d", &m, &n);
        for (int i = 0; i < m; i ++) {
            getchar();
            scanf("%s", fuwa[i]);
        }
        int sum, ans = 0;
        for (int i = 0; i < n; i ++) {
            for (int j = i+1; j < n; j ++) {
                for (int f = 0; f < 5; f ++) {
                    sum = 0;
                    for (int k = 0; k < m; k ++) {
                        if (fuwa[k][i] == fuwa[k][j] && fuwa[k][i] == FuWa[f]) {
                            sum ++;
                        }
                    }
                    ans += sum*(sum-1)/2;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}