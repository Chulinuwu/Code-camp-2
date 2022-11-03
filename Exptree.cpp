#include <bits/stdc++.h>

using namespace std;

char str[300],node[300];
int l[300],r[300],cnt =1;

stack <int> st;

void in(int i){
    if(l[i]){
        printf("(");
        in(l[i]);
    }
    printf("%c", node[i]);
    if(r[i]){
        in(r[i]);
        printf(")");
    }
}

void pre(int i){
    printf("%c", node[i]);
    if(l[i]){
        pre(l[i]);
    }
    if(r[i]){
        pre(r[i]);
    }
}

int main(){

    int len,i;
    gets(str);
    len =strlen (str);

    for(i = 0 ; i < len ; i++){
        if(isalpha(str[i])){
            node[cnt] = str[i];
            st.push(cnt++);
        }

        else if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/'){
            node[cnt] = str[i];
            r[cnt] = st.top();
            st.pop();
            l[cnt] = st.top();
            st.pop();
            st.push(cnt++);
        }
    }
    in(cnt-1);
    printf("\n");
    pre(cnt-1);
    printf("\n");


    return 0;

}
