#include <bits/stdc++.h>

using namespace std;

int p[300300],mark[300300];

int fr(int i){
    if(p[i] == i){
        return i;
    }
    return p[i] =fr(p[i]);
}

int main(){

    int n,q,a,b,pa,pb,i,l,ch;

    scanf("%d %d" , &n , &l);


    for(i = 1 ; i <= l ; i++){
        p[i] = i;
    }
    while(n--){
    scanf("%d %d", &a , &b);
    pa = fr(a) , pb = fr(b) , ch = 1;
    if(!mark[a]){
        mark[a] = 1;
        p[pa] = pb;
    }
    else if(!mark[b]){
        mark[b] = 1;
        p[pb] = pa;
    }
    else if(!mark[pa]){
        mark[pa] = 1;
        p[pa] = pb;
    }
    else if(!mark[pb]){
        mark[pb] = 1;
        p[pb] = pa;
    }
    else{
        printf("No\n");
        ch = 0;
    }
    if(ch){
        printf("Yes\n");
    }
    }

    return 0;
}


/*
6 4
1 2
1 3
1 2
1 2
1 3
2 4
*/
