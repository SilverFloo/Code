#include<bits/stdc++.h>
using namespace std;
int x[10005];
int main(){
int n;
scanf("%d",&n);
for(int i=0;i<n;i++){
int a;scanf("%d",&a);
x[a]++;
}
vector<int> v;
int M=0;
for(int i=0;i<=10000;i++){
if(x[i]>M){M=x[i];v.resize(0);v.push_back(i);}
else if(x[i]==M){v.push_back(i);}
}
for(int i=0;i<v.size();i++)printf("%d ",v[i]);
}
