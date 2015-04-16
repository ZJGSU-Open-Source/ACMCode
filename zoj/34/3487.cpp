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

void suffix(long long n){
    int last = n%10;
    int tens = n/10%10;
    if (tens == 1) {
        printf("th\n");
    } else {
        if (last == 1) {
            printf("st\n");
        } else if (last == 2) {
            printf("nd\n");
        } else if (last == 3) {
            printf("rd\n");
        } else {
            printf("th\n");
        }
    }
}

int main() {
    int t;
    long long n;
    scanf("%d", &t);
    while (t--) {
        scanf("%lld", &n);
        printf("%lld", n);
        suffix(n);
    }
    return 0;
}