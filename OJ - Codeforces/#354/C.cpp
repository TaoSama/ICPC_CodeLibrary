//
//  Created by TaoSama on 2016-05-25
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

int n, k;
char s[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    while(scanf("%d%d%s", &n, &k, s + 1) == 3) {
        int a, b, ans = 0;
        a = b = 0;
        for(int l = 1, r = 1; l <= n; ++l) {
            while(r <= n && b + (s[r] == 'b') <= k)
                b += (s[r++] == 'b');
            ans = max(ans, r - l);
            b -= s[l] == 'b';
        }
        for(int l = 1, r = 1; l <= n; ++l) {
            while(r <= n && a + (s[r] == 'a') <= k)
                a += (s[r++] == 'a');
            ans = max(ans, r - l);
            a -= s[l] == 'a';
        }
        printf("%d\n", ans);
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
