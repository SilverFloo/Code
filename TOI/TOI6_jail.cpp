#include<bits/stdc++.h>
using namespace std;
bool visit[(int)1e6+5];
int main(){
int n,m;
scanf("%d %d",&n,&m);
int walk=0,count=0,left=n;
while(left!=0){
if(!visit[walk%n])count++;
if(count==m){printf("%d ",walk%n+1);count=0;visit[walk%n]=1;left--;}
walk++;
}
}
