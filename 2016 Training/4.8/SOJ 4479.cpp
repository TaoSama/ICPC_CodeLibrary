//
//  Created by TaoSama on 2016-04-09
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
pair<int, int> a[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) scanf("%d%d", &a[i].first, &a[i].second);
        sort(a + 1, a + 1 + n);
        int ans = a[1].second - a[1].first, r = a[1].second;
        for(int i = 2; i <= n; ++i) {
            if(a[i].first > r) ans += a[i].second - a[i].first;
            else if(a[i].second > r) ans += a[i].second - r;
            r = max(r, a[i].second);
        }
        printf("%d\n", ans);
    }
    return 0;
}
