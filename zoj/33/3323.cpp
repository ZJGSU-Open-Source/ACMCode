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

int main(){
    int t;
    char password[22];
    scanf("%d", &t);
    while (t--) {
        scanf("%s", password);
        for (int i = 0; password[i]; i++) {
            if (password[i] <= '9' && password[i] >= '0') {
                continue;
            }
            printf("%c", password[i]);
        }
        printf("\n");
    }
    return 0;
}