//
//  Created by TaoSama on 2017-03-19
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
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
int f[N][2][3];

void add(int& x, int y) {
    if((x += y) >= MOD) x -= MOD;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d", &n);
    f[0][0][0] = 1;
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j < 2; ++j) {
            for(int k = 0; k < 3; ++k) {
                add(f[i][j][0], f[i - 1][j][k]);
                if(j == 1) add(f[i][j][0], f[i - 1][j - 1][k]);
                if(k == 1 || k == 2) add(f[i][j][k], f[i - 1][j][k - 1]);
            }
        }
    }
    int ans = 0;
    for(int j = 0; j < 2; ++j) {
        for(int k = 0; k < 3; ++k) {
            add(ans, f[n][j][k]);
        }
    }
    printf("%d\n", ans);

    return 0;
}
