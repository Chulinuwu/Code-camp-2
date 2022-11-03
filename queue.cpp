#include <bits/stdc++.h>

using namespace std;

struct A{
    int u, v, w;
    bool operator < (const A &o)const{
        if(u != o.u)
            return u > o.u;
        return v > o.v;
    }
};

A a[100100];

priority_queue <A> qu;

int main(){

    int n,u,v;

    scanf("%d", &n);

    for(int i = 1 ; i<= n ; i++){
    scanf("%d %d", &u , &v);
    qu.push({u,v});
    }

    for(int i = 1 ; i <= n ; i++){
        printf("%d %d\n" , qu.top().u , qu.top().v);
        qu.pop()x   ;
    }


    return 0;
}
/*
3
2 5
2 7
9 5
*/

