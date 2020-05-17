#include<bits/stdc++.h>
#define FOR(i,n) for(int i=0;i<n;i++)
#define pb push_back
#include "sockslib.h"
using namespace std;
vector<int> vec;
vector<int> tmp;
int n;




void find(vector<int> v,int sz){
    //printf("<");
    //for(auto i:v)printf("%d ",i );
     //printf(">\n");
    if(sz==3){
          //  printf("<%d>",ask(v));
            vector<int> x;
            x.pb(v[0]);
            x.pb(v[1]);
        if(ask(x)==1){
            match(v[0],v[1]);
            tmp.pb(v[2]);
            return;
        }
            x.clear();
            x.pb(v[1]);
            x.pb(v[2]);
        if(ask(x)==1){

            match(v[1],v[2]);
            tmp.pb(v[0]);
            return;
        }
         x.clear();
            x.pb(v[0]);
            x.pb(v[2]);
        if(ask(x)==1){
            match(v[0],v[2]);
            tmp.pb(v[1]);
            return;
        }
        return;
    }
    if(sz==2){match(v[0],v[1]);return;}



vector<int> a,b;
    int ch=0;
    for(int i=0;i<sz/2;i++){a.pb(v[i]);}
    for(int i=sz/2;i<sz;i++)b.pb(v[i]);
    if(ask(a)!=a.size())find(a,a.size()),ch=1;
    else if(ask(b)!=b.size())find(b,b.size()),ch=ch==1?3:2;
    if(ch==1){

        for(auto i:b)tmp.pb(i);
    }
    if(ch==2){
        for(auto i:a)tmp.pb(i);
    }

    if(ch==0){
        a.clear();
        b.clear();
        for(int i=0;i<sz/4;i++){a.pb(v[i]);}
        for(int i=sz/2;i<3*sz/4;i++){a.pb(v[i]);}
        for(int i=sz/4;i<sz/2;i++)b.pb(v[i]);
        for(int i=3*sz/4;i<sz;i++)b.pb(v[i]);
        if(ask(a)!=a.size())find(a,a.size()),ch=1;
        else if(ask(b)!=b.size())find(b,b.size()),ch=ch==1?3:2;
        if(ch==1){
            for(auto i:b)tmp.pb(i);
        }
        //printf("<<<%d>>",ask(b));
        if(ch==2){
            for(auto i:a)tmp.pb(i);
        }

        if(ch==0){
            a.clear();
            b.clear();
            for(int i=0;i<sz/4;i++){
                a.pb(v[i]);
            }
            for(int i=sz/4;i<3*sz/4;i++){
                b.pb(v[i]);
            }
            for(int i=3*sz/4;i<sz;i++){
                a.pb(v[i]);
            }
            if(ask(a)!=a.size())find(a,a.size()),ch=1;
            else if(ask(b)!=b.size())find(b,b.size()),ch=ch==1?3:2;
            if(ch==1){
                for(auto i:b)tmp.pb(i);
            }
            if(ch==2){
                for(auto i:a)tmp.pb(i);
            }
        }
    }
}
int main(){
    n=num();
    for(int i=1;i<=n<<1;i++)vec.pb(i);
    while(!vec.empty()){
        find(vec,vec.size());
        vec.clear();
        for(auto i:tmp)vec.pb(i);
        tmp.clear();
      //  printf("/break/");
    }
}
