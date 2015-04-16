/*
 Author: sakeven
 */
#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n, m;
int mat[11][11];

bool check(){
    bool flagGrass = true;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            if (mat[i][j] == 1) {
                continue;
            }
            flagGrass = false;
            if (mat[i][j] == mat[i+1][j] || mat[i][j] == mat[i][j+1]) {
                return true;
            }
        }
    }
    return flagGrass;
}

int main(){
    while (scanf("%d %d", &n, &m), n||m) {
        memset(mat, -1, sizeof(mat));
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                scanf("%d", &mat[i][j]);
            }
        }
        if (check()) {
            printf("No\n");
        } else {
            printf("Yes\n");
        }
    }
}