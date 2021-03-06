//
//  Created by TaoSama on 2016-05-10
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
const int N = 1e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;
int n, m, q[N];
LL f[2][N]; // f[j][i]:= j段到i的最小值
LL s[N], s2[N]; //sum, square sum

//f[j][i] = min { 2f[k] + [ (s[i] - s[k])^2 - (s2[i] - s2[k]) ] / 2 }
//slope(k, j):= { (2f[j]+s[j]*s[j]+s2[j])-(2f[k]+s[k]*s[k]+s2[k]) } /
// { 2(s[j] - s[k]) } <= s[i]

LL up(int p, int k, int j) {
    return (2 * f[p][j] + s[j] * s[j] + s2[j]) -
           (2 * f[p][k] + s[k] * s[k] + s2[k]);
}

LL dw(int k, int j) {
    return 2 * (s[j] - s[k]);
}

bool check(int p, int k, int j, int i) {
    return up(p, k, j) * dw(j, i) >= up(p, j, i) * dw(k, j);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    while(scanf("%d%d", &n, &m) == 2 && (n || m)) {
        for(int i = 1; i <= n; ++i) {
            scanf("%I64d", s + i);
            s2[i] = s2[i - 1] + s[i] * s[i];
            s[i] += s[i - 1];
//            printf("s[%d] = %I64d, s2[%d] = %I64d\n", i, s[i], i, s2[i]);
        }

        int p = 0;
        for(int i = 0; i <= n; ++i) {
            f[p][i] = (s[i] * s[i] - s2[i]) / 2;
//            printf("f[0][%d] = %I64d\n", i, f[p][i]);
        }

        for(int j = 1; j <= m; ++j) {
            int L = 0, R = 0;
            q[R++] = 0;
            for(int i = 1; i <= n; ++i) {
                while(L + 1 < R && up(p, q[L], q[L + 1]) <= s[i] * dw(q[L], q[L + 1]))
                    ++L;
                int k = q[L];
                f[!p][i] = f[p][k] + ((s[i] - s[k]) * (s[i] - s[k]) -
                                      (s2[i] - s2[k])) / 2;
                while(L + 1 < R && check(p, q[R - 2], q[R - 1], i)) --R;
                q[R++] = i;
            }
            p = !p;
        }
        printf("%I64d\n", f[p][n]);
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
