#include<bits/stdc++.h>
using namespace std;
bool stat[500006];
int main(){
int n,M,q;
scanf("%d %d %d",&n,&M,&q);
vector< pair<pair<int,int>,int> > que;
for(int i=0;i<n;i++){
int a,b;
scanf("%d %d",&a,&b);
que.push_back(make_pair(make_pair(a,0),i+1));
que.push_back(make_pair(make_pair(b,1),i+1));
}
sort(que.begin(),que.end());
int c=0;
for(int i=0;i<que.size();i++){
if(!que[i].first.second){if(c<M){c++;stat[que[i].second]=1;}}
else{if(stat[que[i].second])c--;}
}
while(q--){
int a;
scanf("%d",&a);
printf("%c ",stat[a]?'Y':'N');
}
}
