#include<bits/stdc++.h>
using namespace std;
int main(){
    int k,w,l;
    cin>>k>>w>>l;
    int m=2*k-l-w;
    char state[2*k+1];
    for(int i=0;i<k-w;i++)state[i]='A';
    for(int i=k-w;i<m;i++)state[i]='B';
    do{
    int ll=l;
    int ww=w;
    int c=0;
    for(;c<m;c++){
    if(state[c]=='B')ll++;
    else ww++;
    if(ll==k||ww==k)break;
    }
    for(int i=0;i<c+1;i++)printf("%c ",state[i]=='A'?'W':'L');printf("\n");
    }while(next_permutation(state,state+m));

}
