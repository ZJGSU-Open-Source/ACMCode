/*
 Author: sakeven
 */
#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n;

int main(){
    char str[1000];
    scanf("%d", &n);
    getchar();
    while (n--) {
        int tabs = 0, spaces = 0;
        while (gets(str), strcmp(str, "##") != 0){//注意要一行仅有##才结束
            int i;
            for (i = 0; str[i]; i ++) {
                if (str[i] == '\t') {
                    tabs ++;
                }
            }
            
            for (i--; i >= 0 ; i--) {
                if (str[i] == ' ') {
                    spaces ++;
                } else if (str[i] == '\t') {
                    spaces += 4;
                } else {
                    break;
                }
            }
        }
        printf("%d tab(s) replaced\n%d trailing space(s) removed\n", tabs, spaces);
    }
    return 0;
}