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

int main(){
    int n, k, m;
    char key[110][22];
    char keywords[22];
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) {
        scanf("%s", key[i]);
    }
    scanf("%d", &k);
    for (int j = 0; j < k; j++) {
        scanf("%d", &m);
        int ans = 0;
        while (m--) {
            scanf("%s", keywords);
            for (int i = 0; i < n; i++) {
                if (!strcmp(key[i], keywords)) {
                    ans ++;
                    break;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}