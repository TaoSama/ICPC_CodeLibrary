
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
    
    string s; 
    while(cin >> s) {
        int ans = 0;
        for(char c : s) {
            if(string("aeiou").find(c) != string::npos) ++ans;
            else if(isdigit(c)) {
                ans += (c - '0') % 2 == 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
