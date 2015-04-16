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

int main(){
    int t, n;
    char names[110][22];
    char first[22];
    scanf("%d", &t);
    while (t --) {
        scanf("%d %s", &n, first);
        int idx = 0;
        for (int i = 0; i < n; i ++) {
            scanf("%s", names[i]);
            if (!strcmp(names[i], first)) {
                idx = i;
            }
        }
        int ans = (idx + n/2)%n;
        printf("%s\n", names[ans]);
    }
    return 0;
}