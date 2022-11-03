#include <bits/stdc++.h>

using namespace std;

char aa[50][50];

int visit[50][50],roomCount, exitDepth , m, n,l,a,b,c,d;

int DIR[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

int onBoard(int ni , int nj){
    if((ni >= 0) && (ni < m) && (nj >= 0) && (nj < n)){
        return 1;
    }
    return 0;
}

void play(int i , int j , int depth){
    visit[i][j] = 1;
    roomCount++;
    if((i == c) && (j == d)){
        exitDepth = depth;
    }
    for(int dir = 0 ; dir < 4 ; dir++){
        int ni = i + DIR[dir][0];
        int nj = j + DIR[dir][1];
        if(onBoard(ni,nj) && aa[ni][nj] == '.' && (!visit[ni][nj])){
            play(ni,nj,depth+1);
        }
    }
}

int main(){

    int Q,i,j;

    scanf("%d", &Q);

    while(Q--){
        scanf("%d %d %d", &m , &n , &l);
        for(i = 0 ; i < m ; i++){
            scanf(" %s", aa[i]);
        }
        scanf("%d %d %d %d" , &a,&b ,&c ,&d);
        a--,b--,c--,d--;
        for(i = 0 ; i < m ; i++){
            for(j = 0 ; j < n ; j++){
                visit[i][j] = 0;
            }
        }
        roomCount = 0;
        exitDepth = -1;
        play(a,b,0);

        if(exitDepth == -1){
            printf("-1\n");
        }
        else if(exitDepth > l){
            printf("-1\n");
        }
        else{
            int extraRoom = roomCount - exitDepth - 1;
            if(l - exitDepth - extraRoom*2 >= 0){
                printf("%d\n" , roomCount);
            }
            else{
                int lleft = l - exitDepth;
                printf("%d\n", 1 + exitDepth + (lleft/2));
            }
        }
    }

    return 0;
}

/*
3
5 8 9
#..#..#.
.#...##.
##.##..#
...##.##
##.#..##
4 3 2 4
4 5 100
.....
.####
...#.
#.##.
3 3 1 3
3 5 2
.....
.####
.....
3 3 1 3
*/
