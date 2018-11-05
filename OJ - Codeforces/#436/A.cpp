
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;



int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n; cin >> n;
    map<int, int> mp;
    for(int i = 1; i <= n; ++i) {
        int x; cin >> x;
        mp[x]++;
    }
    if(mp.size() == 2) {
        auto iter = mp.begin();
        auto iter2 = mp.rbegin();
        if(iter->second == iter2->second) {
            cout << "YES\n";
            cout << iter->first << ' ' << iter2->first << endl;
        }
        else cout << "NO\n";
    }
    else cout << "NO\n";
    return 0;
}
