#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
bool visit[(int)5e6+5];
bool peak[(int)5e6+5];
int main(){
int n,want;cin>>n>>want;
int x[n];
for(int i=0;i<n;i++){scanf("%d",&x[i]);}
if(x[0]>x[1])peak[0]=1;
if(x[n-1]>x[n-2])peak[n-1]=1;
vector<int> anss;int c=0;
for(int i=1;i<n-1;i++){if(x[i]>x[i-1]&&x[i]>x[i+1])peak[i]=1;}
for(int i=0;i<n;i++){
if(peak[i]&&!visit[x[i]]){anss.push_back(x[i]);visit[x[i]]=1;}
}
sort(anss.begin(),anss.end(),greater<int>());
vector<int> ans;
if(anss.size()>0)ans.push_back(anss[0]);
for(int i=1;i<anss.size();i++){
if(anss[i]!=anss[i-1])ans.push_back(anss[i]);
}

if(ans.size()==0)printf("-1");
else if(ans.size()>=want){
   for(int i=0;i<want;i++){printf("%d\n",ans[i]);}
}
else{
    for(int i=ans.size()-1;i>=0;i--)printf("%d\n",ans[i]);
}
}




