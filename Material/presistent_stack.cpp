#include<bits/stdc++.h>
template <class T,int n>
class p_stack {
    int v=0;
    int vtop[n];
    T data[n];
    int bf[n];
  public:
    p_stack(){
        vtop[0]=0;
    }
    void push(int ver,T d){
        v++;
        vtop[v]=v;
        data[v]=d;
        bf[v]=vtop[ver];
    }
    void pop(int ver){
        v++;
        vtop[v]=bf[ver];
    }
    T top(int ver){
        return data[vtop[ver]];
    }
    int cur_ver(){
        return v;
    }
    int empty(int ver){
        db(vtop[ver]);
        return vtop[ver]==0;
    }
};

int main(){
}
