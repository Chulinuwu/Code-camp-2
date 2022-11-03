#include <bits/stdc++.h>

using namespace std;

int a[1000100];
double qsum[1000100];

int main(){

int n , k , i , avg , sum;

scanf("%d %d" ,  &n , &k);

for(i = 1 ; i <= n ; i++){
    scanf("%d", &a[i]);
}

avg = 0;
x = 1;

while(x != n-k+1){
    for(i = x ; i <= k+x-1 ; i++){
        sum += a[i];
    }
    qsum[x] = (double)sum / k;
    if(x != 1){
        if(qsum[x] - qsum[x-1] > 1e-6){
            max = qsum[x];
        }
        else{
            max = qsum[x-1];
        }
    }
    x++;
}

printf("%.1lf\n", max);

return 0;

}
