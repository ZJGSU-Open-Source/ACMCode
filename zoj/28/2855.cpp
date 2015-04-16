/*
 Author: sakeven
 */
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <queue>
#include <cmath>
#include <cstring>

using namespace std;

const double pi = acos(-1);

int main() {
    double longitude, latitude;
    int level;
    char s[100];
    
    while (scanf("%lf %lf %d", &longitude, &latitude, &level) != EOF) {
        double x = longitude * pi / 180;
        double y = log(tan(pi/4 + (latitude*pi/180)/2));
        double x1 = -pi;
        double x2 = pi;
        double y1 = log(tan(pi/4 + (-85*pi/180)/2));
        double y2 = log(tan(pi/4 + (85*pi/180)/2));
        s[0] = 't';
        for (int i = 1; i <= level; i ++) {
            if ( x - x1 < x2 - x) {
                x2 = (x1+x2)/2;
                s[i] = 'q';
            } else {
                x1 = (x1+x2)/2;
                s[i] = 'r';
            }
            
            if (y - y1 < y2 - y) {
                y2 = (y1+y2)/2;
                if (s[i] == 'q') {
                    s[i] = 't';
                } else {
                    s[i] = 's';
                }
            } else {
                y1 = (y1+y2)/2;
            }
        }
        s[level+1] = 0;
        printf("%s\n", s);
    }
    return 0;
}