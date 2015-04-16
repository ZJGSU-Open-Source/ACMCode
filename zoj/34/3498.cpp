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
    scanf("%d", &t);
    while (t --) {
        scanf("%d", &n);
        int ans = 0;
        while (n) {
            ans ++;
            n= n/2;
        }
        printf("%d\n", ans);
    }
    return 0;
}