/*
 Author: sakeven
 */
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>

using namespace std;

struct node{
    double a,b;
}lines[5100];

struct point{
    int index;
    double x;
    point(){}
    point(int index, double x):index(index), x(x){}
};

bool cmp(const node &A, const node &B){
    return A.a < B.a || (A.a == B.a && A.b < B.b);
}

int main(){
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i ++) {
            scanf("%lf%lf", &lines[i].a , &lines[i].b);
        }
        sort(lines, lines+n, cmp);
        int k = 0;
        for (int i = 0; i < n-1; i ++) {
            if (lines[i].a == lines[i+1].a) {
                continue;
            }
            lines[k++] = lines[i];
        }
        lines[k++] = lines[n-1];
        if (k <= 2) {
            printf("%d\n", k);
            continue;
        }
        point p;
        stack<point>st;
        st.push(point(0, 0));
        st.push(point(1, (lines[1].b - lines[0].b)/(lines[0].a - lines[1].a)));
        for (int i = 2; i < k; i ++) {
            double x(0);
            while (st.size() > 1) {
                p = st.top();
                x = (lines[p.index].b - lines[i].b)/(lines[i].a - lines[p.index].a);
                if (x <= p.x) {
                    st.pop();
                    if (st.size() == 1) {
                        x = (lines[0].b - lines[i].b)/(lines[i].a - lines[0].a);
                        break;
                    }
                } else {
                    break;
                }
            }
            st.push(point(i, x));
        }
        printf("%lu\n", st.size());
    }
    return 0;
}