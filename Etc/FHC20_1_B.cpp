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
const int INF=1e9;
ll p[1000005];
ll q[1000005];
int main(){
    pf();
    rf();
    int T;
    cin>>T;
    FOR1(xx,T){
        int n,m,k,s;
        cin>>n>>m>>k>>s;
        FOR(i,k)scanf("%lld",&p[i]);
        
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        for(int i=k;i<n;i++){
            p[i]=(a*p[i-2]+b*p[i-1]+c)%d+1;
        }
        
        FOR(i,k)scanf("%lld",&q[i]);
        cin>>a>>b>>c>>d;
        for(int i=k;i<m;i++){
            q[i]=(a*q[i-2]+b*q[i-1]+c)%d+1;
        }
        //  FOR(i,n)printf("%lld ",p[i]);cout<<endl;
        //  FOR(i,m)printf("%lld ",q[i]);cout<<endl;
        sort(p,p+n);
        sort(q,q+m);
        //  FOR(i,n)printf("%lld ",p[i]);cout<<endl;
        //  FOR(i,m)printf("%lld ",q[i]);cout<<endl;
        ll l = 0,r = 500000000;
        ll ans = -1;
        while(l<=r){
            ll mid = (l+r)/2;
            int ptr = 0;
            int ch=0;
            FOR(i,n){
                int x = p[i]-q[ptr]<0?0:p[i]-q[ptr];
                if(x>mid){ch=1;break;}
               // printf("%d %d",x,ptr);
                while(ptr<m&&q[ptr]<=p[i])ptr++;
                if(ptr==m)break;
                int y = q[ptr]-p[i];
                while(ptr<m&&min(2*x+y,2*y+x)<=mid){
                    if(i<n-1&&q[ptr]>p[i+1])break;
                    ptr++;
                    y = q[ptr]-p[i];
                }if(ptr==m)break;
            }
           if(ptr!=m)ch=1;
            if(ch==0){ans = mid; r=mid-1;}
            else l=mid+1;
        }
    printf("Case #%d: %lld\n",xx,ans);
    }  
}