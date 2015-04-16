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

int main() {
    int t;
    int p, pa, pb;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d", &p, &pa, &pb);
        if (abs(p-pa) < abs(p-pb)) {
            printf("A\n");
        } else {
            printf("B\n");
        }
    }
    return 0;
}