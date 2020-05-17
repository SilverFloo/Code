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
#define rf() freopen("input.txt","r",stdin)
using namespace std;
vector<string> l,m,r;
bool cmp(string l,string r){
    return l.size()<r.size();
}
int main(){
    int t;
    cin>>t;
    FOR1(k,t){
        int n;
        cin>>n;
        int ch=0;
        string ans;
        FOR(i,n){
            string s;
            cin>>s;
            int p=-1;
            if(s[0]=='*'&&s[s.size()-1]=='*'){
                m.pb(s);
            }
            else{

                    for(int j=0;j<s.size();j++){
                        if(s[j]=='*'){p=j;break;}
                    }
                    if(p==-1&&ch==0)ch=1,ans=s;
                    else if(ans!=s&&p==-1)ch=2;
                    else l.push_back(s.substr(0,p));

                int pp=-1;
                    for(int j=s.size()-1;j>=0;j--){
                        if(s[j]=='*'){pp=j;break;}
                    }
                    if(pp==-1&&ch==0)ch=1,ans=s;
                    else if(ans!=s&&pp==-1)ch=2;
                    else r.push_back(s.substr(pp+1));

                if(p!=-1&&pp!=-1)m.push_back(s.substr(p,pp-p));
            }
        }
        sort(all(l),cmp);
        sort(all(r),cmp);
        for(auto s:l){
            for(int i=0;i<s.size();i++){
                if(s[i]!=l[l.size()-1][i])ch=2;
            }
        }
        for(auto s:r){
            for(int i=0;i<s.size();i++){
                    int a=s.size();
                int b=r[r.size()-1].size();
               // cout<<a-i-1<<' '<<b-i-1<<endl;
                if(s[a-i-1]!=r[r.size()-1][b-i-1])ch=2;
            }
        }

        printf("Case #%d: ",k);
        if(ch==0){
            if(!l.empty())cout<<l[l.size()-1];
            for(auto s:m){
                for(auto a:s){
                    if(a!='*')cout<<a;
                }
            }
            if(!r.empty())cout<<r[r.size()-1];
        }
        else if(ch==1){
            cout<<ans;
        }
        else{
            cout<<'*';
        }
        cout<<endl;
        l.clear();
        r.clear();
        m.clear();
    }
}
/*
10000
3
*ABDFS*
ASDDASDF*
*DSF*sdfs*dsdfa
10000
3
*1*
2*
*3*4*5
*/
