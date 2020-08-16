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
ll l[1000005];
ll h[1000005];
ll al,bl,cl,dl,ah,bh,ch,dh;
int main(){
    rf();
    pf();
    int T;
    cin>>T;
    FOR1(xx,T){
       ll n,k,w;
        cin>>n>>k>>w;
        FOR(i,k){
            scanf("%d",&l[i]);
        }
        cin>>al>>bl>>cl>>dl;
        for(int i=k;i<n;i++){
            l[i] = (al*l[i-2]+bl*l[i-1]+cl)%dl+1;
        }
        FOR(i,k){
            scanf("%d",&h[i]);
        }
        cin>>ah>>bh>>ch>>dh;
        for(int i=k;i<n;i++){
            h[i] = (ah*h[i-2]+bh*h[i-1]+ch)%dh+1;
        }
        ll lbf=-1;
        ll hbf=-1;
        ll peri=0;
        ll ans = 1;
        deque<ll> q;
        for(int i=0;i<n;i++){
            while(!q.empty()&&l[q.front()]+w<l[i])q.pop_front();
            if(lbf>=l[i]){
                peri += 2*(l[i]+w-lbf);
                if(h[i]>h[q.front()]) peri+=2*(h[i]-h[q.front()]); 
               // printf("%lld/",h[i]-h[q.front()]);   
            }
            else {
                peri += 2*h[i]+2*w;
            }
            while(!q.empty()&&h[i]>=h[q.back()])q.pop_back();
            q.pb(i);
            lbf = l[i]+w;
            ans*=peri;
            ans%=1000000007;
            peri%=1000000007;
            //printf("%lld %lld <%lld>\n",l[i],h[i],peri);
        }
         printf("Case #%d: %lld\n",xx,ans);
    }
}