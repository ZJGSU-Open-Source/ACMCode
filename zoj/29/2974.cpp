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

const int MAXN = 250;

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
    for (int i = 0; i < MAXN; i ++) {
        for (int j = 0; j < MAXN; j ++) {
            mat[i][j] = 0;
            if (i == j) {
                mat[i][j] = 1;
            }
        }
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
                tmp.mat[i][j] += mat[i][k] * A.mat[k][j];
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

double vol[MAXN];

int main(){
    int t, n, a, m;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i ++) {
            scanf("%lf", &vol[i]);
        }
        int k = 0;
        matrix<double> container(n,n);
        for (int i = 0; i < n; i ++) {
            scanf("%d", &k);
            if (k == 0) {   //注意这里
                container.mat[i][i] = 1.0;
            }
            for (int j = 0; j < k; j ++) {
                scanf("%d", &a);
                container.mat[i][a-1] += 1.0/k;
            }
        }
        scanf("%d", &m);
        matrix<double> res =  container.pow(m);
        double sum[250] = {0};
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                sum[i] += vol[j]*res.mat[j][i];
            }
        }
        for (int i = 0; i < n-1; i ++) {
            printf("%.2f ", sum[i]);
        }
        printf("%.2f\n", sum[n-1]);
    }
    return 0;
}
