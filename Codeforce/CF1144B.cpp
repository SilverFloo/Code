#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<a;i++)
#define FOR1(i,a) for(int i=1;i<=a;i++)
#define db(a) printf("<%d> ",a)
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
vector<int> o,e;
int main(){
    int n;
    cin>>n;
    FOR(i,n){
        int a;
        cin>>a;
        if(a%2)o.pb(a);
        else e.pb(a);
    }
    sort(all(o));
    sort(all(e));
    if(o.size()==e.size())printf("0");
    else if(o.size()>e.size()){
        int ans=0;
        for(int i=0;i<o.size()-e.size()-1;i++)ans+=o[i];
        printf("%d",ans);
    }
    else {
        int ans=0;
        for(int i=0;i<e.size()-o.size()-1;i++)ans+=e[i];
        printf("%d",ans);
    }
}
