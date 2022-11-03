#include <bits/stdc++.h>

using namespace std;

int Pow(int a, int b , int c){
    if(b == 0){
        return 1;
    }
    int  t = Pow(a,b/2 , c);
    if(b%2 == 0){
        return (t*t) % c;
    }
    return (((t*t)%c)*a) %c;
}

int main(){

    int a, b, c ,q;

    scanf("%d" , &q);
   
   while(q--){
       scanf("%d %d %d" , &a , &b , &c);
       printf("%d\n", Pow(a,b,c));
   }

    return 0;
}