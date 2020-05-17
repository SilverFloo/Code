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
#define rf() freopen("_working/input.in","r",stdin)
#define pf() freopen("_working/output.out","w+",stdout)
using namespace std;
int sum(int x){
    return x*(x+1)/2;
}
int main(){
    rf();pf();
    int t;
    cin>>t;
    FOR(k,t){
        int l,r;
        cin>>l>>r;
        int cnt=1;
        while(l>=0&&r>=0){
            if(cnt>max(l,r))break;
            if(l>=r)l-=cnt;
            else r-=cnt;
            cnt++;
        }

        printf("Case #%d: %d %d %d\n",k+1,cnt-1,l,r);


    }
    
}