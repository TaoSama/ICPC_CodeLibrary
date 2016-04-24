//
//  Created by TaoSama on 2016-04-24
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <vector>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n >> m) {
        string s, t;
        for(int i = 1; i <= n; ++i) {
            cin >> t;
            s += t;
        }
        for(int i = 0; i < s.size(); ++i) s[i] = tolower(s[i]);
        cin >> t;
        for(int i = 0; i < t.size(); ++i) t[i] = tolower(t[i]);
        if(s.find(t) != string::npos) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
