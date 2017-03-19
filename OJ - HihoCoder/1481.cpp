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



int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
//    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        string s; cin >> s; int a = 0, l = 0;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == 'A') ++a;
            if(i + 2 < s.size() && s[i] == 'L' && s[i + 1] == 'L' && s[i + 2] == 'L')
                ++l;
        }
//        pr(a); prln(l);
        if(a > 1 || l) puts("NO");
        else puts("YES");
    }

    return 0;
}
