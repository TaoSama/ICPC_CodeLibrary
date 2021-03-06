//
//  Created by TaoSama on 2016-05-08
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

int n;
vector<int> prime;
int f[N];

void gao() {
    bool vis[N] = {};
    for(int i = 2; i < N; ++i) {
        if(vis[i]) continue;
        prime.push_back(i);
        for(int j = i + i; j < N; j += i) vis[j] = true;
    }
}

//2*3*5*7*11*13   6 primes
vector<int> factorize(int x) {
    vector<int> factor;
    for(int p : prime) {
        if(x % p == 0) {
            factor.push_back(p);
            while(x % p == 0) x /= p;
        }
        if(x == 1) break;
    }
    return factor;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    gao();
    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        int ans = 0;
        memset(f, 0, sizeof f);
        for(int i = 1; i <= n; ++i) {
            int x; scanf("%d", &x);
            vector<int> factor = factorize(x);

            int cur = 0;
            for(int fac : factor) {
                f[fac] = max(f[fac], f[fac] + 1);
                cur = max(cur, f[fac]);
            }
            for(int fac : factor) f[fac] = max(f[fac], cur);
            ans = max(ans, cur);
        }
        printf("%d\n", ans);
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
