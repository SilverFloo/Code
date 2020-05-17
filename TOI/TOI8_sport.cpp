#include<bits/stdc++.h>
using namespace std;
int main(){
    int k,w,l;
    cin>>k>>w>>l;
    int m=2*k-l-w;
    char state[2*k+1];
    for(int i=0;i<k-l;i++)state[i]='L';
    for(int i=k-l;i<m;i++)state[i]='W';
    do{
    int ll=l;
    int ww=w;
    int c=m-1;
    for(;c>=0;c--){
    if(state[c]=='L')ll++;
    else ww++;
    if(ll==k||ww==k)break;
    }
    for(int i=m-1;i>=c;i--)printf("%c ",state[i]);printf("\n");
    }while(next_permutation(state,state+m));

}
