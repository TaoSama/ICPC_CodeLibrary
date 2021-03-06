//
//  Created by TaoSama on 2016-08-10
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
const int N = 5e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int C = 5e4;

int n;
vector<int> ps[C + 5];

int root[N];
struct PersistentSegTree {
    static const int M = N * 20;
    int sz;
    struct Node {
        int ls, rs, sum;
    } tree[M];
    void init() {
        sz = 0;
        memset(&tree[0], 0, sizeof tree[0]);
    }
    int newNode(int rt) {
        tree[++sz] = tree[rt];
        return sz;
    }
    void update(int o, int v, int l, int r, int& rt) {
        rt = newNode(rt);
        tree[rt].sum += v;
        if(l == r) return;
        int m = l + r >> 1;
        if(o <= m) update(o, v, l, m, tree[rt].ls);
        else update(o, v, m + 1, r, tree[rt].rs);
    }
    int query(int L, int R, int l, int r, int rt) {
        if(L <= l && r <= R) return tree[rt].sum;
        int m = l + r >> 1, ret = 0;
        if(L <= m) ret += query(L, R, l, m, tree[rt].ls);
        if(R > m) ret += query(L, R, m + 1, r, tree[rt].rs);
        return ret;
    }
} T;

int main() {
#ifdef LOCAL
//    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
    freopen("C:\\Users\\TaoSama\\Desktop\\1012.in", "r", stdin);
    freopen("C:\\Users\\TaoSama\\Desktop\\out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1 && n) {
        vector<int> xs;
        for(int i = 1; i <= C; ++i) ps[i].clear();
        for(int i = 1; i <= n; ++i) {
            int x, y; scanf("%d%d", &x, &y);
            ps[x].push_back(y);
        }
        for(int i = 1; i <= C; ++i) {
            auto& v = ps[i];
            if(!v.size()) continue;
            sort(v.begin(), v.end());
            v.resize(unique(v.begin(), v.end()) - v.begin());
        }

        T.init();
        bool ok = true;
        vector<int> lastX(C + 1, 0);
        for(int x = 1; x <= C && ok; ++x) {
            root[x] = root[x - 1];
            auto& v = ps[x];
            for(int i = 0; i < v.size(); ++i) {
                int y = v[i];
                int preX = lastX[y];
                int preY = i - 1 >= 0 ? v[i - 1] : 0;
                int nxtY = i + 1 < v.size() ? v[i + 1] : C + 1;
                int num1 = T.query(preY + 1, nxtY - 1, 1, C, root[preX]);
                int num2 = T.query(preY + 1, nxtY - 1, 1, C, root[x - 1]);
                if(num1 != num2) {ok = false; break;}
                lastX[y] = x;
                T.update(y, 1, 1, C, root[x]);
            }
        }

        puts(ok ? "YES" : "NO");
    }

    return 0;
}
