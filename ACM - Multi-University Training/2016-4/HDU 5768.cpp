//
//  Created by TaoSama on 2016-07-28
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

typedef long long LL;
LL exgcd(LL a, LL b, LL& x, LL& y) {
    LL g = a;
    if(!b) x = 1, y = 0;
    else {
        g = exgcd(b, a % b, y, x);
        y -= a / b * x;
    }
    return g;
}

int n;
LL x, y;
LL a[N], b[N], m[N];
int r[N], p[N];

pair<LL, LL> excrt(int n, LL* a, LL* b, LL* m) {
    LL B = 0, M = 1;
    for(int i = 1; i <= n; ++i) {
        LL A = (M * a[i]) % m[i], c = (b[i] - B * a[i]) % m[i];
        LL x, y, g = exgcd(A, m[i], x, y);
        if(c % g) return { -1, -1};
        x = c / g * x % (m[i] / g);
        B += x * M;
        M *= m[i] / g;
        B %= M;
    }
    B = (B + M) % M;
    if(!B) B = M;
    return {B, M};
}

LL calc(LL x, LL B, LL M) {
    LL ret = x >= B;
    ret += (x - B) / M;
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%I64d%I64d", &n, &x, &y);
        for(int i = 0; i < n; ++i) scanf("%d%d", p + i, r + i);

        LL no = 0;
        for(int s = 1; s < 1 << n; ++s) {
            int idx = 0;
            for(int i = 0; i < n; ++i) {
                if(s >> i & 1) {
                    ++idx;
                    a[idx] = 1;
                    b[idx] = r[i];
                    m[idx] = p[i];
                }
            }
            ++idx;
            a[idx] = 1, b[idx] = 0, m[idx] = 7;

            auto ret = excrt(idx, a, b, m);
            LL B, M; tie(B, M) = ret;
//            pr(s); pr(B); prln(M);
            LL tmp = calc(y, B, M) - calc(x - 1, B, M);
            if(idx - 1 & 1) no += tmp;
            else no -= tmp;
        }
//        prln(no);
        LL ans = (y / 7) - (x - 1) / 7 - no;

        static int kase = 0;
        printf("Case #%d: %I64d\n", ++kase, ans);
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
