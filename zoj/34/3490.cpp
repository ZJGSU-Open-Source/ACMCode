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

bool is_upper(char c) {
    return c >= 'A' && c <= 'Z';
}

bool is_lower(char c) {
    return c >= 'a' && c <= 'z';
}

bool is_alpha(char c){
    return is_upper(c) || is_lower(c);
}

bool is_digit(char c) {
    return c >= '0' && c <= '9';
}

enum char_case{
    lower, upper, digit,none
};
enum char_case leftmost = none;

int increase(char &c){
    if (is_lower(c)) {
        leftmost = lower;
        if (c == 'z') {
            c = 'a';
            return 1;
        } else {
            c += 1;
            return 0;
        }
    } else if (is_upper(c)) {
        leftmost = upper;
        if (c == 'Z') {
            c = 'A';
            return 1;
        } else {
            c += 1;
            return 0;
        }
    } else if (is_digit(c)) {
        leftmost = digit;
        if (c == '9') {
            c = '0';
            return 1;
        } else {
            c += 1;
            return 0;
        }
    }
    return 0;
}

bool contain_aphal_digit(char *s){
    while (*s) {
        if (is_digit(*s) || is_alpha(*s)) {
            return true;
        }
        s ++;
    }
    return false;
}

void process(char *s){
    char *p = s;
    while (*p) {
        p ++;
    }

    if (!contain_aphal_digit(s)) {
        p--;
        (*p) ++;
    } else {
        int flag = 1;
        char *f = p, *pos = NULL;
        while (p != s-1) {
            if (flag && (is_alpha(*p) || is_digit(*p))) {
                flag = increase(*p);
                pos = p;
            }
            p--;
        }
        if (flag == 1) {
            *(f+2) = 0;
            while (f != pos-1) {
                *(f+1) = *f;
                f--;
            }
            f ++;
            switch (leftmost) {
                case upper:
                    *f = 'A';
                    break;
                case lower:
                    *f = 'a';
                    break;
                case digit:
                    *f = '1';
                default:
                    break;
            }
        }
    }
}

int main() {
    int t, n;
    char s[210];
    scanf("%d", &t);
    while (t--) {
        memset(s, 0, sizeof(s));
        scanf("%s%d", s, &n);
        for (int i = 0; i < n; i ++) {
            leftmost = none;
            process(s);
            printf("%s\n", s);
        }
        printf("\n");
    }
    return 0;
}

