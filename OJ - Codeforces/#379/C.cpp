//
//  Created by TaoSama on 2016-11-16
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
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m, k;
int x, s;
int a[N], b[N], c[N], d[N];

typedef long long LL;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d%d%d%d", &n, &m, &k, &x, &s) == 5) {
        for(int i = 1; i <= m; ++i) scanf("%d", a + i);
        for(int i = 1; i <= m; ++i) scanf("%d", b + i);
        for(int i = 1; i <= k; ++i) scanf("%d", c + i);
        for(int i = 1; i <= k; ++i) scanf("%d", d + i);

        LL ans = 1LL * n * x;
        for(int i = 1; i <= k; ++i) {
            if(s < d[i]) break;
            ans = min(ans, 1LL * (n - c[i]) * x);
        }
        for(int i = 1; i <= m; ++i) {
            if(s < b[i]) continue;
            int idx = upper_bound(d + 1, d + 1 + k, s - b[i]) - d - 1;
            ans = min(ans, 1LL * (n - c[idx]) * a[i]);
        }
        printf("%I64d\n", ans);
    }

    return 0;
}
