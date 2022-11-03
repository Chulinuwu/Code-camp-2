#include <bits/stdc++.h>

using namespace std;

struct A{
    int w,v,d,i;

    bool operator < (const A& o) const{
        return w> o.w;
    }
};

struct B{
    int w,v,d,i;

    bool operator < (const B&o) const{
        return d> o.d;
    }
};

priority_queue<A> hat;
priority_queue<B> tim;

int mark[200100];

int main(){

    int n,m,i,opr,j,ch,w,v,d,x;

    scanf("%d %d", &n , &m);

    for(i = 0 ; i < n+ m ; i++){
        scanf("%d", &opr);

        if(opr == 1){
            scanf("%d" , &j);
            if(j == 1){
                scanf("%d %d", &w, &v);
                hat.push({w,v,200100,i});
            }
            if(j == 2){
                scanf("%d %d %d" , &w ,&v ,&d);
                hat.push({w,v,d,i});
            }
            if(j == 3){
                scanf("%d %d %d %d", &w ,&v ,&d ,&x);
                hat.push({w,v,d,i});
                tim.push({x,v,d,i});
            }
        }
        else{
            while(!tim.empty() && tim.top().d <= i){
                hat.push({tim.top().w,tim.top().v , 200100 , tim.top().i});
                tim.pop();
            }
            ch = 1;
            while(!hat.empty()){
                if(hat.top().d <= i || mark[hat.top().i]){
                    hat.pop();
                    continue;
                }
                mark[hat.top().i] = 1;
                printf("%d\n", hat.top().v);
                hat.pop();
                ch = 0;
                break;
            }
            if(ch){
                printf("0\n");
            }
        }
    }

    return 0;
}
