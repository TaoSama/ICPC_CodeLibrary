//
//  Created by TaoSama on 2016-08-23
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
#include <complex>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef complex<double> P;
const double EPS = 5e-13, PI = acos(-1);

int n;

double normalize(double r) {
    if(r < 0.0) r += 2 * PI;
    if(r >= 2 * PI) r -= 2 * PI;
    return r;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1 && n) {
        vector<P> ps(n);
        vector<double> rs(n);
        for(int i = 0; i < n; ++i) {
            double x, y, r;
            scanf("%lf%lf%lf", &x, &y, &r);
            ps[i] = P(x, y);
            rs[i] = r;
        }

        vector<int> visible(n, 0);
        for(int i = 0; i < n; ++i) {
            vector<double> angles;
            angles.push_back(0);
            angles.push_back(2 * PI);
            for(int j = 0; j < n; ++j) {
                if(i == j) continue;
                P v = ps[j] - ps[i];
                double a = abs(v);
                double b = rs[i];
                double c = rs[j];
                if(a + b < c || a + c < b || b + c < a) continue;

                double angle = arg(v);
                double delta = acos((a * a + b * b - c * c) / (2 * a * b));
                angles.push_back(normalize(angle - delta));
                angles.push_back(normalize(angle + delta));
            }

            sort(angles.begin(), angles.end());
            for(int j = 0; j + 1 < angles.size(); ++j) {
                double theta = (angles[j] + angles[j + 1]) / 2;
                for(int d = -1; d <= 1; d += 2) {
                    P o = ps[i] + polar(rs[i] + d * EPS, theta);
                    for(int k = n - 1; ~k; --k) {
                        if(abs(ps[k] - o) < rs[k]) {
                            visible[k] = true;
                            break;
                        }
                    }
                }
            }
        }

        int ans = count(visible.begin(), visible.end(), true);
        printf("%d\n", ans);
    }

    return 0;
}
