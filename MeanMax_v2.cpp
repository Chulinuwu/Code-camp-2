#include <bits/stdc++.h>

using namespace std;

double a[1000100];
double avg[10010][10010] = {0};
double ans;
int main(){

int i , n , k ,x ,y ,j, p;
double sum;

scanf("%d %d" , &n , &k);

for(i = 1 ; i<= n ; i++){
    scanf("%lf", &a[i]);
}

//sort(a+1,a+n+2,greater<int>());

//for(i = 1 ; i<= n ; i++){
//    printf("%.1lf\n", a[i]);
//}

//printf("------------");

 ans = 0;

for(i = 1; i<= n ; i++){

    sum = 0;
    x = 1;
    for(j = i; j <= n ; j++){

        sum+= a[j];

        if(j >= k && x >= k){
            avg[i][j] =  sum/x;
         //  printf("%.1lf\n", avg[i][j]);
            if(avg[i][j] - ans > 0){
            ans = avg[i][j];
            }
        }
    x++;
        }
    }

printf("%.1lf\n", ans);

return 0;

}

/*
4 2
4 3 4 2

6 3
6 3 1 2 1 7

5 1
1 2 3 4 5
*/
