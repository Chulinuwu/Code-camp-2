#include <bits/stdc++.h>

using namespace std;

priority_queue <int> qu1;
priority_queue <int> qu2;
double med[1000100];

int main(){

    int q,i,j,k;
    int cnt;
    double ans,sum,num;

    cin.tie(0) -> sync_with_stdio(0);

    cin >> q ;

    sum = 0;
    ans = 0;
    i = q;
    j = 1;

    while(i>=0){

        cnt = 1;

        cin >> num ;


        if(i == q){
            qu1.push(num);
        }
        else{
            qu2.push(qu1.top());
            cout << qu1.top() << endl;
            qu1.pop();
//            qu1.push(num);
//            while(!qu1.empty()){
//            qu2.push(qu1.top());
//            sum += qu1.top();
//            qu1.pop();
//            cnt++;
//            }
//            med = sum / cnt;
        }
    //   cout << med << endl;
       i--;
    }


    return 0;
}


/*
10
1 4 2 5 2 3 1 6 3 4
*/
