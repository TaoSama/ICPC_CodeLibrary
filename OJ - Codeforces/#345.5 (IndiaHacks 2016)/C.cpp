//
//  Created by TaoSama on 2016-03-19
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:1024000000,1024000000")
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
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, a[N];

bool check(int x) {
    if(x & 1) {
        if(a[x - 1] > a[x] && a[x] < a[x + 1]) return true;
    } else {
        if(a[x - 1] < a[x] && a[x] > a[x + 1]) return true;
    }
    return false;
}

bool isLegal(vector<int>& e) {
    for(int x : e) if(!check(x)) return false;
    return true;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);
        a[0] = INF;
        a[n + 1] = n & 1 ? INF : 0;
        vector<int> e;
        for(int i = 1; i <= n; ++i)
            if(!check(i)) e.push_back(i);
        int ans = 0;
        if(e.size() < 10) {
            for(int x : e) {
                for(int i = 1; i <= n; ++i) {
                    swap(a[x], a[i]);
                    ans += check(i) && isLegal(e);
                    swap(a[x], a[i]);
                }
            }
            for(int i = 0; i < e.size(); ++i) {
                int x = e[i];
                for(int j = i + 1; j < e.size(); ++j) {
                    int y = e[j];
                    swap(a[x], a[y]);
                    ans -= isLegal(e);
                    swap(a[x], a[y]);
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
