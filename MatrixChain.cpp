#include <bits/stdc++.h>

using namespace std;

int col[15],row[15],dp[15][15],path[15][15];

int play(int l,int r){
    if(dp[l][r] != -1){
        return dp[l][r];
    }
    if(l == r){
        return dp[l][r] = 0;
    }
    int minn = 1e9;
    for(int i = l ; i <r ; i++){
        int value = play(l,i)+play(i+1,r)+row[l]*col[i]*col[r];
        if(value < minn){
            minn = value,path[l][r] = i;
        }
    }
    return dp[l][r] = minn;
}

void print(int l , int r){
    if(l == r){
        printf("A%d",l);

        return;
    }
    printf("(");
    print(l,path[l][r]);
    printf(" x ");
    print(path[l][r]+1,r);
    printf(")");
}

int main(){

    int n;
    memset(dp,-1,sizeof dp);
    scanf("%d", &n);
    for(int i = 1 ; i <= n ; i++){
        scanf("%d %d" , &row[i] , &col[i]);
    }

    play(1,n);

    printf("%d\n",dp[1][n]);

    print(1,n);

    return 0;
}

/*
3
5 10
10 20
20 35
*/
