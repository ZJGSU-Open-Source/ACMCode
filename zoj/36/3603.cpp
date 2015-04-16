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
    int t;
    int n;
    int cnt[30], ans[30];
    char letters[20];
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        fill(ans, ans+30, 30);
        for (int i = 0; i < n; i ++) {
            scanf("%s",letters);
            memset(cnt, 0, sizeof(cnt));
            for (int i = 0; i < 12; i ++) {
                cnt[letters[i]-'A']++;
            }
            for (int i = 0; i < 26; i ++) {
                ans[i] = min(cnt[i], ans[i]);
            }
        }
        for (int i = 0; i < 26; i ++) {
            for (int j = 0; j < ans[i]; j ++) {
                printf("%c", 'A'+i);
            }
        }
        printf("\n");
    }
    return 0;
}