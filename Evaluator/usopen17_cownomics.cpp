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
string s1[505],s2[505];

int main(){
    int n,m;
    cin>>n>>m;
    FOR(i,n)cin>>s1[i];
    FOR(i,n)cin>>s2[i];
    int l=1,r=n;
    int ans=0;
    while(l<=r){
        int mid=(l+r)/2;
        for(int i=0;i<=m-mid;i++){
            printf("\n%d>>",mid);
            set<string> check;
            for(int j=0;j<n;j++){
                check.insert(s1[j].substr(i,mid));
            }
            int cnt=0;
            for(int j=0;j<n;j++){
                if(check.find(s2[j].substr(i,mid))==check.end()){cnt++;}
                else break;
            }
            printf(" %d",cnt);
            if(cnt==n){printf("%d",mid);return 0;}
        }
    }

}
