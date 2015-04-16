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

using namespace std;

struct node{
    int idx, price;
};

bool cmp(const node &A, const node &B){
    return  A.price > B.price;
}

int main(){
    int t, n, a;
    scanf("%d", &t);
    while (t--) {
        node bidders[110];
        scanf("%d", &n);
        for (int i = 0; i < n; i ++) {
            scanf("%d", &a);
            bidders[i].idx = i+1;
            bidders[i].price = a;
        }
        sort(bidders, bidders+n, cmp);
        printf("%d %d\n", bidders[0].idx, bidders[1].price);
    }
    return 0;
}