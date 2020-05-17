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
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    FOR(i,n-1){
        if(s[i]>s[i+1]){
            printf("YES\n%d %d",i+1,i+2);
            return 0;
        }
    }
    printf("NO");
}
