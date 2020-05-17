#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<a;i++)
#define FOR1(i,a) for(int i=1;i<=a;i++)
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
 string a,b;
int main(){

    cin>>a>>b;
    for(int i=min(a.size(),b.size());i>0;i--){
        set<vector<int>> s;
            vector<int> x(26),y(26);
            fill(all(x),0);
            fill(all(y),0);
        FOR(j,i){
            x[a[j]-'A']++;
        }
        s.insert(x);
        for(int j=i;j<a.size();j++){
            x[a[j-i]-'A']--;
            x[a[j]-'A']++;
            s.insert(x);
        }

        FOR(j,i){
            y[b[j]-'A']++;
        }
        if(s.find(y)!=s.end()){printf("%d",i);return 0;}
        for(int j=i;j<b.size();j++){
            y[b[j-i]-'A']--;
            y[b[j]-'A']++;
             if(s.find(y)!=s.end()){printf("%d",i);return 0;}
        }

    }
    printf("0");

}
