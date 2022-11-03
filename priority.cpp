#include <bits/stdc++.h>

using namespace std;

priority_queue <int> qu;

int main(){

    int n , num , i;

    scanf("%d", &n);

    for(i = 1 ; i <= n ; i++){
            scanf("%d", &num);
            qu.push(num);
    }

    for(i = 1 ; i<= n ; i++){
        printf("%d\n" ,  qu.top());
        qu.pop();
    }

    return 0;

}
