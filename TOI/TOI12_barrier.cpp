#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<a;i++)
#define FOR1(i,a) for(int i=1;i<=a;i++)
using namespace std;
int house[(int)6e6+5];
int main(){
int n,k;
scanf("%d %d",&n,&k);
FOR1(i,n){scanf("%d",&house[i]);house[i]+=house[i-1];}
deque<int> q;
int ans1=0,ans2=0;
FOR(i,n+1){
while(!q.empty()&&house[q.back()]>house[i])q.pop_back();
q.push_back(i);
while(q.front()<i-k)q.pop_front();
if(house[i]-house[q.front()]>ans1){ans1=house[i]-house[q.front()];ans2=i-q.front();}
if(house[i]-house[q.front()]==ans1){ans2=i-q.front();}
//printf("%d ",house[i]-house[q.front()]);
}
printf("%d\n%d",ans1,ans2);


}
