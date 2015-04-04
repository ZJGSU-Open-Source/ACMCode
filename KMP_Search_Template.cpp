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

int next[30];

void GetNext(char des[],int next[])  {
    int pLen = strlen(des);
    next[0] = -1;
    int k = -1;
    int j = 0;
    while (j < pLen - 1)  {
        //p[k]表示前缀，p[j]表示后缀
        if (k == -1 || des[j] == des[k])   {
            ++k;    ++j;
            next[j] = k;
        }  else   {
            k = next[k];
        }
    }
}

int KmpSearch(char src[], char des[])  {
    int i = 0, j = 0;
    int sLen = strlen(src);
    int pLen = strlen(des);
    while (i < sLen && j < pLen)  {
        //①如果j = -1，或者当前字符匹配成功（即S[i] == P[j]），都令i++，j++
        if (j == -1 || src[i] == des[j])  {
            ++i;    ++j;
        }  else  {
            //②如果j != -1，且当前字符匹配失败（即S[i] != P[j]），则令 i 不变，j = next[j]
            //next[j]即为j所对应的next值
            j = next[j];
        }
    }
    if (j == pLen)  return i - j;
    else    return -1;
}
int main(){
    char s[30], p[30];
    while(scanf("%s%s",s,p)){
        GetNext(p, next);
        printf("%d\n",KmpSearch(s, p));
    }
    return 0;
}
