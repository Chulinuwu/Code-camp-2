#include <bits/stdc++.h>

using namespace std;

int a[10010];

int main(){

    int i , j , k , l,n , m;
    int sum,sum1;
    sum = 0;
    for(i = 0 ; i < 9 ; i++){
        scanf("%d" , &a[i]);
        sum += a[i];
    }

    for(i = 0 ; i< 9 ;i++){
        for(j = 0 ; j < 9 ; j++){
            if(sum - 100 == a[i] + a[j]){
                for(k = 0 ; k < 9 ; k++){
                        if(k == i || k == j){
                            continue;
                        }
                        printf("%d\n",a[k]);  
                }
            }
        }
    }

    return 0;   
}

/*
8
6
5
1
37
30
28
22
36

7
8
10
13
15
19
20
23
25
*/