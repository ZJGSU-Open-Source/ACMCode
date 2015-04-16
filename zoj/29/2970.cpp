/*
 Author: sakeven
 */
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>

using namespace std;

int main(){
    int t, n, a;
    char str[10];
    scanf("%d", &t);
    while (t --) {
        scanf("%s", str);
        scanf("%d", &n);
        int minn = 2008, maxn = 0;
        for (int i = 0; i < n; i ++) {
            scanf("%d", &a);
            minn = min(a, minn);
            maxn = max(a, maxn);
        }
        if (!strcmp(str, "Faster")){
            printf("%d\n", minn);
        } else {
            printf("%d\n", maxn);
        }
    }
    return 0;
}