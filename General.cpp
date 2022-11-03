#include <bits/stdc++.h>

using namespace std;

int aa[100100], p[100100];

int fr(int i){
    if(p[i] == i){
        return i;
    }
    return p[i] = fr(p[i]);
}

int main(){

int i,n,m,a,b,pa,pb;

scanf("%d %d" , &n , &m);

for(i = 1 ; i <= n ; i++){
    p[i] = i;
}
for(i = 1 ; i <= n ; i++){
    scanf("%d", &aa[i]);
}
while(m--){
    scanf("%d %d" , &a , &b);
    pa = fr(a), pb = fr(b);
    if(pa == pb){
        printf("-1\n");
    }
    else{
        if(aa[pa] > aa[pb]){
            printf("%d\n" , pa);
            aa[pa] += aa[pb] / 2;
            p[pb] = pa;
        }
        else if(aa[pb] > aa[pa]){
            printf("%d\n",pb);
            aa[pb] += aa[pa]/2;
            p[pa] = pb;
        }
        else if(pa < pb){
            printf("%d\n", pa);
            aa[pa] += aa[pb] / 2;
            p[pb] = pa;
        }
        else{
            printf("%d\n",pb);
            aa[pb] += aa[pa]/2;
            p[pa] = pb;
        }
    }
}

return 0;
}
