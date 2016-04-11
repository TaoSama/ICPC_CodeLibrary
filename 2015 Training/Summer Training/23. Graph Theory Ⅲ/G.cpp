//
//  Created by TaoSama on 2015-08-19
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
const int N = 4e2 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int M = 1e5 + 10;

int pnt[M], cap[M], nxt[M], head[N], cnt;

void add_edge(int u, int v, int w) {
    pnt[cnt] = v;
    cap[cnt] = w;
    nxt[cnt] = head[u];
    head[u] = cnt++;
}

void add_double(int u, int v, int w1, int w2 = 0) {
    add_edge(u, v, w1);
    add_edge(v, u, w2);
}

//lev:= get hierarchical graph
//once we can't a new augmenting path, then it gets long or doesn't exist
//then we need bfs to get a new hierarchical graph again

//cur:= current gap optimization
//to guarantee that do not check useless edge over one time
int lev[N], cur[N];
bool bfs(int s, int t) {
    queue<int> q;
    memset(lev, 0, sizeof lev);
    q.push(s);  lev[s] = 1;
    while(q.size() && !lev[t]) {
        int u = q.front(); q.pop();
        for(int i = head[u]; ~i; i = nxt[i]) {
            int v = pnt[i];
            if(cap[i] > 0 && !lev[v]) {
                lev[v] = lev[u] + 1;
                q.push(v);
            }
        }
    }
    return lev[t];
}

int dfs(int u, int t, int delta) {
    if(u == t || !delta) return delta;
    int ret = 0;
    for(int i = cur[u]; ~i; i = nxt[i]) {
        int v = pnt[i];
        if(cap[i] > 0 && lev[v] == lev[u] + 1) {
            int d = dfs(v, t, min(delta, cap[i]));
            cur[u] = i;            //current gap optimization
            ret += d; delta -= d;  //multiple path augmenting
            cap[i] -= d;
            cap[i ^ 1] += d;

            if(delta == 0) return ret;
        }
    }
    lev[u] = 0;
    return ret;
}

int dinic(int s, int t) {
    int ret = 0;
    while(bfs(s, t)) {
        for(int i = s; i <= t; ++i) cur[i] = head[i];
        ret += dfs(s, t, INF);
    }
    return ret;
}

int n, m, k, sz;

map<string, int> mp;
int ID(string s) {
    if(!mp.count(s)) mp[s] = ++sz;
    return mp[s];
}

int outlet[105], device[105], from[105], to[105];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int T; scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        char buf[30];
        sz = cnt = 0;  mp.clear();
        memset(head, -1, sizeof head);
        for(int i = 1; i <= n; ++i) {
            scanf("%s", buf);
            outlet[i] = ID(buf);
        }
        scanf("%d", &m);
        for(int i = 1; i <= m; ++i) {
            scanf("%s%s", buf, buf);
            device[i] = ID(buf);
        }
        scanf("%d", &k);
        for(int i = 1; i <= k; ++i) {
            scanf("%s", buf);
            from[i] = ID(buf);
            scanf("%s", buf);
            to[i] = ID(buf);
        }

        int s = 0, t = mp.size() + 1;
        for(int i = 1; i <= m; ++i) add_double(s, device[i], 1);
        for(int i = 1; i <= n; ++i) add_double(outlet[i], t, 1);
        for(int i = 1; i <= k; ++i) add_double(from[i], to[i], INF);

        printf("%d\n", m - dinic(s, t));
        if(T) puts("");
    }
    return 0;
}
