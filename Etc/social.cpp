#include<bits/stdc++.h>
using namespace std;
const int MAX=1e5+5;
int par[MAX<<1];
int size[MAX<<1];
int root(int i){
while(i!=par[par[i]]){
par[i]=par[par[i]];
i=par[par[i]];
}return i;
}
void merge(int a,int b){
size[root(b)]+=size[root(a)];
par[root(a)]=root(b);
}
using namespace std;
int main(){
int q;
scanf("%d",&q);
while(q--){
int n;
scanf("%d",&n);
map<string,int> key;
int c=0;
for(int i=0;i<n;i++){
string a,b;
cin>>a>>b;
if(key.find(a)==key.end()){key[a]=c;par[c]=c;size[c]=1;c++;}
if(key.find(b)==key.end()){key[b]=c;par[c]=c;size[c]=1;c++;}
if(root(key[a])!=root(key[b]))merge(key[a],key[b]);
printf("%d\n",size[root(key[a])]);
}

}
}
