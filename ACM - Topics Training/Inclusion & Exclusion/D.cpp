//
//  Created by TaoSama on 2015-10-24
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
//#pragma comment(linker, "/STACK:1024000000,1024000000")
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

vector<int> factor[N];
void gao() {
    bool vis[N] = {};
    for(int i = 2; i < N; ++i) {
        if(vis[i]) continue;
        for(int j = i; j < N; j += i) {
            vis[j] = true;
            factor[j].push_back(i);
        }
    }
}

int calc(int k, int x) {
    int ret = 0;
    int sz = factor[k].size();
    for(int s = 1; s < 1 << sz; ++s) {
        int cnt = 0, mul = 1;
        for(int i = 0; i < sz; ++i)
            if(s >> i & 1) ++cnt, mul *= factor[k][i];
        if(cnt & 1) ret += x / mul;
        else ret -= x / mul;
    }
    return x - ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    gao();
    while(t--) {
        int n, m; scanf("%d%d", &n, &m);
        if(n > m) swap(n, m);
        long long ans = 0;
        for(int i = 1; i <= n; ++i) ans += calc(i, m);
        printf("%I64d\n", ans);
    }
    return 0;
}
