#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<a;i++)
#define FOR1(i,a) for(int i=1;i<=a;i++)
#define f first
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb emplace_back
#define p emplace
#define ii pair<int,int>
#define ll long long
using namespace std;
const int INF=1e9;
bool s(char a){
    if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u')return 1;
    return 0;

}
int main(){
    int n;
    cin>>n;
    FOR(j,n){
        char x[105];
        scanf("%s",x);
        int pos1=-1,pos2=-1;
        vector<char> a,b;
        for(int i=0;i<strlen(x);i++){
            if(s(x[i])){
                pos1=i;
                a.pb(x[i]);
                while(i<strlen(x)&&s(x[i+1])){
                    i++;
                    a.pb(x[i]);
                }
                break;
            }
        }
        for(int i=strlen(x)-1;i>=0;i--){
            if(s(x[i])){
                b.pb(x[i]);
                pos2=i;
                while(i>=0&&s(x[i-1])){
                    i--;
                    b.pb(x[i]);
                    pos2=i;
                }
                break;
            }
        }
        if(pos1==-1&&pos2==-1){
            printf("%s\n",x);
            continue;

        }
        for(int i=0;i<strlen(x);i++){
            if(pos1==i){
                for(int k=b.size()-1;k>=0;k--)printf("%c",b[k]);

                i++;
                while(s(x[i-1])&&s(x[i]))i++;
                i--;
            }
            else if(pos2==i){
               for(auto k:a)printf("%c",k);
                i++;
                while(s(x[i-1])&&s(x[i]))i++;
                i--;
            }
            else printf("%c",x[i]);

        }printf("\n");
    }
}
