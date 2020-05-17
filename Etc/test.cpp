#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> s;
    int x;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        s.emplace_back(x);
    }
    for(auto i:s)
    cout<<"hello"<<i<<endl;
}