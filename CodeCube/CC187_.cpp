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
const int INF=1e9;
struct node{
    int pr,cnt;
    char val;
    bool rev=0;
    node *l=NULL,*r=NULL;
};
int cnt(node* p){
    return p==NULL?0:p->cnt;
}
void push(node* p){
    if(p!=NULL&&p->rev==1){
        p->rev=0;
        swap(p->l,p->r);
        if(p->l!=NULL)p->l->rev^=1;
        if(p->r!=NULL)p->r->rev^=1;
    }
}
void merge(node* &t,node* l,node* r){
    push(l);
    push(r);
    if(l==NULL)t=r;
    else if(r==NULL)t=l;
    else if(l->pr>r->pr){
        merge(l->r,l->r,r);
        t=l;
    }
    else{
        merge(r->l,l,r->l);
        t=r;
    }
    if(t!=NULL)t->cnt = cnt(t->l)+cnt(t->r)+1;
}
void split(node* t,node* &l,node* &r,int key,int add=0){
    if(t==NULL){
        l=r=NULL;return;
    }
    push(t);
    int cur = add+cnt(t->l);
    if(key<=cur){
        split(t->l,l,t->l,key,add);
        r=t;
    }
    else{
        split(t->r,t->r,r,key,add+cnt(t->l)+1);
        l=t;
    }
    if(t!=NULL)t->cnt = cnt(t->l)+cnt(t->r)+1;
}
void print(node* t,int cnt=0){
    if(t==NULL)return;
    push(t);
    print(t->l,cnt+1);
  //  FOR(i,cnt)printf("   ");
    printf("%c",t->val,t->pr);
    print(t->r,cnt+1);
}
void reverse(node* t,int l,int r){
    node *t1,*t2,*t3;
    split(t,t1,t2,l);
    split(t2,t2,t3,r-l+1);
    //print(t1);print(t2);print(t3);
    t2->rev ^= 1;
    merge(t,t1,t2);
    merge(t,t,t3);
}
void insert(node* &t,node* it,int pos,int add=0){
    if(t==NULL){t=it;return;}
    push(t);
    int cur = add+cnt(t->l);
    if(it->pr>t->pr){
        split(t,it->l,it->r,pos);
        t=it;
    }
    else if(cur>pos){
        insert(t->l,it,pos,add);
    }
    else{
        insert(t->r,it,pos,add+cnt(t->l)+1);
    }
}
int main(){
    srand(time(NULL));
    string s;
    cin>>s;
    node* t=NULL;
    for(int i=0;i<s.size();i++){
        node* tmp = (node*)malloc(sizeof(node));
        tmp->pr=rand();
        tmp->l=NULL;
        tmp->rev=0;
        tmp->r=NULL;
        tmp->val=s[i];
        insert(t,tmp,i);
        //cout<<endl;
       // print(t);
       // cout<<endl;
    }
    int q;
    cin>>q;
    while(q--){
        char c;
        cin>>c;
        if(c=='I'){
            int p;
            string s;
            cin>>p>>s;
            p--;
            for(int i=0;i<s.size();i++){
                node* tmp = (node*)malloc(sizeof(node));
                tmp->pr=rand();
                tmp->val=s[i];
                tmp->rev=0;
                tmp->l=NULL;
                tmp->r=NULL;
                insert(t,tmp,p+i);
        //        cout<<endl;
      //  print(t);
      //  cout<<endl;
            }
        }
        else{
            int a,b;
            cin>>a>>b;
            reverse(t,a-1,b-1);
        }
       // print(t);
        //cout<<endl;
    }
    print(t);
}
