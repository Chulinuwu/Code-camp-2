#include <bits/stdc++.h>

using namespace std;

int a[10010][10010];
int b[10010][10010];

int main(){

    int m, n , i , j;

    scanf("%d %d" , &m , &n);

    for(i = 0 ; i < m ; i++){
        for(j = 0 ; j < n ; j++){
            scanf("%d" , &a[i][j]);
        }
    }

    for(i = 0 ; i < m ; i++){
        for(j = 0 ; j < n ; j++){
            scanf("%d", &b[i][j]);
        }
    }

    for(i = 0 ; i < m ; i++){
        for(j = 0 ; j < n ; j++){
            printf("%d ", a[i][j] + b[i][j]);
        }
        printf("\n");
    }

    return 0;
}