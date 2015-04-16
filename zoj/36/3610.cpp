/*
 Author: sakeven
 */
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int main() {
    int t;
    char b[22], g[22];
    scanf("%d", &t);
    while (t --) {
        scanf("%s %s %*s", b, g);
        printf("%s will survive\n", g);
    }
    return 0;
}