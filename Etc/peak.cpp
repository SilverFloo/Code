#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
int visit[(int)5e6];
int main(){
int n,want;cin>>n>>want;
int x[n];pair<int,int> ss[n];
for(int i=0;i<n;i++){scanf("%d",&x[i]);ss[i].f=x[i];ss[i].s=i;}
sort(ss,ss+n);
int c=0;
vector<int> ans;
for(int i=n-1;i>=0&&c<want;i--){
        if(i<n-1)if(ss[i].f==ss[i+1].f&&visit[i+1]){visit[i]=1;continue;}
int pos=ss[i].s;
if(pos==0){if(x[pos+1]<x[pos]){ans.push_back(ss[i].f);c++;visit[i]=1;}}
else if(pos==n-1){if(x[pos-1]<x[pos]){ans.push_back(ss[i].f);c++;visit[i]=1;}}
else{if(x[pos+1]<x[pos]&&x[pos-1]<x[pos]){ans.push_back(ss[i].f);c++;visit[i]=1;}}
}
if(ans.size()==0)printf("-1");
else if(ans.size()>=want){
   for(auto i:ans){printf("%d\n",i);}
}
else{
    for(int i=ans.size()-1;i>=0;i--)printf("%d\n",ans[i]);

}
}
