#include <bits/stdc++.h>

using namespace std;

struct A{
    int w,ind;
    bool operator < (const A&o) const{
        return w < o.w;
    }
}; A now;

int mark[100100];

priority_queue <A> pq;

int main(){

    int n,q,num;

    scanf("%d %d", &n , &q);

    for(int i = 1; i <= n ; i++){
        scanf("%d",&num);
        pq.push({num,i});
    }

    for(int i = 1 ; i <= q; i++){
        int ans = 0;
        scanf("%d" , &num);
        while(!pq.empty()){
            now = pq.top();

            if(now.w > num){
                if(mark[now.ind] != i && mark[now.ind] != 0 ){
                    pq.pop();
                    continue;
                }
                if(mark[now.ind+1] == 0 && now.ind+1 <= n){
                    mark[now.ind+1]=i;
                    ans++;
                }
                if(mark[now.ind-1] == 0 && now.ind-1 >= 1){
                    mark[now.ind-1]=i;
                    ans++;
                }
                if(mark[now.ind] == 0){
                mark[now.ind] = i;
                ans++;
                }
                pq.pop();
            }
            else{
            break;
            }
        }
        printf("%d\n", ans);
    }


    return 0;
}

/*
7 4
3
1
4
6
7
3
5 -
5
4
6
2
*/
