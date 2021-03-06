//
//  Created by TaoSama on 2016-04-06
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

int n, m, a[16];
int d[1 << 17];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);
        memset(d, 0x3f, sizeof d);
        queue<int> q; q.push(0);
        d[0] = 0;
        while(q.size()) {
            int u = q.front(); q.pop();
            for(int i = 0; i < 17; ++i) {
                int v = u ^ (1 << i);
                if(d[v] == INF) {
                    d[v] = d[u] + 1;
                    q.push(v);
                }
            }
            for(int i = 1; i <= n; ++i) {
                int v = u ^ a[i];
                if(d[v] == INF) {
                    d[v] = d[u] + 1;
                    q.push(v);
                }
            }
        }

        int ans = 0;
        for(int i = 1; i <= m; ++i) {
            int s, t; scanf("%d%d", &s, &t);
            ans += 1LL * i * d[s ^ t] % MOD;
            if(ans >= MOD) ans -= MOD;
        }
        printf("%d\n", ans);
    }
    return 0;
}
