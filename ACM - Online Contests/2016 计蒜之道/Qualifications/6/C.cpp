//
//  Created by TaoSama on 2016-06-12
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

int n, val[N][2];
vector<int> G[N];
int f[N][2];

void dfs(int u, int fa) {
    f[u][0] = f[u][1] = 0;
    vector<int> sons;
    for(int v : G[u]) {
        if(v == fa) continue;
        sons.push_back(v);
        dfs(v, u);
    }

    for(int i = 0; i < 2; ++i) {
        int x = val[u][i], cur = -INF;

        vector<int> big, small;
        big.push_back(u); small.push_back(u);
        for(int v : sons) {
            if(val[v][0] >= x || val[v][1] >= x)
                big.push_back(v);
            if(val[v][0] <= x || val[v][1] <= x)
                small.push_back(v);
        }
        for(int a : big) {
            for(int j = 0; j < 2; ++j) {
                if(a == u && i != j) continue;
                int maxv = val[a][j];
                if(maxv < x) continue;
                for(int b : small) {
                    for(int k = 0; k < 2; ++k) {
                        if(b == u && i != k) continue;
                        if(a == b && j != k) continue;
                        int minv = val[b][k];
                        if(minv > x) continue;

                        int tmp = f[a][j], ok = 1;
                        if(a != b) tmp += f[b][k]; //fuck
                        for(int v : sons) {
                            if(v == a || v == b) continue;
                            int choice = -INF;
                            for(int c = 0; c < 2; ++c) {
                                int y = val[v][c];
                                if(y < minv || y > maxv) continue;
                                choice = max(choice, f[v][c]);
                            }
                            if(choice == -INF) {ok = 0; break;}
                            tmp += choice;
                        }
                        if(!ok) continue;

                        int diff = maxv - minv;
                        int delta = (diff + 999) / 1000 * 666 * u;
                        cur = max(cur, tmp + x - delta);
                    }
                }
            }
        }
        f[u][i] = cur;
    }
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i)
            for(int j = 0; j < 2; ++j)
                scanf("%d", val[i] + j);

        for(int i = 1; i <= n; ++i) G[i].clear();
        for(int i = 1; i < n; ++i) {
            int u, v; scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }

        dfs(1, -1);
//        for(int i = 1; i <= n; ++i) {
//            for(int j = 0; j < 2; ++j)
//                printf("f[%d][%d] = %d\n", i, j, f[i][j]);
//        }
        printf("%d\n", max(f[1][0], f[1][1]));
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
