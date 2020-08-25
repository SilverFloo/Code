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
int t[605][605];
int tab(int i,int j){
    return t[i+300][j+300];
}
void up(int i,int j,int x){
    t[i+300][j+300]=x;
}
int main(){
    // for(int i=-10;i<0;i++){
    //     for(int j=-10;j<0;j++){
    //         if(i==-5&&j==-5)continue;
    //         up(i,j,1);
    //     }
    // }
    FOR(i,10){
        int a,b;
        cin>>a>>b;
        swap(a,b);
        up(a,b,1);
    }
    ii now = {0,0};
    string s;
    cin>>s;
    
            for(int i=10;i>=-10;i--){
             for(int j=-10;j<=10;j++){
            if(now==mp(i,j)){printf("x");}else printf("%d",tab(i,j));
                }cout<<endl;
        
            }
    for(auto i:s){
        printf("%c",i);
        if(i=='U'){
            int k = now.f+1;
            while(tab(k,now.s)==1){
                k++;
            }
            up(k,now.s,1);
            up(now.f,now.s,0);
            now.f++;
        }
        if(i=='D'){
            int k = now.f-1;
            while(tab(k,now.s)==1){
                k--;
            }
            up(k,now.s,1);
            up(now.f,now.s,0);
            now.f--;
        }
        if(i=='L'){
            int k = now.s-1;
            while(tab(now.f,k)==1){
                k--;
            }
            up(now.f,k,1);
            up(now.f,now.s,0);
            now.s--;
        }
        if(i=='R'){
            int k = now.s+1;
            while(tab(now.f,k)==1){
                k++;
            }
            up(now.f,k,1);
            up(now.f,now.s,0);
            now.s++;
        }
         if(i=='/'){
            
            for(int i=20;i>=-20;i--){
                 printf("%3d ",i);
             for(int j=-10;j<=90;j++){
            if(now==mp(i,j)){printf("x");}else printf("%d",tab(i,j));
                }cout<<endl;
        
            }
        
                    string x;cin>>x;
         }
    }
}