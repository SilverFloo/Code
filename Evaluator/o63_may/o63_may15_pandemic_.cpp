#include<bits/stdc++.h>
#include "pandelib.cpp"
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
assignment_t a[100000];
bool results[100000];
int n,k,l;
int main(){
    rf();
    pandemic_init(n,k,l);
    for(int i=2;1<<i<n;i++){
        int cnt=0;
        for(int j=1;j<=n;j++){
            a[i-1].pb(j-1);
           // printf("%d ",j-1);
            cnt++;
            if(cnt==1<<i){
                j+=1<<i;
                cnt=0;
            }

        }//cout<<endl;
    }
    for(int i=0;i<n;i+=4){
        a[0].pb(i);
    }
    pandemic_assign(a,results);

    for(int i=0; i<k; i++)a[i].clear();
    
    for(int i=1;i<n;i+=4){
        a[0].pb(i);
    }
    pandemic_assign(a,results);
    for(int i=0; i<k; i++)a[i].clear();
    for(int i=2;i<n;i+=4){
        a[0].pb(i);
    }
    
    pandemic_assign(a,results);
    for(int i=0; i<k; i++)a[i].clear();
    for(int i=3;i<n;i+=4){
        a[0].pb(i);
    }
    pandemic_assign(a,results);
    for(int i=1; i<k; i++)a[i].clear();
    for(int i=0;i<27;i++){
        pandemic_assign(a,results);
    }
    int x=0;
    while((1<<x)<n)x++;
    int l=0,r=(1<<x)-1;

    while(l!=r){
        
        int m=(l+r)/2;
        if(results[x-2]){r=m;}
        else l=m+1;
        x--;
        if(x==2)break;
    }
    //printf("%d %d",l,r);
    
    if(results[0])pandemic_answer(l);
    pandemic_assign(a,results);
    if(results[0])pandemic_answer(l+1);
    pandemic_assign(a,results);
    if(results[0])pandemic_answer(l+2);
    pandemic_assign(a,results);
    if(results[0])pandemic_answer(l+3);


}