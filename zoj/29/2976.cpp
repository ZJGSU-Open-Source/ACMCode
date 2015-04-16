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
#include <algorithm>

using namespace std;

int main() {
    int t, n;
    int x, y, z, l;
    double light[210][210];
    
    scanf("%d", &t);
    while (t --> 0) {
        scanf("%d", &n);
        memset(light, 0, sizeof(light));
        for (int i = 0; i < n; i ++) {
            scanf("%d %d %d %d", &x, &y, &z, &l);
            for (int j = -100; j <= 100; j ++) {
                for (int k = -100; k <= 100; k ++) {
                    double r = sqrt((j-x)*(j-x) + (k-y)*(k-y) + z*z);
                    light[j+100][k+100] += l*z / (r*r*r);
                }
            }
        }
        double maxn = -1;
        for (int j = -100; j <= 100; j++) {
            for (int k = -100; k <= 100; k ++) {
                maxn = max(light[j+100][k+100], maxn);
            }
        }
        printf("%.2f\n", maxn);
    }
    return 0;
}