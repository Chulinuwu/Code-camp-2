#include <bits/stdc++.h>

using namespace std;

struct A{
    int u,v,w;

    bool operator < (const A&o) const{
        return w > o.w;
    }
};

A a[1000010];
int p[2510];

int find_root(int i){
    if(p[i] == i){
        return i;
    }
    else{
        return p[i] = find_root(p[i]);
    }
}

int main(){

    int n,m,u,v,w,st,en;

    double pp;

    scanf("%d %d", &n ,&m);

    for(int i = 1; i <= n ; i++){
        p[i] = i;
    }
    for(int i = 1; i <= m ; i++){
        scanf("%d %d %d", &a[i].u, &a[i].v , &a[i].w);
    }
    scanf("%d %d %lf", &st , &en , &pp);
    sort(a+1 , a+1+m);

    int minn = 1e9;
    for(int i = 1 ; i<= m ; i++){
        int ru = find_root(a[i].u);
        int rv = find_root(a[i].v);

        if(ru != rv){
            p[ru] = rv;
            minn = min(minn,a[i].w);
        }
        if(p[find_root(st)] == p[find_root(en)]){
            double res = pp/(minn-1);
            printf("%0.lf\n" , ceil(res));
            break;
        }
    }

    return 0;
}

/*
7 10
1 2 30
1 3 15
1 4 10
2 4 25
2 5 60
3 4 40
4 7 35
3 6 20
5 7 20
7 6 30
1 7 99
*/


