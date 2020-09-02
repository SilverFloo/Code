#include "boxes.h"
#define ll long long
#include<bits/stdc++.h>
using namespace std;
ll l[10000005],r[10000005];
long long delivery(int N, int K, int L, int p[]) {
    for(int i=0;i<N;i++){
        if(i<K) l[i]=2*p[i];
        else l[i]=l[i-K]+2*p[i];
    }
    for(int i=N-1;i>=0;i--){
        if(i>N-1-K)r[i]=2*(L-p[i]);
        else r[i]=r[i+K]+2*(L-p[i]);
    }
    ll ans = 1e18;
    for(int i=-1;i<N;i++){
        ll x =0,y=0;
        if(i>=0)x+=l[i],y+=l[i];
        if(i<N-1)x+=r[i+1];
        if(i<N-K-1)y+=r[i+K+1];
        y+=L;
        ans = min(ans,x);
        ans = min(ans,y);
    }
    return ans;
}