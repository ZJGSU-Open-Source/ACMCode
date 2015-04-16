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

int getval(char s[10]){
    if (!strcmp(s, "one")) {
        return 1;
    } else if (!strcmp(s, "two")) {
        return 2;
    } else if (!strcmp(s, "three")) {
        return 3;
    } else if (!strcmp(s, "four")) {
        return 4;
    } else if (!strcmp(s, "five")) {
        return 5;
    } else if (!strcmp(s, "six")) {
        return 6;
    } else if (!strcmp(s, "seven")) {
        return 7;
    } else if (!strcmp(s, "eight")) {
        return 8;
    } else if (!strcmp(s, "nine")) {
        return 9;
    } else if (!strcmp(s, "ten")) {
        return 10;
    } else if (!strcmp(s, "eleven")) {
        return 11;
    }  else if (!strcmp(s, "twelve")) {
        return 12;
    } else if (!strcmp(s, "thirteen")) {
        return 13;
    } else if (!strcmp(s, "fourteen")) {
        return 14;
    } else if (!strcmp(s, "fifteen")) {
        return 15;
    } else if (!strcmp(s, "sixteen")) {
        return 16;
    } else if (!strcmp(s, "seventeen")) {
        return 17;
    } else if (!strcmp(s, "eighteen")) {
        return 18;
    } else if (!strcmp(s, "nineteen")) {
        return 19;
    } else if (!strcmp(s, "twenty")) {
        return 20;
    } else if (!strcmp(s, "thirty")) {
        return 30;
    } else if (!strcmp(s, "forty")) {
        return 40;
    } else if (!strcmp(s, "fifty")) {
        return 50;
    } else if (!strcmp(s, "sixty")) {
        return 60;
    } else if (!strcmp(s, "seventy")) {
        return 70;
    } else if (!strcmp(s, "eighty")) {
        return 80;
    } else if (!strcmp(s, "ninety")) {
        return 90;
    } else if (!strcmp(s, "hundred")) {
        return 100;
    } else if (!strcmp(s, "thousand")) {
        return 1000;
    } else if (!strcmp(s, "million")) {
        return 1000000;
    }
    return 0;
}

int main(){
    int t;
    string in;
    char words[100][10];
    scanf("%d", &t);
    getchar();
    while (t--) {
        getline(cin, in);
        cout<<in<<endl;
        int cnt = 0,  k = 0;
        in.append(" ");
        for (int i = 0; i < in.length(); i++) {
            if (in[i] == ' ') {
                words[cnt][k++] = 0;
                cnt ++;
                k = 0;
                continue;
            }
            words[cnt][k++] = in[i];
        }
        int p = 0, m = 0, t = 0;
        for (int i = 0; i < cnt; i ++) {
            int n = getval(words[i]);
            switch (n) {
                case 1000000:
                    m = p*1000000;
                    p = 0;
                    break;
                case 1000:
                    t = p*1000;
                    p = 0;
                    break;
                case 100:
                    p = p*100;
                    break;
                default:
                    p += n;
                    break;
            }
        }
        printf("%d\n", m+t+p);
    }
}