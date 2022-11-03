#include <bits/stdc++.h>

using namespace std;

int gcd(int a , int b){
    if(a%b == 0){
        return b;
    }
    return gcd(b,a%b);
}

int main()
{
    int ans , num;

    scanf("%d %d", &ans , &num);

    ans = gcd(ans,num);

    printf("%d\n",ans);

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

