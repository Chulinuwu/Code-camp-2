#include <bits/stdc++.h>

using namespace std;

char a[10010][10010];

int main(){

    int m,n,i,j,k;

    scanf("%d %d" , &m ,&n);

    for(i = 0 ; i < m; i++){
        for(j= 0 ; j < n ; j++){
            scanf(" %c", a[i][j]);
        }
    }


    return 0;

}

/*
8 5
.....
.....
.OO..
.....
.O...
...O.
.....
.....
1 1 3 2 0
*/