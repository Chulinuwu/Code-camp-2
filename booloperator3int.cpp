#include <bits/stdc++.h>

using namespace std;

struct A{
    int x,y,z;
    bool operator<(const A& other) const{
        if(x < other.x) {
            return false;
        }
        else if(x == other.x){
            if(y < other.y) {
                return false;
            }
            else if(y == other.y){
                return z > other.z;
            }
        }
        return true;
    }
};
A now;

priority_queue<A> heap;

int main(){

    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        int num1,num2,num3;
        cin >> num1 >> num2 >> num3;
        heap.push({num1,num2,num3});
    }
    cout << "--------------------------------" << endl;
    while(!heap.empty()){
        now = heap.top();
        cout << now.x << " " << now.y << " " << now.z << endl;
        heap.pop();
    }

    return 0;
}

/*
5
1 2 3
1 3 4
1 2 5
3 4 6
4 5 6
*/
