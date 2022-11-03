#include <bits/stdc++.h>

using namespace std;

double n[1000100];

int main(){

    int q, i , j , k ,m ,x,y;
    int sum;
    double avg;
    scanf("%d" , &q);

    for(i = 0 ; i< q ; i++){

        avg = 0;

        scanf("%lf", &n[i]);
    sort(n,n+q,greater<double>());
        if(i == 0){
            printf("%.1lf\n",n[i]);
        }
        if((i+1)%2 == 0){
        //    sort(n,n+i);
            avg = (double)(n[i/2]) + (double)(n[i/2 + 1]) ;
            printf("%.1lf\n", avg/2);
        }
        else if((i+1)%2 != 0 && i != 0){
          //  sort(n,n+i);
            printf("%.1lf\n", n[i/2]);
        }

    }


    return 0;

}
/*
10
1 4 2 5 2 3 1 6 3 4
*/
