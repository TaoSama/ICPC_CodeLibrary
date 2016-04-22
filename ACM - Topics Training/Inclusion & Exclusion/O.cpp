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

int n, k;

typedef long long LL;

vector<int> factor;
void fact(int x) {
    factor.clear();
    for(int i = 2; i * i <= x; ++i) {
        if(x % i == 0) {
            factor.push_back(i);
            while(x % i == 0) x /= i;
        }
        if(x == 1) break;
    }
    if(x > 1) factor.push_back(x);
}

LL calc(LL x) {
    LL ret = 0;
    int sz = factor.size();
    for(int s = 1; s < 1 << sz; ++s) {
        int cnt = 0, mul = 1;
        for(int i = 0; i < sz; ++i)
            if(s >> i & 1) ++cnt, mul *= factor[i];
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

    while(scanf("%d%d", &n, &k) == 2) {
        fact(n);
        LL l = 1, r = 1e10;
        while(l <= r) {
            LL m = l + r >> 1;
            if(calc(m) < k) l = m + 1;
            else r = m - 1;
        }
        printf("%I64d\n", l);
    }
    return 0;
}
