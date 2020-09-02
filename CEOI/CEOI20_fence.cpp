#include<bits/stdc++.h>
#define FOR(i,n) for(int i=0;i<n;i++)
#define ll long double
#define f first
#define s second
using namespace std;
ll h[100005],w[100005];
ll mod = (1e9)+7;
ll cal(ll h, ll w){
    if(fmod(h,2)==0&&fmod(w,2)==0) return fmod(fmod(fmod(fmod(h+1,mod)*fmod(w+1,mod),mod)*fmod(h/2,mod),mod)*fmod(w/2,mod),mod);
    else if(fmod(h,2)==1&&fmod(w,2)==1)return fmod(fmod(fmod(fmod((h+1)/2,mod)*fmod((w+1)/2,mod),mod)*fmod(h,mod),mod)*fmod(w,mod),mod);
    else if(fmod(h,2)==1)return fmod(fmod(fmod(fmod(fmod(h+1,mod)/2,mod)*(fmod(w+1,mod)),mod)*fmod(h,mod),mod)*fmod(w/2,mod),mod);
    else return fmod(fmod(fmod(fmod((h+1),mod)*fmod((w+1)/2,mod),mod)*fmod(h/2,mod),mod)*fmod(w,mod),mod);
}
ll caldown(ll h,ll w){
    if(fmod(w,2)==0)return fmod(fmod(fmod(w/2,mod)*fmod(w+1,mod),mod)*fmod(h,mod),mod);
    else return fmod(fmod(fmod((w+1)/2,mod)*fmod(w,mod),mod)*fmod(h,mod),mod);
}
int main(){
    //freopen("_working/input.in","r",stdin);

    int n;
    cin>>n;
    FOR(i,n)scanf("%Lf",&h[i]);
    FOR(i,n)scanf("%Lf",&w[i]);
    stack<pair<ll,ll>> q;
    q.emplace(0,0);
    ll cnt = 0;
    ll ans = 0;
    for(int i=0;i<n;i++){
        ll stbf=cnt;
        while(q.top().f>h[i]){
            ll st=q.top().s;
            stbf = q.top().s;
            ll height = q.top().f;
            q.pop();
            //cout<<fmod(cal(height - max(q.top().f,h[i]),cnt-st),mod);
            ans+=fmod(cal(height - max(q.top().f,h[i]),cnt-st),mod);
            ans=fmod(ans,mod);
            ans+=fmod(fmod(height - max(q.top().f,h[i]),mod)*fmod(caldown(max(q.top().f,h[i]),cnt-st),mod),mod);
            ans=fmod(ans,mod);
        }
        if(q.top().f<h[i]){
            q.emplace(h[i],stbf);
        }
        cnt+=w[i];
    }
    while(q.size()>1){
       ll st=q.top().s;
        ll height = q.top().f;
        q.pop();
           // cout<<fmod(cal(height - q.top().f,cnt-st),mod)<<' ';
        ans+=fmod(cal(height - q.top().f,cnt-st),mod);
        ans=fmod(ans,mod);
        ans+=fmod(fmod(height - q.top().f,mod)*fmod(caldown(q.top().f,cnt-st),mod),mod);
        ans=fmod(ans,mod);
    }
    printf("%.0Lf",fmod(ans,mod));
    //cout<<fmod(ans,mod);

}