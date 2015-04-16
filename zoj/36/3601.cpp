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
#include <map>
#include <stack>
#include <set>
#include <cmath>
#include <cstring>

using namespace std;

map<string, int>Hash;
set< pair<int, int> > s;
string names[60000];
int cnt = 0;
int idx[60000];

int getID(char *name) {
    string sname = name;
    map<string, int>::iterator it = Hash.find(sname);
    if ( it == Hash.end()) {
        Hash[sname] = cnt;
        names[cnt++] = sname;
        return cnt-1;
    } else {
        return it->second;
    }
}

int main() {
    int t;
    int n, m, q, l;
    int a, b;
    char name[30];
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d", &n, &m, &q);
        Hash.clear();
        s.clear();
        cnt = 0;
        for (int i = 0; i < n+m; i ++) {
            scanf("%s %d", name, &l);
            a = getID(name);
            for (int j = 0; j < l; j ++) {
                scanf("%s", name);
                b = getID(name);
                s.insert(make_pair(a, b));
            }
        }
        while (q --) {
            scanf("%d", &l);
            for (int i = 0; i < l; i ++) {
                scanf("%s", name);
                idx[i] = getID(name);
            }
            int ans = 0;
            int cnt = 0;
            for (int j = 0; j < l; j ++) {
                int flag = 1;
                for (int i = 0; i < l; i ++) {
                    if (i != j && ( s.find(make_pair(idx[i], idx[j])) != s.end() ||
                                   s.find(make_pair(idx[j], idx[i])) == s.end())) {
                        flag = 0;
                        break;
                    }
                }
                if (flag) {
                    ans = idx[j];
                    cnt ++;
                }
                if (cnt >= 2) {
                    break;
                }
            }
            if (cnt == 1) {
                printf("1 %s\n", names[ans].c_str());
            } else {
                printf("0\n");
            }
        }
        printf("\n");
    }
    return 0;
}