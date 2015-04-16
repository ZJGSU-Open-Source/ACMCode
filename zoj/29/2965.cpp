/*
 Author: sakeven
 */
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <queue>
#include <cmath>
#include <cstring>

using namespace std;

int main() {
    int t, p;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &p);
        int ans = 0;
        if (p ==1) {
            ans = 7;
        } else if (p == 2) {
            ans = 27;
        } else if (p >= 3 && p <= 10) {
            ans = 70;
        } else if (p == 11) {
            ans = 270;
        } else {
            ans = 700;
        }
        printf("%d\n", ans);
    }
    return 0;
}