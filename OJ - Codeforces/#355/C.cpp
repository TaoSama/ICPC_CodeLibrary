//
//  Created by TaoSama on 2016-06-02
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

char s[N];
int ID(char c) {
    if(isdigit(c)) return c - '0';
    if(isupper(c)) return c - 'A' + 10;
    if(islower(c)) return c - 'a' + 36;
    if(c == '-') return 62;
    return 63;
}
int cnt[70];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    for(int i = 0; i < 64; ++i)
        for(int j = 0; j < 64; ++j)
            ++cnt[i & j];

    while(scanf("%s", s) == 1) {
        long long ans = 1;
        for(int i = 0; s[i]; ++i)
            ans = ans * cnt[ID(s[i])] % MOD;
        printf("%I64d\n", ans);
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
