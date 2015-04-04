struct Mat {
    double mat[N][N];
};

Mat operator * (Mat a, Mat b){
    Mat c;
    memset(c.mat, 0, sizeof(c.mat));
    for(int k = 0; k < n; ++k){
        for(int i = 0; i < n; ++i){
            //if(a.mat[i][k] <= 0)    continue;   //
            for(int j = 0; j < n; ++j){
                //if(b.mat[k][j] <= 0)    continue;   //
                c.mat[i][j] += a.mat[i][k] * b.mat[k][j];
            }
        }
    }
    return c;
}

Mat operator ^ (Mat a, int k){
    Mat c;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            c.mat[i][j] = (i == j); //init
        }
    }
    for(; k; k >>= 1){
        if(k & 1)   c = c * a;  //key, 这里需要理解一下为什么奇数时候要乘
        a = a * a;
    }
    return c;
}
