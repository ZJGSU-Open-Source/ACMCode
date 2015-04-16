/*
 Author: sakeven
 */
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>

using namespace std;

int main(){
    int t, n;
    int structure[110], out[110];
    scanf("%d", &t);
    while (t --> 0) {
        scanf("%d", &n);
        for (int i = 0; i < n; i ++) {
            scanf("%d", &structure[i]);
        }
        for (int i = 0; i < n; i ++) {
            scanf("%d", &out[i]);
        }
        bool is_queue = true, is_stack = true;
        for (int i = 0; i < n; i ++) {
            if (structure[i] != out[i]) {
                is_queue = false;
            }
            if (structure[n-i-1] != out[i]) {
                is_stack = false;
            }
        }
        if (is_queue && !is_stack) {
            printf("queue\n");
        } else if ( !is_queue && is_stack) {
            printf("stack\n");
        } else if ( is_queue && is_stack) {
            printf("both\n");
        } else {
            printf("neither\n");
        }
    }
    return 0;
}