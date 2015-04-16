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


int main()
{
    int t;
    double H, h, D, ans;
    cin >> t;
    while (t--) {
        cin >> H >> h >> D;
        ans = H - sqrt( D*(H-h) );
        if (ans > h) {
            ans = h;
        } else if (ans < 0){
            ans = 0;
        }
        printf("%.3f\n", (h-ans)/(H-ans)*D+ans );
    }
    return 0;
}
