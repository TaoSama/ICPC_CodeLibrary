//
//  Created by TaoSama on 2016-10-03
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

int n;
string s;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n >> s) {
        s.push_back('_');
        bool out = true;
        int cnt = 0;
        int maxv = 0, inCnt = 0;
        for(char c : s) {
            if(!isalpha(c)) {
                if(out) maxv = max(maxv, cnt);
                else if(cnt) ++inCnt;
//              pr(c); pr(out); pr(cnt); prln(inCnt);

                if(c == '(') out = false;
                else if(c == ')') out = true;

                cnt = 0;
            } else {
                ++cnt;
            }
        }
        cout << maxv << ' ' << inCnt << endl;
    }

    return 0;
}
