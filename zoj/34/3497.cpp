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

const int MAXN = 50;

template<class T>
class matrix{
public:
    T mat[MAXN][MAXN];
    int col, row;
    matrix();
    matrix(int, int);
    void unti();
    matrix mult(const matrix&) const;
    matrix pow(int) const;
};

template<class T>
matrix<T>::matrix(){
    memset(mat, 0, sizeof(mat));
}

template<class T>
matrix<T>::matrix(int row, int col):row(row), col(col) {
    memset(mat, 0, sizeof(mat));
}

template<class T>
void matrix<T>::unti() {
    memset(mat, 0, sizeof(mat));
    for (int i = 0; i < MAXN; i ++) {
                mat[i][i] = 1;
    }
}

template<class T>
matrix<T> matrix<T>::mult(const matrix& A) const{
    assert(A.row == col);
    matrix<T> tmp(row, A.col);
    for (int k = 0; k < col; k ++) {
        for (int i = 0; i < row; i ++) {
            if (mat[i][k] == 0) {
                continue;
            }
            for (int j = 0; j < A.col; j ++) {
                tmp.mat[i][j] |= mat[i][k] * A.mat[k][j];
            }
        }
    }
    return tmp;
}

template<class T>
matrix<T> matrix<T>::pow(int k) const{
    matrix<T> base(row, col);
    matrix<T> res(row, col);
    res.unti();
    base = *this;
    while(k!=0){
        if ( k & 1){
            res = base.mult(res);
        }
        k >>= 1;
        base = base.mult(base);
    }
    return res;
}

int begins[30];

int main(){
    int t, n, m, q, p;
    int a, b;
    scanf("%d", &t);
    while (t --) {
        scanf("%d%d", &m, &n);
        matrix<int> Map(n*m, n*m);
       
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                getchar();
                scanf("(");
                for (int k = 0; k < 4; k ++) {
                    if (k != 0) {
                        scanf(",");
                    }
                    scanf("(%d,%d)", &a, &b);
                    if (i == m-1 && j == n-1) {
                        continue;
                    }
                    Map.mat[i*n+j][(a-1)*n+b-1] = 1;
                    //printf("%d %d %d\n", i*n+j, a, b);
                }
                scanf(")");
            }
        }
        scanf("%d", &q);
        while (q --) {
            memset(begins, 0, sizeof(begins));
            begins[0] = 1;
            scanf("%d", &p);
            matrix<int> last =  Map.pow(p);
            int ends[50] = {0};
            int cnt = 0;
            for (int i = 0; i < n*m; i ++) {
                ends[i] = 0;
                for (int j = 0; j < n*m; j ++) {
                    ends[i] |= begins[j]*last.mat[j][i];
                }
                cnt += ends[i];
            }
            if (ends[n*m-1] == 0) {
                printf("False\n");
            } else if(cnt > 1) {
                printf("Maybe\n");
            } else {
                printf("True\n");
            }
        }
        printf("\n");
    }
    return 0;
}