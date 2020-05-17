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
int tab[200005];
int main(){
    int n;
    cin>>n;
    FOR(i,n){
        char c;
        scanf(" %c",&c);
        tab[i]+=c-'a';
    }
    FOR(i,n){
        char c;
        scanf(" %c",&c);
        tab[i]+=c-'a';
    }
    for(int i=n-1;i>0;i--){
        if(tab[i]>=26)tab[i]-=26,tab[i-1]++;
    }
    for(int i=0;i<n;i++){
        printf("%c",tab[i]/2+'a');
        if(tab[i]%2)tab[i+1]+=26;
    }

}
