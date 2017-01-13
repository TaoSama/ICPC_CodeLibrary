//
//  Created by TaoSama on 2016-12-30
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
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

int n;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n) {
        int d = 0; bool ok = true;
        for(int i = 1; i <= n; ++i) {
            int x; string dir; cin >> x >> dir;
            if(dir == "South") {
                d += x;
                if(d > 20000) {
                    ok = false;
                }
            } else if(dir == "North") {
                d -= x;
                if(d < 0) {
                    ok = false;
                }
            } else {
                if(d == 0 || d == 20000) ok = false;
            }
        }
        ok &= d == 0;
        cout << (ok ? "YES" : "NO") << endl;
    }

    return 0;
}
