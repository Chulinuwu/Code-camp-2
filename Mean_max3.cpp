#include <bits/stdc++.h>

using namespace std;

double a[1000100];
double avg[10010][10010] = {0};
double sum[1000100];
double ans[1000100];

int main(){

int i , n , k ,x ,y ,j, p , l , r ,mid;
double mx;

scanf("%d %d" , &n , &k);

for(i = 1 ; i<= n ; i++){
    scanf("%lf", &a[i]);
    sum[i] = a[i] + sum[i-1];
}


for(i = 1 ; i<= n ; i++){
    printf("%.1lf\n", sum[i]);
}
//printf("%.1lf\n", ans);

l = 1 , r = n;
mx = 0;

while(l < r){
    x = 1;
    mid = (l+r) / 2;

    if((sum[mid]-sum[mid-1])- (sum[n]-sum[mid]) > 1e-6){
        mx = sum[mid]-sum[mid-1];
        r = mid-1;
    }
    else{
        l = mid+1;
        r = mid*2 - 1;
    }
}

//ans = mx /

return 0;

}


//sort(a+1,a+n+2,greater<int>());

//for(i = 1 ; i<= n ; i++){
//    printf("%.1lf\n", a[i]);
//}

//printf("------------");

// ans = 0;

//for(i = 1; i<= n ; i++){
//
//    sum = 0;
//    x = 1;
//    for(j = i; j <= n ; j++){
//
//        sum+= a[j];
//
//        if(j >= k && x >= k){
//            avg[i][j] =  sum/x;
//         //  printf("%.1lf\n", avg[i][j]);
//            if(avg[i][j] - ans > 0){
//            ans = avg[i][j];
//            }
//        }
//    x++;
//        }
//    }
