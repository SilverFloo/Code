#include<bits/stdc++.h>
using namespace std;
int main(){
int n;
scanf("%d",&n);
vector < int > x;
for(int i=0;i<n;i++){
int d;
scanf("%d",&d);
x.push_back(d);
}
int ans=0;
while(x.size()!=0&&x.size()!=1){
int Ma=0,pos=0;
for(int i=0;i<x.size()-1;i++){
if(fabs(x[i+1]-x[i])>Ma){Ma=fabs(x[i+1]-x[i]);pos=i;}
}
ans+=Ma;

x.erase(x.begin()+pos,x.begin()+pos+2);

}
printf("%d",ans);
}
