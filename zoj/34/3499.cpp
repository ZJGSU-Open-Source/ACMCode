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
    double elements[510];
    scanf("%d", &t);
    while (t --) {
        scanf("%d", &n);
        for (int i = 0; i < n; i ++) {
            scanf("%lf", &elements[i]);
        }
        sort(elements, elements+n);
        if (n%2 == 0) {
            printf("%.3f\n", (elements[n/2]+elements[n/2-1])/2);
        } else {
            printf("%.3f\n", elements[n/2]);
        }
    }
    return 0;
}