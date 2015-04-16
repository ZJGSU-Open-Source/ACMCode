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

int origin(int distance, int waiting_time) {
    double ans = 0;
    if (distance <= 3) {
        ans = 10 + waiting_time/5.0*2 + 1;
    } else if (distance <= 10) {
        ans =  10 + (distance-3)*2 + waiting_time/5.0*2 + 1;
    } else {
        ans = 24 + (distance-10)*3 + waiting_time/5.0*2 + 1;
    }
    return (int)(ans + 0.5);
}

int now(int distance, int waiting_time) {
    double ans = 0;
    if (distance <= 3) {
        ans = 11 + waiting_time/4.0*2.5;
    } else if (distance <= 10) {
        ans = 11 + (distance-3)*2.5 + waiting_time/4.0*2.5;
    } else {
        ans = 28.5 + (distance-10)*3.75 + waiting_time/4.0*2.5;
    }
    return (int)(ans + 0.5);
}

int main() {
    int t, distance, waiting_time;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &distance, &waiting_time);
        printf("%d\n", now(distance, waiting_time)-origin(distance, waiting_time));
    }
    return 0;
}