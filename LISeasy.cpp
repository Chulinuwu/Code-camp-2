#include <bits/stdc++.h>

using namespace std;

int a[1010],length[1010],from[1010], keep[1010];

int main(){

    int N, maxx = 0 , at = 0 , i , j ;

    scanf("%d", &N);

    for(i = 0 ; i < N ; i++){
        scanf("%d", &a[i]);

        length[i] = 1;
        from[i] = i;
    }

    for(i = 1 ; i < N ; i++){
        for(j = 0 ; j < i ; j++){
            if(a[i] > a[j] && length[i] < length[j] +1){
                length[i] = length[j] +1 , from[i] = j;
            }
        }
    }

    for(i = 0 ; i < N ; i++){
        if(length[i] > maxx){
            maxx = length[i] , at = i;
        }
    }

    printf("%d\n", maxx);

    for(i = 0 ; i < maxx ; i++){
        keep[i] = a[at] , at = from[at];
    }

    for(i = maxx-1 ; i >= 0 ; i--){
        printf((i == 0)?"%d\n" : "%d " , keep[i]);
    }

    return 0;
}

/*
8
-7 10 9 2 3 8 8 1
*/
