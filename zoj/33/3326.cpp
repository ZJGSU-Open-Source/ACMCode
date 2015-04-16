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

const int maxn = 800010;

bool is_prime[32];
int mon[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool isprime(int n){
    for (int i = 2; i <= (int)sqrt(n*1.0); i ++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}
void cal_prime(){
    is_prime[0] = is_prime[1] = 0;
    is_prime[2] = 1;
    for (int i = 3; i < 32; i ++) {
        is_prime[i] = isprime(i);
    }
}

bool isleap(int year){
    if (year %400 == 0 ||(year %100 && year % 4 == 0)) {
        return 1;
    }
    return 0;
}

struct node {
    int year, month, day;
    int cnt;
};

node dates[maxn];

void init(){
    int idx = 1;
    dates[0].cnt = 0;
    for (int year = 1000; year <= 2999; year ++) {
        if (isleap(year)) {
            mon[2] += 1;
        }
        for (int month = 1; month <= 12; month ++) {
            for (int day = 1; day <= mon[month]; day ++) {
                dates[idx].year = year;
                dates[idx].month = month;
                dates[idx].day = day;
                dates[idx].cnt = dates[idx-1].cnt + (is_prime[month] && is_prime[day]);
                idx ++;
            }
        }
        if (isleap(year)) {
            mon[2] -= 1;
        }
    }
}

int search(int year, int month, int day){
    int i, idx = (year-1000)*365;
    for (i = idx; i < maxn; i ++) {
        if (dates[i].year == year && dates[i].month == month && dates[i].day == day) {
            break;
        }
    }
    return dates[i].cnt;
}

int main(){
    int  t;
    int y1, y2, m1, m2, d1, d2;
    cal_prime();
    init();
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d", &y1, &m1, &d1);
        scanf("%d %d %d", &y2, &m2, &d2);
        int ans = search(y2, m2, d2) - search(y1, m1, d1) + (is_prime[m1]&&is_prime[d1]);
        printf("%d\n", ans);
    }
    return 0;
}