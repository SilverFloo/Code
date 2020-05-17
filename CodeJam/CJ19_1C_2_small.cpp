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
int cnt[5000];
int full[5000];
int tab[5];
string pattern[120];
string ans;
int t;
int intl(){
    cin>>ans;
    string s="ABCDE";
    int cnt=0;
    if(s!=ans)pattern[cnt++]=s;
    while(next_permutation(all(s))){
        if(s!=ans)pattern[cnt++]=s;
    }
}
int get(int x){t++;
    return pattern[x/5][x%5];

}


int fac(int n){
    int ans=1;
    for(int i=1;i<=n;i++)ans*=i;
    return ans;
}
int main(){
    int T,F;
    cin>>T>>F;
    while(T--){
            intl();
        FOR(i,5000)cnt[i]=0;
        FOR(i,5000)full[i]=0;
        int ptr = 2;
        for(int i=0;i<119;i++){
            int now = 1;
            for(int j=0;j<5;j++)tab[j]=0;
            for(int j=0;j<5;j++){
                while(1){
                    int x=0;
                    for(int k=0;k<5;k++)if(full[5*now+k]||tab[k])x++;
                    if(x==4){
                        for(int k=0;k<5;k++)
                            if(full[5*now+k]||tab[k]){}
                            else{
                                cnt[now]++;
                                if(cnt[now] == fac(5-j))full[now]=1;
                                now=5*now+k;j++;
                                tab[k]=1;
                                break;
                            }
                    }
                    else break;
                    if(j==5)break;
                }
                if(j==5)break;
               /*
               printf("%d",5*i+j+1);

                fflush(stdout);
                char x;
                scanf(" %c",&x);*/
                char x = get(5*i+j);
                cnt[now]++;
                if(cnt[now] == fac(5-j)){if(now==1)printf("%d %d//",now,cnt[now]);full[now]=1;}
                now = 5*now+x-'A';
                tab[x-'A']=1;
            }
        }
        FOR(i,5)tab[i]=0;
        int now = 1;
        int ans[5];

        for(int i=0;i<4;i++){
            for(int j=0;j<5;j++){
                    printf("%d ",full[5*now+j]);
                if(!full[5*now+j]&&!tab[j]){printf("%c",'A'+j);tab[j]=1;now=5*now+j;break;}
            }printf("\n");
        }printf("\n");
        for(int j=0;j<5;j++){
                    printf("%d ",full[5*now+j]);
                if(!full[5*now+j]&&!tab[j]){printf("%c",'A'+j);tab[j]=1;now=5*now+j;break;}
            }
       // cout<<t;
        //fflush(stdout);
        char c;
        scanf(" %c",&c);
        if(c=='N')exit(0);
        //f(c=='Y')
    }
}

