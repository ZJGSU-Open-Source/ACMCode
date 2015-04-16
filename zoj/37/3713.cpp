/*
 Author: sakeven
 */
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <bitset>

using namespace std;


string line;

int main() {
    int t;
    scanf("%d", &t);
    getchar();
    while (t --) {
        getline(cin, line);
        int len = line.size();
        if (len == 0) {
            printf("00\n");
            continue;
        }
        int l = len;
        while (l) {
            int tmp = l%(1<<7);
            l >>= 7;
            if (l > 0) {
                tmp = tmp|(1<<7);
            }
            printf("%02X",  tmp);
        }
        for (int i = 0; i < len; i ++) {
            printf("%02X", line[i]);
        }
        printf("\n");
    }
    return 0;
}