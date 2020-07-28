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

struct node{
    char c;
    node *par[25];
    int d;
};
node *ver[1000005];
int cv=1;
void Init(){
    ver[0]=(node*)malloc(sizeof(node));
    ver[0]->d=-1;
    for(int i=0;i<=20;i++)ver[0]->par[i]=NULL;
}
void TypeLetter(char L){
    ver[cv]=(node*)malloc(sizeof(node));
    ver[cv]->par[0]=ver[cv-1];
    ver[cv]->d = ver[cv-1]->d+1;
    ver[cv]->c = L;
    node* tmp = ver[cv-1];
    for(int i=1;i<=20;i++){
        if(tmp!=NULL)ver[cv]->par[i] = tmp->par[i-1];
        else ver[cv]->par[i]=NULL;
        tmp = ver[cv]->par[i];
    }
    cv++;
}
void UndoCommands(int U){
    ver[cv]=ver[cv-U-1];
    cv++;
}
char GetLetter(int P){
    node* tmp = ver[cv-1];
    int x = P;
    for(int i=20;i>=0;i--){
        if(tmp->par[i]==NULL)continue;
        if(tmp->par[i]->d>=x)tmp = tmp->par[i];
    }
    return tmp->c;
}
int main(){
    Init();
    while(1){
        char c;
        scanf("%c ",&c);
        if(c=='T'){
            scanf("%c",&c);
            TypeLetter(c);
        }
        if(c=='U'){
            int x;
            scanf("%d",&x);
            UndoCommands(x);
        }
        if(c=='G'){
            int x;
            scanf("%d",&x);
            printf("%c\n",GetLetter(x));
        }
    }
}