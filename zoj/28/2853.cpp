/*
 Author: sakeven
 */
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <queue>
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

int pop[MAXN];

int main() {
    int t, a, b;
    int n, m;
    double p;
    while (scanf("%d%d", &n, &m), n+m) {
        matrix<double> A(n, n);
        A.unti();
        for (int i = 0; i < n; i ++) {
            scanf("%d", &pop[i]);
        }
        scanf("%d", &t);
        for (int i = 0; i < t; i ++) {
            scanf("%d %d %lf", &a, &b, &p);
            A.mat[a][b] += p;
            A.mat[a][a] -= p;
        }
        matrix<double> res = A.pow(m);
        double sum = 0;
        for (int i = 0; i < n; i ++) {
            sum += pop[i] * res.mat[i][n-1];
        }
        printf("%.0f\n", sum);
    }
}