//
//  Created by TaoSama on 2016-07-15
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

string s;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    while(cin >> s) {
        if(s == "0.0e0") {
            cout << "0\n";
            continue;
        }
        string bs;
        while(s.back() != 'e') {
            bs = s.back() + bs;
            s.pop_back();
        }
        s.pop_back();
        int b = stoi(bs);
        s += string(b, '0');
//        prln(b);

        int p = s.find('.');
        s.insert(p + b + 1, ".");
//        prln(s);
        s.erase(p, 1);
        while(s.back() == '0') s.pop_back();
        while(s.back() == '.') s.pop_back();
        cout << s << endl;
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
