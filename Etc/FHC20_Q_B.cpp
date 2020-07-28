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
vector<int> tab;
int main(){
    rf();
    pf();
    int q;
    cin>>q;
    FOR1(x,q){
        int n;
        cin>>n;
        tab.clear();
        FOR(i,n){
            char c;
            cin>>c;
            if(c=='A')tab.pb(0);
            else tab.pb(1);
            if(tab.size()>=3){
                int x = tab[tab.size()-1]+tab[tab.size()-2]+tab[tab.size()-3];
                if(x==1){
                    tab.pop_back();
                    tab.pop_back();
                    tab.pop_back();
                    tab.push_back(0);
                }
                if(x==2){
                    tab.pop_back();
                    tab.pop_back();
                    tab.pop_back();
                    tab.push_back(1);
                }
            }
        }
        printf("Case #%d: %c\n",x,tab.size()==1?'Y':'N');
    }

}