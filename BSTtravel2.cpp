#include <bits/stdc++.h>

using namespace std;

typedef struct node{
    int num;
    struct node *l,*r;
}node;

node *root , *run , *now;

node* newnode(int num){
    node *temp;
    temp = (node*)malloc(sizeof(node));
    temp -> num = num;
    temp -> l = temp -> r = NULL;
    return temp;
}

void pre(node*run){
    if(run == NULL){
    return;
    }
    printf("%d ", run -> num);
    pre(run -> l);
    pre(run -> r);
}

void post(node*run){
    if(run ==NULL){
        return;
    }
    post(run -> l), post(run -> r);
    printf("%d ", run -> num);
}

void in(node*run){
    if(run == NULL){
        return;
    }
    in(run -> l);
    printf("%d ", run->num);
    in(run -> r);
}

int main(){

int n , num , i;

scanf("%d %d" , &n , &num);

root = newnode(num);
run = newnode(num);

for(i = 0 ; i < n- 1 ; i++){
    scanf("%d" , &num);
    now = newnode(num);
    run = root;
    while(1){
        if(num < run -> num){
            if(run -> l == NULL){
                run -> l = now;
                break;
            }
            run = run -> l;
        }
        else{
            if(run -> r == NULL){
                run -> r = now;
                break;
            }
            run = run -> r;
        }
    }
}
pre(root);
printf("\n");
post(root);
printf("\n");
in(root);
printf("\n");

return 0;
}

/*
5
17
6
3
14
19
*/
