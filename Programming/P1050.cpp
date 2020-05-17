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
int n,k;
vector<vector<int>> val;
vector<int> want;
bool cmp(vector<int> x,vector<int> y){
FOR(i,k){
if(x[i]!=y[i])return x[i]<y[i];
}
}
bool eq(vector<int> x,vector<int> y){
FOR(i,k){
if(x[i]!=y[i])return 0;
}
return 1;
}
int find(vector<int> x){
    int l=0,r=n-1;
    while(l<=r){
int mid=(l+r)/2;
if(eq(val[mid],x))return mid;
else if(!cmp(val[mid],x))r=mid-1;
else l=mid+1;
}
return -1;
}
int main(){
    cin>>n>>k;
    FOR(i,n){
    vector<int> a;
    FOR(j,k){
    int x;
    scanf("%d",&x);
    a.pb(x);
    }
    a.pb(i+1);
    val.pb(a);
    }

    FOR(i,k){
    int x;
    scanf("%d",&x);
    want.pb(x);
    }

    sort(all(val),cmp);
    int x=find(want);
    if(x!=-1){printf("%d",val[x][k]);exit(0);}


    FOR(i,n){
    vector<int> a;
    FOR(j,k){
    a.pb(want[j]-val[i][j]);
    }
    int x=find(a);
    if(x!=-1&&x!=i){printf("%d %d",val[i][k],val[x][k]);exit(0);}
    }
    printf("NO");
}
