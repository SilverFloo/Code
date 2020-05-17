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
    int n;
    cin>>n;
    vector<string> x;
    for(int i=0;i<n;i++){
        string a;
        cin>>a;
        x.pb(a);
    }
    sort(all(x));
    for(auto i:x)cout<<i<<endl;
}
