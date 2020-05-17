#include<bits/stdc++.h>
using namespace std;
int n;
inline void p(int x,int t){
stack<int> ans;
for(int i=0;i<n;i++){ans.push(x&1);x>>=1;}
while(!ans.empty()){printf("%d",ans.top());ans.pop();}
}
int main(){
cin>>n;
for(int i=0;i<1<<n;i++){
for(int j=0;j<n;j++){
if((i|(1<<j))!=i){
p(i,0);printf(" ");p(i|(1<<j),0);printf("\n");
}
}
}
}

