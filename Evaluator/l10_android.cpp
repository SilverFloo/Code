#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<a;i++)
#define FOR1(i,a) for(int i=1;i<=a;i++)
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb emplace_back
#define p emplace
#define ii pair<int,int>
#define ll long long
using namespace std;
const int INF=1e9;

int main(){
list<int> pro;
int p,s,m;
scanf("%d %d %d",&p,&s,&m);
int me[p];
for(int i=0;i<p;i++){scanf("%d",&me[i]);}
for(int i=0;i<s;i++){
int a;
scanf("%d",&a);
a--;
list<int>::iterator it;
for(it=pro.begin();it!=pro.end();it++){
if(*it==a){break;}
}
if(it==pro.end()){
while(me[a]>m){
m+=me[pro.front()];
pro.pop_front();
}
pro.push_back(a);
m-=me[a];
}
else{
pro.erase(it);
pro.push_back(a);
}

}
printf("%d",m);
}
