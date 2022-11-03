#include <bits/stdc++.h>

using namespace std;



int main(){

    int dif1,dif2;
    int x , y, z;

    scanf("%d %d %d", &x ,&y ,&z);

    dif1 = z - y;
    dif2 = y - x;

    if(dif1  > dif2){
        printf("%d", z-y-1);
    }
    else{
        printf("%d", y-x-1);
    }

    return 0;
}