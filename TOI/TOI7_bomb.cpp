#include<bits/stdc++.h>
#define push push_back
#define s second
#define f first
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
using namespace std;
bool cmp(pii a,pii b){
if(a.f==b.f)return a.s>b.s;
return a.f<b.f;
}
int main(){
int n;
cin>>n;
vector<pair<int,int> > point;
for(int i=0;i<n;i++){int a,b;
scanf("%d %d",&a,&b);
point.emplace_back(a,b);
}
sort(point.begin(),point.end(),cmp);
vector<pair<int,int>> ans;
int mx=-2e9;int now;
for(int i=n-1;i>=0;i--){
if(point[i].s>=mx){mx=point[i].s;now=point[i].f;
ans.emplace_back(point[i].f,point[i].s);
}
}
sort(all(ans),cmp);
for(auto i:ans){printf("%d %d\n",i.f,i.s);}
}
