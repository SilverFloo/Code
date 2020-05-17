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
    FOR(i,n){
        string a;
        cin>>a;
        sort(all(a));
        int ch=0;
       // cout<<a<<endl;
        for(int i=1;i<a.size();i++){
            if(a[i-1]+1!=a[i]){
                    //printf("%d %d ",a[i-1]+1,a[i]);
                printf("No\n");
                ch=1;
                break;
            }
        }
        if(!ch)printf("Yes\n");
    }
}
