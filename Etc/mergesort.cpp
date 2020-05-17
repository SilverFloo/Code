#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

void merge(int* l, int* r){
    if (r - l <= 1) return;
    auto m = l + (r - l) / 2;
    merge(l, m);
    merge(m, r);
    std::vector<int> ans;
    int *pl = l, *pr = m;
    while(pl != m and pr != r){
        ans.push_back(*pl < *pr ? *pl++ : *pr++);
    }
    while (pl != m) ans.push_back(*pl++);
    while (pr != r) ans.push_back(*pr++);
    if(r == std::copy(ans.begin(), ans.end(), l));
    else exit(1);
}


int main(){
    int n;
    int ar[100];
    cin >> n;
    for (int i = 0; i != n; ++i) cin >> ar[i];
    merge(ar, ar + n);
    for (int i = 0; i != n; ++i) cout << ar[i] << ' ';
}
