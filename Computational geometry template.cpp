//#pragma comment(linker, "/STACK:16777216") //for c++ Compiler
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define ll long long
#define Max(a,b) (((a) > (b)) ? (a) : (b))
#define Min(a,b) (((a) < (b)) ? (a) : (b))
#define Abs(x) (((x) > 0) ? (x) : (-(x)))
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 220;
const double eps = 1e-9;

int gcd(int a,int b){
    return b == 0 ? a : gcd(b, a % b);
}
struct POINT{
    double x;
    double y;
    POINT() : x(0), y(0) {};
    POINT(double _x_, double _y_) : x(_x_), y(_y_) {};
};

struct SEG{
    POINT a;
    POINT b;
    SEG() {};
    SEG(POINT _a_, POINT _b_) : a(_a_), b(_b_) {};
};

struct LINE{
    POINT a;
    POINT b;
    LINE() {};
    LINE(POINT _a_, POINT _b_) : a(_a_), b(_b_) {};
};

struct LINE2{
    double A, B, C;
    LINE2 () {};
    LINE2(double _A_, double _B_, double _C_): A(_A_), B(_B_), C(_C_) {};
};

LINE2 Line2line(const LINE & L){
    LINE2 L2;
    L2.A = L.b.y - L.a.y;
    L2.B = L.a.x - L.b.x;
    L2.C = L.b.x * L.a.y - L.a.x * L.b.y;
    return L2;
}

struct POLY{
    int n;
    double * x;
    double * y;
    POLY() : n(0), x(NULL), y(NULL) {};
    POLY(int _n_, const double * _x_, const double * _y_){
        n = _n_;
        x = new double[n + 1];
        memcpy(x, _x_, n * sizeof(double));
        x[n] = _x_[0];
        y = new double[n + 1];
        memcpy(y, _y_, n * sizeof(double));
        y[n] = _y_[0];
    }
};

POINT vertex(const POLY & poly, int idx){
    idx %= poly.n;
    return POINT(poly.x[idx], poly.y[idx]);
}

SEG Edge(const POLY & poly, int idx){
    idx %= poly.n;
    return SEG(POINT(poly.x[idx], poly.y[idx]),
        POINT(poly.x[idx + 1], poly.y[idx + 1]));
}

void Coefficient(const LINE & L, double & A, double & B, double & C){
    A = L.b.y - L.a.y;
    B = L.a.x - L.b.x;
    C = L.b.x * L.a.y - L.a.x * L.b.y;
}

POINT Intersection(const LINE & A, const LINE & B){
    double A1, B1, C1;
    double A2, B2, C2;
    Coefficient(A, A1, B1, C1);
    Coefficient(B, A2, B2, C2);
    POINT temp_point(0, 0);
    temp_point.x = -(B2 * C1 - B1 * C2) / (A1 * B2 - A2 * B1);
    temp_point.y =  (A2 * C1 - A1 * C2) / (A1 * B2 - A2 * B1);
    return temp_point;
}

double Ptol(const POINT p, const LINE2 L){
    return Abs(L.A * p.x + L.B * p.y + L.C) / sqrt(L.A * L.A + L.B * L.B);
}

bool IsEqual(double a, double b){
    return (Abs(a - b) < eps);
}

bool IsEqual(const POINT & a, const POINT & b){
    return (IsEqual(a.x, b.x) && IsEqual(a.y, b.y));
}

bool IsEqual(const LINE & A, const LINE & B){
    double A1, B1, C1;
    double A2, B2, C2;
    Coefficient(A, A1, B1, C1);
    Coefficient(B, A2, B2, C2);
    return IsEqual(A1 * B2, A2 * B1) &&
        IsEqual(A1 * C2, A2 * C1) &&
        IsEqual(B1 * C2, B2 * C1);
}

double Cross(const POINT & a, const POINT & b, const POINT &o){
    return (a.x - o.x) * (b.y - o.y) - (b.x - o.x) * (a.y - o.y);
}

double SquareDis(const POINT & a, const POINT & b){
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

//求面积，正为顺时针，和叉积写法有关
double PointArea(POINT p[],int n){
    double area = 0;
    for(int i = 2; i < n; ++i)
        area += Cross(p[1], p[i], p[i+1]);
    return -area / 2.0;
}

bool IsParallel(const LINE & A, const LINE & B){
    double A1, B1, C1;
    double A2, B2, C2;
    Coefficient(A, A1, B1, C1);
    Coefficient(B, A2, B2, C2);
    /*
    return (A1 * B2 == A2 * B1) &&
        ((A1 * C2 != A2 * C1) || (B1 * C2 != B2 * C1));
    */
    return (A1 * B2 == A2 * B1);
}

bool IsIntersect(const LINE & A, const LINE & B){
    return !IsParallel(A, B);
}

bool IsIntersect(const SEG & u, const SEG & v){
    return (Cross(v.a, u.b, u.a) * Cross(u.b, v.b, u.a) >= 0) &&
        (Cross(u.a, v.b, v.a) * Cross(v.b, u.b, v.a) >= 0) &&
        (Max(u.a.x, u.b.x) >= Min(v.a.x, v.b.x)) &&
        (Max(v.a.x, v.b.x) >= Min(u.a.x, u.b.x)) &&
        (Max(u.a.y, u.b.y) >= Min(v.a.y, v.b.y)) &&
        (Max(v.a.y, v.b.y) >= Min(u.a.y, u.b.y));
}

bool IsOnSeg(const SEG & seg, const POINT & p){
    return (IsEqual(p, seg.a) || IsEqual(p, seg.b)) ||
        (((p.x - seg.a.x) * (p.x - seg.b.x) < 0 ||
        (p.y - seg.a.y) * (p.y - seg.b.y) < 0) &&
        (IsEqual(Cross(seg.b, p, seg.a), 0)));
}

bool IsOnPoly(const POLY & poly, const POINT & p){
    for(int i = 0; i < poly.n; ++i){
        if(IsOnSeg(Edge(poly, i), p)){
            return true;
        }
    }
    return false;
}

bool IsInPoly(const POLY & poly, const POINT & p){
    SEG L(p, POINT(INF, p.y));
    int count = 0;
    for(int i = 0; i < poly.n; ++i){
        SEG S = Edge(poly, i);
        if(IsOnSeg(S, p)){
            return true;
        }
        if(!IsEqual(S.a.y, S.b.y)){
            POINT & q = (S.a.y > S.b.y) ? (S.a) : (S.b);
            if(IsOnSeg(L, q)){
                ++count;
            } else if(!IsOnSeg(L, S.a) && !IsOnSeg(L, S.b) && IsIntersect(S, L)){
                ++count;
            }
        }
    }
    return (count % 2 != 0);
}

POINT InCenter(const POLY & poly){
    double S, Si, Ax, Ay;
    POINT p;
    Si = (poly.x[poly.n - 1] * poly.y[0] - poly.x[0] * poly.y[poly.n - 1]);
    S = Si;
    Ax = Si * (poly.x[0] + poly.x[poly.n - 1]);
    Ay = Si * (poly.y[0] + poly.y[poly.n - 1]);
    for(int i = 1; i < poly.n; ++i){
        Si = (poly.x[i - 1] * poly.y[i] - poly.x[i] * poly.y[i - 1]);
        Ax += Si * (poly.x[i - 1] + poly.x[i]);
        Ay += Si * (poly.y[i - 1] + poly.y[i]);
        S += Si;
    }
    S = S * 3;
    return POINT(Ax/S, Ay/S);
}

double Area(const POLY & poly){
    if(poly.n < 3)  return double(0);
    double s = poly.y[0] * (poly.x[poly.n - 1] - poly.x[1]);
    for(int i = 1; i < poly.n; ++i){
        s += poly.y[i] * (poly.x[i - 1] - poly.x[(i + 1) % poly.n]);
    }
    return s / 2;
}

int PointInedge(const POLY & poly){
    int ans = 0;
    for(int i = 0; i < poly.n; ++i){
        double xx = Abs(poly.x[i] - poly.x[i + 1]);
        double yy = Abs(poly.y[i] - poly.y[i + 1]);
        if(xx == 0 && yy == 0)
            ans += 0;
        else if(xx == 0)
            ans += yy - 1;
        else if(yy == 0)
            ans += xx- 1 ;
        else
            ans += gcd(xx, yy) - 1;
    }
    return ans + poly.n;
}

bool IsConvexPolygon(const POLY & poly){
    double ans ,cnt = 1.0;
    bool flag ,real = false;
    for(int i = 0; i < poly.n; ++i){
        ans = (poly.x[i] - poly.x[(i + 2) % poly.n])\
            * (poly.y[(i + 1) % poly.n] - poly.y[(i + 2) % poly.n])\
            - (poly.x[(i + 1) % poly.n] - poly.x[(i + 2) % poly.n])\
            * (poly.y[i] - poly.y[(i + 2) % poly.n]);
            if(ans < 0) return false;
        /*POINT point_A, point_B, point_C;
        if(point_A.x == point_B.x || point_B.x == point_C.x){
            if(point_A.x == point_B.x && point_B.x == point_C.x)
                continue;
        }else{
            if((point_B.y - point_A.y) / (point_B.x - point_A.x) \
                == (point_C.y - point_B.y) / (point_C.x - point_B.x))
                continue;
        }

        if(real && cnt * ans < eps) return false;
        cnt = ans;
        real = true;
        */
    }
    return true;
}

double Graham(POINT *pnt, POINT *res, int n){
    int i, len, top =1;
    sort(pnt, pnt + n);
    if (n == 0)
        return 0;
    res[0] = pnt[0];
    if (n == 1)
        return 1;
    res[1] = pnt[1];
    if (n == 2)
        return 2;
    res[2] = pnt[2];
    for (i =2; i < n; i++){
        while (top && Cross(pnt[i], res[top], res[top -1]) >= 0)
            top--;
        res[++top] = pnt[i];
    }
    len = top;
    res[++top] = pnt[n -2];
    for (i = n -3; i >=0; i--){
        while (top != len &&  Cross(pnt[i], res[top], res[top -1]) >= 0)
            top--;
        res[++top] = pnt[i];
    }
    return top;
}

double rotating_calipers(POINT *ch, int n){
    int q =1, ans =0;
    ch[n] = ch[0];
    for (int i = 0; i < n; ++i){
        while (Cross(ch[i + 1], ch[q + 1], ch[i]) > Cross(ch[i + 1], ch[q], ch[i]))
            q = (q +1) % n;
        ans = max(ans, max(SquareDis(ch[i], ch[q]), SquareDis(ch[i + 1], ch[q + 1])));
    }
    return ans;
}

double EulerFunction( double a,double b,double c,double d,double e ){
    return a * (b * c - d * e);
}

double EulerTetrahedron(double OA, double OB, double OC, double AB, double BC, double CA){
    OA *= OA;    OB *= OB;   OC *= OC;
    AB *= AB;    CA *= CA;   BC *= BC;
    double ans = 0;
    ans += EulerFunction( OA,OB,OC,(OB+OC-BC)/2.,(OB+OC-BC)/2. );
    ans -= EulerFunction( (OA+OB-AB)/2.,(OA+OB-AB)/2.,OC,(OA+OC-CA)/2.,(OB+OC-BC)/2. );
    ans += EulerFunction( (OA+OC-CA)/2.,(OA+OB-AB)/2.,(OB+OC-BC)/2.,OB,(OA+OC-CA)/2.);
    return sqrt(ans/36);
}
