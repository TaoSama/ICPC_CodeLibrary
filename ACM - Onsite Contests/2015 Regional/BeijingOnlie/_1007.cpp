//
//  Created by TaoSama on 2015-09-20
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
#include <ctime>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e6 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

vector<int> sta[N];

int lowbit(int x) {
    return x & -x;
}

int dp[7][N];
int dp7[] = {
    0, 12, 4, 8, 16, 18, 4, 10, 6, 10, 12, 14, 8, 12, 10, 12, 14, 16, 18, 18, 18, 18, 18, 22, 4, 12, 8, 12, 14, 16, 6, 12, 8, 12, 14, 16, 10, 14, 12, 14, 16, 18, 16, 18, 18, 20, 20, 22, 8, 14, 10, 14, 16, 18, 10, 16, 12, 14, 16, 18, 12, 16, 14, 16, 18, 20, 18, 20, 20, 20, 22, 24, 12, 16, 14, 16, 18, 20, 14, 18, 16, 18, 20, 22, 16, 18, 18, 20, 20, 22, 20, 22, 22, 24, 24, 26, 22, 22, 22, 22, 22, 26, 22, 24, 22, 24, 24, 26, 22, 24, 24, 24, 26, 28, 24, 26, 26, 28, 28, 32, 4, 14, 8, 12, 16, 18, 8, 14, 10, 14, 16, 18, 12, 16, 14, 16, 18, 20, 18, 20, 20, 22, 22, 24, 6, 14, 10, 14, 16, 18, 8, 14, 10, 14, 16, 18, 12, 16, 14, 16, 18, 20, 18, 20, 20, 22, 22, 24, 10, 16, 12, 16, 18, 20, 12, 18, 14, 16, 18, 20, 14, 18, 16, 18, 20, 22, 20, 22, 22, 22, 24, 26, 14, 18, 16, 18, 20, 22, 16, 20, 18, 20, 22, 24, 18, 20, 20, 22, 22, 24, 22, 24, 24, 26, 26, 28, 20, 22, 22, 24, 24, 26, 22, 24, 24, 26, 26, 28, 24, 26, 26, 26, 28, 30, 26, 28, 28, 30, 30, 32, 8, 16, 12, 16, 18, 20, 10, 16, 12, 16, 18, 20, 14, 18, 16, 18, 20, 22, 20, 22, 22, 24, 24, 26, 10, 18, 14, 18, 20, 22, 12, 16, 14, 16, 18, 20, 16, 18, 18, 20, 20, 22, 20, 22, 22, 24, 24, 26, 12, 18, 14, 18, 20, 22, 14, 20, 16, 18, 20, 22, 16, 20, 18, 20, 22, 24, 22, 24, 24, 24, 26, 28, 16, 20, 18, 20, 22, 24, 18, 22, 20, 22, 22, 24, 20, 22, 22, 24, 24, 26, 24, 26, 26, 26, 28, 30, 22, 24, 24, 26, 26, 28, 24, 26, 24, 26, 26, 28, 26, 28, 28, 28, 30, 30, 28, 30, 30, 30, 32, 34, 12, 18, 14, 18, 20, 22, 14, 20, 16, 18, 20, 22, 16, 20, 18, 20, 22, 24, 22, 24, 24, 24, 26, 28, 14, 20, 16, 20, 22, 24, 16, 20, 18, 20, 22, 24, 18, 22, 20, 22, 24, 26, 24, 26, 26, 26, 28, 30, 16, 22, 18, 20, 22, 24, 18, 24, 20, 22, 24, 26, 20, 22, 22, 22, 24, 26, 24, 26, 26, 26, 28, 30, 18, 22, 20, 22, 24, 26, 20, 24, 22, 24, 24, 26, 22, 24, 24, 26, 26, 28, 26, 28, 28, 28, 30, 32, 24, 26, 26, 26, 28, 30, 26, 28, 28, 28, 30, 32, 28, 28, 30, 30, 30, 32, 30, 32, 32, 32, 34, 36, 16, 20, 18, 20, 22, 24, 18, 22, 20, 22, 24, 26, 20, 22, 22, 24, 24, 26, 24, 26, 26, 28, 28, 30, 18, 22, 20, 22, 24, 26, 20, 24, 22, 24, 26, 28, 22, 24, 24, 26, 26, 28, 26, 28, 28, 30, 30, 32, 20, 24, 22, 24, 26, 28, 22, 26, 24, 26, 26, 28, 24, 26, 26, 26, 28, 30, 28, 30, 30, 30, 32, 34, 22, 24, 24, 26, 26, 28, 24, 26, 26, 28, 28, 30, 26, 28, 28, 30, 30, 32, 28, 30, 30, 30, 32, 34, 26, 28, 28, 30, 30, 32, 28, 30, 30, 32, 32, 34, 30, 32, 32, 32, 34, 34, 32, 34, 34, 34, 36, 38, 26, 26, 26, 26, 26, 30, 26, 28, 26, 28, 28, 30, 26, 28, 28, 28, 30, 32, 28, 30, 30, 32, 32, 36, 26, 28, 28, 28, 28, 32, 26, 28, 28, 30, 30, 32, 28, 30, 30, 30, 32, 34, 30, 32, 32, 34, 34, 36, 26, 28, 28, 30, 30, 32, 28, 30, 28, 30, 30, 32, 30, 30, 32, 32, 32, 34, 32, 34, 34, 34, 36, 38, 28, 30, 30, 30, 32, 34, 30, 32, 32, 32, 34, 36, 32, 32, 34, 34, 34, 36, 34, 36, 36, 36, 38, 38, 30, 32, 32, 34, 34, 36, 32, 34, 34, 36, 36, 38, 34, 36, 36, 36, 38, 38, 36, 38, 38, 38, 40, 42, 4, 16, 8, 12, 18, 20, 8, 14, 10, 14, 16, 18, 12, 16, 14, 16, 18, 20, 20, 22, 22, 22, 22, 26, 8, 16, 12, 16, 18, 20, 10, 16, 12, 16, 18, 20, 14, 18, 16, 18, 20, 22, 20, 22, 22, 24, 24, 26, 12, 18, 14, 18, 20, 22, 14, 20, 16, 18, 20, 22, 16, 20, 18, 20, 22, 24, 22, 24, 24, 24, 26, 28, 16, 20, 18, 20, 22, 24, 18, 22, 20, 22, 24, 26, 20, 22, 22, 24, 24, 26, 24, 26, 26, 28, 28, 30, 22, 24, 24, 26, 26, 28, 24, 26, 26, 28, 28, 30, 26, 28, 28, 28, 30, 32, 28, 30, 30, 32, 32, 34, 6, 16, 10, 14, 18, 20, 10, 16, 12, 16, 18, 20, 14, 18, 16, 18, 20, 22, 20, 22, 22, 24, 24, 26, 8, 16, 12, 16, 18, 20, 10, 16, 12, 16, 18, 20, 14, 18, 16, 18, 20, 22, 20, 22, 22, 24, 24, 26, 12, 18, 14, 18, 20, 22, 14, 20, 16, 18, 20, 22, 16, 20, 18, 20, 22, 24, 22, 24, 24, 24, 26, 28, 16, 20, 18, 20, 22, 24, 18, 22, 20, 22, 24, 26, 20, 22, 22, 24, 24, 26, 24, 26, 26, 28, 28, 30, 22, 24, 24, 26, 26, 28, 24, 26, 26, 28, 28, 30, 26, 28, 28, 28, 30, 32, 28, 30, 30, 32, 32, 34, 10, 18, 14, 18, 20, 22, 12, 18, 14, 18, 20, 22, 16, 20, 18, 20, 22, 24, 22, 24, 24, 26, 26, 28, 12, 20, 16, 20, 22, 24, 14, 18, 16, 18, 20, 22, 18, 20, 20, 22, 22, 24, 22, 24, 24, 26, 26, 28, 14, 20, 16, 20, 22, 24, 16, 22, 18, 20, 22, 24, 18, 22, 20, 22, 24, 26, 24, 26, 26, 26, 28, 30, 18, 22, 20, 22, 24, 26, 20, 24, 22, 24, 24, 26, 22, 24, 24, 26, 26, 28, 26, 28, 28, 28, 30, 32, 24, 26, 26, 28, 28, 30, 26, 28, 26, 28, 28, 30, 28, 30, 30, 30, 32, 32, 30, 32, 32, 32, 34, 36, 14, 20, 16, 20, 22, 24, 16, 22, 18, 20, 22, 24, 18, 22, 20, 22, 24, 26, 24, 26, 26, 26, 28, 30, 16, 22, 18, 22, 24, 26, 18, 22, 20, 22, 24, 26, 20, 24, 22, 24, 26, 28, 26, 28, 28, 28, 30, 32, 18, 24, 20, 22, 24, 26, 20, 26, 22, 24, 26, 28, 22, 24, 24, 24, 26, 28, 26, 28, 28, 28, 30, 32, 20, 24, 22, 24, 26, 28, 22, 26, 24, 26, 26, 28, 24, 26, 26, 28, 28, 30, 28, 30, 30, 30, 32, 34, 26, 28, 28, 28, 30, 32, 28, 30, 30, 30, 32, 34, 30, 30, 32, 32, 32, 34, 32, 34, 34, 34, 36, 38, 18, 22, 20, 22, 24, 26, 20, 24, 22, 24, 26, 28, 22, 24, 24, 26, 26, 28, 26, 28, 28, 30, 30, 32, 20, 24, 22, 24, 26, 28, 22, 26, 24, 26, 28, 30, 24, 26, 26, 28, 28, 30, 28, 30, 30, 32, 32, 34, 22, 26, 24, 26, 28, 30, 24, 28, 26, 28, 28, 30, 26, 28, 28, 28, 30, 32, 30, 32, 32, 32, 34, 36, 24, 26, 26, 28, 28, 30, 26, 28, 28, 30, 30, 32, 28, 30, 30, 32, 32, 34, 30, 32, 32, 32, 34, 36, 28, 30, 30, 32, 32, 34, 30, 32, 32, 34, 34, 36, 32, 34, 34, 34, 36, 36, 34, 36, 36, 36, 38, 40, 24, 26, 26, 28, 28, 30, 26, 28, 28, 30, 30, 32, 28, 30, 30, 30, 32, 34, 30, 32, 32, 34, 34, 36, 26, 28, 28, 30, 30, 32, 28, 30, 30, 32, 32, 34, 30, 32, 32, 32, 34, 36, 32, 34, 34, 36, 36, 38, 28, 30, 30, 32, 32, 34, 30, 32, 30, 32, 32, 34, 32, 32, 34, 34, 34, 36, 34, 36, 36, 36, 38, 40, 30, 32, 32, 32, 34, 36, 32, 34, 34, 34, 36, 38, 34, 34, 36, 36, 36, 38, 36, 38, 38, 38, 40, 40, 32, 34, 34, 36, 36, 38, 34, 36, 36, 38, 38, 40, 36, 38, 38, 38, 40, 40, 38, 40, 40, 40, 42, 44, 8, 18, 12, 16, 20, 22, 12, 18, 14, 18, 20, 22, 16, 20, 18, 20, 22, 24, 22, 24, 24, 26, 26, 28, 10, 18, 14, 18, 20, 22, 12, 18, 14, 18, 20, 22, 16, 20, 18, 20, 22, 24, 22, 24, 24, 26, 26, 28, 14, 20, 16, 20, 22, 24, 16, 22, 18, 20, 22, 24, 18, 22, 20, 22, 24, 26, 24, 26, 26, 26, 28, 30, 18, 22, 20, 22, 24, 26, 20, 24, 22, 24, 26, 28, 22, 24, 24, 26, 26, 28, 26, 28, 28, 30, 30, 32, 24, 26, 26, 28, 28, 30, 26, 28, 28, 30, 30, 32, 28, 30, 30, 30, 32, 34, 30, 32, 32, 34, 34, 36, 10, 20, 14, 18, 22, 24, 14, 20, 16, 20, 22, 24, 18, 22, 20, 22, 24, 26, 24, 26, 26, 28, 28, 30, 12, 18, 16, 18, 20, 22, 14, 18, 16, 18, 20, 22, 18, 20, 20, 22, 22, 24, 22, 24, 24, 26, 26, 28, 16, 20, 18, 20, 22, 24, 18, 22, 20, 22, 24, 26, 20, 22, 22, 24, 24, 26, 24, 26, 26, 28, 28, 30, 20, 22, 22, 24, 24, 26, 22, 24, 24, 26, 26, 28, 24, 26, 26, 28, 28, 30, 26, 28, 28, 30, 30, 32, 24, 26, 26, 28, 28, 30, 26, 28, 28, 30, 30, 32, 28, 30, 30, 32, 32, 34, 30, 32, 32, 34, 34, 36, 12, 20, 16, 20, 22, 24, 14, 20, 16, 20, 22, 24, 18, 22, 20, 22, 24, 26, 24, 26, 26, 28, 28, 30, 14, 22, 18, 22, 24, 26, 16, 20, 18, 20, 22, 24, 20, 22, 22, 24, 24, 26, 24, 26, 26, 28, 28, 30, 16, 22, 18, 22, 24, 26, 18, 24, 20, 22, 24, 26, 20, 24, 22, 24, 26, 28, 26, 28, 28, 28, 30, 32, 20, 24, 22, 24, 26, 28, 22, 26, 24, 26, 26, 28, 24, 26, 26, 28, 28, 30, 28, 30, 30, 30, 32, 34, 26, 28, 28, 30, 30, 32, 28, 30, 28, 30, 30, 32, 30, 32, 32, 32, 34, 34, 32, 34, 34, 34, 36, 38, 16, 22, 18, 22, 24, 26, 18, 24, 20, 22, 24, 26, 20, 24, 22, 24, 26, 28, 26, 28, 28, 28, 30, 32, 18, 24, 20, 24, 26, 28, 20, 24, 22, 24, 26, 28, 22, 24, 24, 26, 26, 28, 26, 28, 28, 30, 30, 32, 20, 26, 22, 24, 26, 28, 22, 28, 24, 26, 28, 30, 24, 26, 26, 26, 28, 30, 28, 30, 30, 30, 32, 34, 22, 26, 24, 26, 28, 30, 24, 28, 26, 28, 28, 30, 26, 28, 28, 30, 30, 32, 30, 32, 32, 32, 34, 36, 28, 30, 30, 30, 32, 34, 30, 32, 30, 32, 32, 34, 32, 32, 34, 34, 34, 36, 34, 36, 36, 36, 38, 40, 20, 24, 22, 24, 26, 28, 22, 26, 24, 26, 28, 30, 24, 26, 26, 28, 28, 30, 28, 30, 30, 32, 32, 34, 22, 26, 24, 26, 28, 30, 24, 26, 26, 28, 28, 30, 26, 28, 28, 30, 30, 32, 28, 30, 30, 32, 32, 34, 24, 28, 26, 28, 30, 32, 26, 30, 28, 30, 30, 32, 28, 30, 30, 30, 32, 34, 32, 34, 32, 34, 36, 36, 26, 28, 28, 30, 30, 32, 28, 30, 30, 32, 32, 34, 30, 32, 32, 34, 34, 36, 32, 34, 34, 34, 36, 38, 30, 32, 32, 34, 34, 36, 32, 34, 32, 34, 34, 36, 34, 36, 36, 36, 38, 38, 36, 38, 38, 38, 40, 42, 26, 28, 28, 30, 30, 32, 28, 30, 30, 32, 32, 34, 30, 32, 32, 32, 34, 36, 32, 34, 34, 36, 36, 38, 28, 30, 30, 32, 32, 34, 28, 30, 30, 32, 32, 34, 30, 32, 32, 34, 34, 36, 32, 34, 34, 36, 36, 38, 30, 32, 32, 34, 34, 36, 32, 34, 32, 34, 34, 36, 34, 34, 34, 36, 36, 38, 36, 38, 36, 38, 40, 40, 32, 34, 34, 34, 36, 38, 34, 36, 34, 36, 36, 38, 36, 36, 38, 38, 38, 40, 38, 40, 38, 40, 42, 42, 34, 36, 36, 38, 38, 40, 36, 38, 36, 38, 38, 40, 38, 40, 40, 40, 42, 42, 40, 42, 42, 42, 44, 46, 12, 20, 16, 20, 22, 24, 14, 20, 16, 20, 22, 24, 18, 22, 20, 22, 24, 26, 24, 26, 26, 28, 28, 30, 14, 22, 18, 22, 24, 26, 16, 20, 18, 20, 22, 24, 20, 22, 22, 24, 24, 26, 24, 26, 26, 28, 28, 30, 16, 22, 18, 22, 24, 26, 18, 24, 20, 22, 24, 26, 20, 24, 22, 24, 26, 28, 26, 28, 28, 28, 30, 32, 20, 24, 22, 24, 26, 28, 22, 26, 24, 26, 26, 28, 24, 26, 26, 28, 28, 30, 28, 30, 30, 30, 32, 34, 26, 28, 28, 30, 30, 32, 28, 30, 28, 30, 30, 32, 30, 32, 32, 32, 34, 34, 32, 34, 34, 34, 36, 38, 14, 22, 18, 22, 24, 26, 16, 22, 18, 22, 24, 26, 20, 24, 22, 24, 26, 28, 26, 28, 28, 30, 30, 32, 16, 22, 20, 22, 24, 26, 18, 22, 20, 22, 24, 26, 22, 24, 24, 26, 26, 28, 26, 28, 28, 30, 30, 32, 18, 24, 20, 24, 26, 28, 20, 24, 22, 24, 26, 28, 22, 26, 24, 26, 28, 30, 28, 30, 30, 30, 32, 34, 22, 26, 24, 26, 28, 30, 24, 28, 26, 28, 28, 30, 26, 28, 28, 30, 30, 32, 30, 32, 32, 32, 34, 36, 28, 30, 30, 32, 32, 34, 30, 32, 30, 32, 32, 34, 32, 34, 34, 34, 36, 36, 34, 36, 36, 36, 38, 40, 16, 24, 20, 24, 26, 28, 18, 22, 20, 22, 24, 26, 22, 24, 24, 26, 26, 28, 26, 28, 28, 30, 30, 32, 18, 26, 22, 26, 28, 30, 20, 24, 22, 24, 26, 28, 24, 26, 26, 28, 28, 30, 28, 30, 30, 32, 32, 34, 20, 24, 22, 24, 26, 28, 22, 26, 22, 24, 26, 28, 24, 26, 26, 26, 28, 30, 28, 30, 30, 30, 32, 34, 24, 26, 26, 28, 28, 30, 26, 28, 26, 28, 28, 30, 28, 30, 30, 30, 32, 32, 30, 32, 32, 32, 34, 36, 28, 30, 30, 32, 32, 34, 30, 32, 30, 32, 32, 34, 32, 34, 34, 34, 36, 36, 34, 36, 36, 36, 38, 40, 18, 24, 20, 24, 26, 28, 20, 26, 22, 24, 26, 28, 22, 26, 24, 26, 28, 30, 28, 30, 30, 30, 32, 34, 20, 26, 22, 26, 28, 30, 22, 26, 24, 26, 28, 30, 24, 26, 26, 28, 28, 30, 28, 30, 30, 32, 32, 34, 22, 28, 24, 26, 28, 30, 24, 30, 26, 28, 30, 32, 26, 28, 28, 28, 30, 32, 30, 32, 32, 32, 34, 36, 24, 28, 26, 28, 30, 32, 26, 30, 28, 30, 30, 32, 28, 30, 30, 32, 32, 32, 32, 34, 34, 34, 36, 36, 30, 32, 32, 32, 34, 36, 32, 34, 32, 34, 34, 36, 34, 34, 36, 36, 36, 36, 36, 38, 38, 38, 40, 40, 22, 26, 24, 26, 28, 30, 24, 28, 26, 28, 28, 30, 26, 28, 28, 30, 30, 32, 30, 32, 32, 32, 34, 36, 24, 28, 26, 28, 30, 32, 26, 30, 28, 30, 30, 32, 28, 30, 30, 32, 32, 34, 32, 34, 34, 34, 36, 38, 26, 30, 28, 30, 30, 32, 28, 32, 30, 32, 32, 34, 30, 32, 32, 32, 34, 34, 32, 34, 34, 34, 36, 38, 28, 30, 30, 32, 32, 34, 30, 32, 32, 34, 34, 36, 32, 34, 34, 36, 36, 36, 34, 36, 36, 36, 38, 40, 32, 34, 34, 34, 36, 38, 34, 36, 34, 36, 38, 38, 36, 36, 38, 38, 38, 38, 38, 40, 40, 40, 42, 42, 28, 30, 30, 32, 32, 34, 30, 32, 30, 32, 32, 34, 32, 34, 34, 34, 36, 36, 34, 36, 36, 36, 38, 40, 30, 32, 32, 34, 34, 36, 32, 34, 32, 34, 34, 36, 34, 36, 36, 36, 38, 38, 36, 38, 38, 38, 40, 42, 32, 34, 32, 34, 34, 36, 34, 36, 34, 36, 36, 38, 34, 36, 36, 36, 38, 38, 36, 38, 38, 38, 40, 42, 34, 36, 36, 36, 38, 38, 36, 38, 36, 38, 38, 40, 38, 38, 40, 40, 40, 40, 40, 40, 42, 40, 42, 44, 36, 38, 38, 38, 40, 42, 38, 40, 38, 40, 42, 42, 40, 40, 42, 42, 42, 42, 42, 44, 44, 44, 46, 46, 16, 22, 18, 22, 24, 26, 18, 24, 20, 22, 24, 26, 20, 24, 22, 24, 26, 28, 26, 28, 28, 28, 30, 32, 18, 24, 20, 24, 26, 28, 20, 24, 22, 24, 26, 28, 22, 26, 24, 26, 28, 30, 28, 30, 30, 30, 32, 34, 20, 26, 22, 24, 26, 28, 22, 28, 24, 26, 28, 30, 24, 26, 26, 26, 28, 30, 28, 30, 30, 30, 32, 34, 22, 26, 24, 26, 28, 30, 24, 28, 26, 28, 28, 30, 26, 28, 28, 30, 30, 32, 30, 32, 32, 32, 34, 36, 28, 30, 30, 30, 32, 34, 30, 32, 32, 32, 34, 36, 32, 32, 34, 34, 34, 36, 34, 36, 36, 36, 38, 40, 18, 24, 20, 24, 26, 28, 20, 26, 22, 24, 26, 28, 22, 26, 24, 26, 28, 30, 28, 30, 30, 30, 32, 34, 20, 26, 22, 26, 28, 30, 22, 26, 24, 26, 28, 30, 24, 28, 26, 28, 30, 32, 30, 32, 32, 32, 34, 36, 22, 28, 24, 26, 28, 30, 24, 28, 26, 28, 30, 32, 26, 28, 28, 28, 30, 32, 30, 32, 32, 32, 34, 36, 24, 28, 26, 28, 30, 32, 26, 30, 28, 30, 30, 32, 28, 30, 30, 32, 32, 34, 32, 34, 34, 34, 36, 38, 30, 32, 32, 32, 34, 36, 32, 34, 34, 34, 36, 38, 34, 34, 36, 36, 36, 38, 36, 38, 38, 38, 40, 42, 20, 26, 22, 26, 28, 30, 22, 26, 24, 26, 28, 30, 24, 28, 26, 28, 30, 32, 30, 32, 32, 32, 34, 36, 22, 28, 24, 28, 30, 32, 24, 28, 26, 28, 30, 32, 26, 28, 28, 30, 30, 32, 30, 32, 32, 34, 34, 36, 24, 28, 26, 28, 30, 32, 26, 30, 26, 28, 30, 32, 28, 30, 28, 30, 32, 32, 32, 34, 34, 34, 36, 38, 26, 30, 28, 30, 30, 32, 28, 32, 28, 30, 32, 34, 30, 32, 32, 32, 34, 34, 32, 34, 34, 36, 36, 38, 32, 34, 34, 34, 36, 38, 34, 36, 34, 36, 36, 38, 36, 36, 38, 38, 38, 40, 38, 40, 40, 40, 42, 44, 22, 28, 24, 26, 28, 30, 24, 30, 26, 28, 30, 32, 26, 28, 28, 28, 30, 32, 30, 32, 32, 32, 34, 36, 24, 30, 26, 28, 30, 32, 26, 30, 28, 30, 32, 34, 28, 30, 30, 30, 32, 34, 32, 34, 34, 34, 36, 38, 26, 32, 28, 30, 32, 34, 28, 34, 30, 32, 34, 36, 30, 30, 32, 32, 32, 34, 34, 34, 36, 36, 36, 38, 28, 30, 30, 30, 32, 34, 30, 32, 30, 32, 32, 34, 32, 32, 34, 34, 34, 34, 34, 36, 36, 36, 38, 38, 32, 34, 34, 34, 36, 38, 34, 36, 34, 36, 36, 38, 36, 36, 38, 38, 38, 40, 38, 40, 40, 40, 42, 44, 24, 28, 26, 28, 30, 32, 26, 30, 28, 30, 30, 32, 28, 30, 30, 32, 32, 34, 32, 34, 34, 34, 36, 38, 26, 30, 28, 30, 32, 34, 28, 30, 30, 32, 32, 34, 30, 32, 32, 34, 34, 36, 32, 34, 34, 36, 36, 38, 28, 32, 30, 32, 32, 34, 30, 34, 32, 34, 34, 36, 32, 34, 34, 34, 36, 36, 34, 36, 36, 36, 38, 40, 30, 32, 32, 34, 34, 36, 32, 34, 34, 36, 36, 38, 34, 36, 36, 38, 38, 38, 36, 38, 38, 38, 40, 42, 34, 36, 36, 36, 38, 40, 36, 38, 36, 38, 38, 40, 38, 38, 40, 40, 40, 42, 40, 42, 42, 42, 44, 44, 30, 32, 32, 32, 34, 36, 32, 34, 34, 34, 36, 38, 34, 34, 36, 36, 36, 38, 36, 38, 38, 38, 40, 42, 32, 34, 34, 34, 36, 38, 34, 36, 36, 36, 38, 40, 36, 36, 38, 38, 38, 40, 38, 40, 40, 40, 42, 44, 34, 36, 36, 36, 38, 40, 36, 38, 36, 38, 38, 40, 38, 38, 38, 40, 40, 42, 40, 40, 40, 42, 42, 44, 36, 36, 38, 38, 38, 40, 38, 38, 38, 40, 40, 42, 40, 40, 42, 42, 42, 42, 40, 42, 42, 42, 44, 46, 38, 40, 40, 40, 42, 44, 40, 42, 40, 42, 42, 44, 42, 42, 44, 44, 44, 46, 44, 46, 46, 46, 48, 48, 20, 24, 22, 24, 26, 28, 22, 26, 24, 26, 28, 30, 24, 26, 26, 28, 28, 30, 28, 30, 30, 32, 32, 34, 22, 26, 24, 26, 28, 30, 24, 28, 26, 28, 30, 32, 26, 28, 28, 30, 30, 32, 30, 32, 32, 34, 34, 36, 24, 28, 26, 28, 30, 32, 26, 30, 28, 30, 30, 32, 28, 30, 30, 30, 32, 34, 32, 34, 34, 34, 36, 38, 26, 28, 28, 30, 30, 32, 28, 30, 30, 32, 32, 34, 30, 32, 32, 34, 34, 36, 32, 34, 34, 34, 36, 38, 30, 32, 32, 34, 34, 36, 32, 34, 34, 36, 36, 38, 34, 36, 36, 36, 38, 38, 36, 38, 38, 38, 40, 42, 22, 26, 24, 26, 28, 30, 24, 28, 26, 28, 30, 32, 26, 28, 28, 30, 30, 32, 30, 32, 32, 34, 34, 36, 24, 28, 26, 28, 30, 32, 26, 30, 28, 30, 32, 34, 28, 30, 30, 32, 32, 34, 32, 34, 34, 36, 36, 38, 26, 30, 28, 30, 32, 34, 28, 32, 30, 32, 32, 34, 30, 32, 32, 32, 34, 36, 34, 36, 36, 36, 38, 40, 28, 30, 30, 32, 32, 34, 30, 32, 32, 34, 34, 36, 32, 34, 34, 36, 36, 38, 34, 36, 36, 36, 38, 40, 32, 34, 34, 36, 36, 38, 34, 36, 36, 38, 38, 40, 36, 38, 38, 38, 40, 40, 38, 40, 40, 40, 42, 44, 24, 28, 26, 28, 30, 32, 26, 30, 28, 30, 32, 34, 28, 30, 30, 32, 32, 34, 32, 34, 34, 36, 36, 38, 26, 30, 28, 30, 32, 34, 28, 30, 30, 32, 32, 34, 30, 32, 32, 34, 34, 36, 32, 34, 34, 36, 36, 38, 28, 32, 30, 32, 32, 34, 30, 34, 30, 32, 34, 36, 32, 34, 32, 34, 36, 36, 34, 36, 36, 38, 38, 40, 30, 32, 32, 34, 34, 36, 32, 34, 32, 34, 34, 36, 34, 36, 36, 36, 38, 38, 36, 38, 38, 38, 40, 42, 34, 36, 36, 38, 38, 40, 36, 38, 36, 38, 38, 40, 38, 40, 40, 40, 42, 42, 40, 42, 42, 42, 44, 46, 26, 30, 28, 30, 32, 34, 28, 32, 30, 32, 32, 34, 30, 32, 32, 32, 34, 36, 34, 36, 36, 36, 38, 40, 28, 32, 30, 32, 34, 36, 30, 34, 32, 34, 34, 36, 32, 34, 34, 34, 36, 38, 36, 38, 38, 38, 40, 42, 30, 34, 32, 34, 34, 36, 32, 36, 34, 36, 36, 38, 34, 34, 36, 36, 36, 38, 36, 38, 38, 38, 40, 42, 32, 34, 34, 34, 36, 38, 34, 36, 34, 36, 36, 38, 36, 36, 38, 38, 38, 38, 38, 40, 40, 40, 42, 42, 36, 38, 38, 38, 40, 40, 38, 40, 38, 40, 40, 42, 40, 40, 40, 42, 42, 42, 42, 42, 44, 44, 44, 46, 28, 30, 30, 32, 32, 34, 30, 32, 32, 34, 34, 36, 32, 34, 34, 36, 36, 38, 34, 36, 36, 36, 38, 40, 30, 32, 32, 34, 34, 36, 32, 34, 34, 36, 36, 38, 34, 36, 36, 38, 38, 40, 36, 38, 38, 38, 40, 42, 32, 34, 34, 36, 36, 38, 34, 36, 36, 38, 38, 40, 36, 38, 38, 38, 40, 40, 38, 38, 40, 40, 40, 42, 34, 36, 36, 38, 38, 40, 36, 38, 38, 40, 40, 42, 38, 40, 40, 42, 42, 42, 40, 42, 42, 42, 44, 46, 36, 38, 38, 38, 40, 42, 38, 40, 38, 40, 40, 42, 40, 40, 42, 42, 42, 44, 42, 44, 44, 44, 46, 48, 32, 34, 34, 36, 36, 38, 34, 36, 36, 38, 38, 40, 36, 38, 38, 38, 40, 40, 38, 40, 40, 40, 42, 44, 34, 36, 36, 38, 38, 40, 36, 38, 38, 40, 40, 42, 38, 40, 40, 40, 42, 42, 40, 42, 42, 42, 44, 46, 36, 38, 38, 40, 40, 42, 38, 40, 38, 40, 40, 42, 40, 40, 40, 42, 42, 44, 42, 42, 42, 44, 44, 46, 38, 40, 40, 40, 42, 42, 40, 42, 40, 42, 44, 44, 42, 42, 44, 44, 44, 44, 44, 44, 46, 44, 46, 48, 40, 42, 42, 42, 44, 46, 42, 44, 42, 44, 44, 46, 44, 44, 46, 46, 46, 48, 46, 48, 48, 48, 50, 52, 30, 30, 30, 30, 30, 34, 30, 32, 30, 32, 32, 34, 30, 32, 32, 32, 34, 36, 32, 34, 34, 36, 36, 40, 30, 32, 32, 32, 32, 36, 30, 32, 32, 34, 34, 36, 32, 34, 34, 34, 36, 38, 34, 36, 36, 38, 38, 40, 30, 32, 32, 34, 34, 36, 32, 34, 32, 34, 34, 36, 34, 34, 36, 36, 36, 38, 36, 38, 38, 38, 40, 42, 32, 34, 34, 34, 36, 38, 34, 36, 36, 36, 38, 40, 36, 36, 38, 38, 38, 40, 38, 40, 40, 40, 42, 42, 34, 36, 36, 38, 38, 40, 36, 38, 38, 40, 40, 42, 38, 40, 40, 40, 42, 42, 40, 42, 42, 42, 44, 46, 30, 32, 32, 32, 32, 36, 32, 34, 32, 34, 34, 36, 32, 34, 34, 34, 36, 38, 34, 36, 36, 38, 38, 42, 30, 32, 32, 34, 34, 36, 32, 34, 34, 36, 36, 38, 34, 36, 36, 36, 38, 40, 36, 38, 38, 40, 40, 42, 32, 34, 34, 36, 36, 38, 34, 36, 34, 36, 36, 38, 36, 36, 38, 38, 38, 40, 38, 40, 40, 40, 42, 44, 34, 36, 36, 36, 38, 40, 36, 38, 38, 38, 40, 42, 38, 38, 40, 40, 40, 42, 40, 42, 42, 42, 44, 44, 36, 38, 38, 40, 40, 42, 38, 40, 40, 42, 42, 44, 40, 42, 42, 42, 44, 44, 42, 44, 44, 44, 46, 48, 30, 32, 32, 34, 34, 36, 32, 34, 34, 36, 36, 38, 34, 36, 36, 36, 38, 40, 36, 38, 38, 40, 40, 42, 32, 34, 34, 36, 36, 38, 32, 34, 34, 36, 36, 38, 34, 36, 36, 38, 38, 40, 36, 38, 38, 40, 40, 42, 34, 36, 34, 36, 36, 38, 36, 38, 36, 38, 38, 40, 36, 38, 38, 40, 40, 42, 38, 40, 40, 42, 42, 44, 36, 38, 38, 38, 40, 42, 38, 40, 38, 40, 40, 42, 40, 40, 42, 42, 42, 44, 42, 44, 42, 44, 46, 46, 38, 40, 40, 42, 42, 44, 40, 42, 40, 42, 42, 44, 42, 44, 44, 44, 46, 46, 44, 46, 46, 46, 48, 50, 32, 34, 34, 36, 36, 38, 34, 36, 34, 36, 36, 38, 36, 36, 38, 38, 38, 40, 38, 40, 40, 40, 42, 44, 34, 36, 36, 38, 38, 40, 36, 38, 36, 38, 38, 40, 38, 38, 40, 40, 40, 42, 40, 42, 42, 42, 44, 46, 36, 38, 36, 38, 38, 40, 38, 40, 38, 40, 40, 42, 38, 40, 40, 40, 42, 42, 40, 42, 42, 42, 44, 46, 38, 38, 40, 40, 40, 42, 40, 40, 40, 42, 40, 42, 42, 42, 42, 44, 42, 44, 42, 44, 44, 44, 46, 46, 40, 42, 42, 42, 44, 44, 42, 44, 42, 44, 44, 46, 44, 44, 44, 46, 46, 46, 46, 46, 48, 48, 48, 50, 34, 36, 36, 36, 38, 40, 36, 38, 38, 38, 40, 42, 38, 38, 40, 40, 40, 42, 40, 42, 42, 42, 44, 44, 36, 38, 38, 38, 40, 42, 38, 40, 40, 40, 42, 44, 40, 40, 42, 42, 42, 44, 42, 44, 44, 44, 46, 46, 38, 40, 40, 40, 42, 44, 40, 42, 40, 42, 42, 44, 42, 42, 42, 44, 44, 46, 44, 44, 44, 46, 46, 48, 40, 40, 42, 42, 42, 44, 42, 42, 42, 44, 44, 46, 44, 44, 46, 46, 46, 46, 44, 46, 46, 46, 48, 50, 42, 44, 44, 44, 46, 46, 44, 46, 44, 46, 46, 48, 46, 46, 46, 48, 48, 48, 48, 48, 50, 48, 50, 52, 36, 38, 38, 40, 40, 42, 38, 40, 40, 42, 42, 44, 40, 42, 42, 42, 44, 44, 42, 44, 44, 44, 46, 48, 38, 40, 40, 42, 42, 44, 40, 42, 42, 44, 44, 46, 42, 44, 44, 44, 46, 46, 44, 46, 46, 46, 48, 50, 40, 42, 42, 44, 44, 46, 42, 44, 42, 44, 44, 46, 44, 44, 44, 46, 46, 48, 46, 46, 46, 48, 48, 50, 42, 44, 44, 44, 46, 46, 44, 46, 44, 46, 48, 48, 46, 46, 48, 48, 48, 48, 48, 48, 50, 48, 50, 52, 44, 46, 46, 46, 48, 50, 46, 48, 46, 48, 48, 50, 48, 48, 50, 50, 50, 52, 50, 52, 52, 52, 54, 56
};

int n, cnt;
map<vector<int>, int> mp[8];
int ID(vector<int>& u, int n) {
    if(!mp[n].count(u)) {
        mp[n][u] = cnt++;
        sta[cnt - 1] = u;
        return cnt - 1;
    }
    return -1;
}

void bfs(int n) {
    vector<int> s;
    for(int i = 0; i < n; ++i) s.push_back(1 << i);
    mp[n].clear(); cnt = 0;
    memset(dp[n], -1, sizeof dp[n]);
    int id = ID(s, n); dp[n][0] = 0;
    queue<int> q; q.push(id);
    while(q.size()) {
        int u = q.front(); q.pop();
        for(int i = 0; i < n; ++i) {
            if(!sta[u][i]) continue;
            if(i > 0) {
                if(!sta[u][i - 1] || lowbit(sta[u][i]) < lowbit(sta[u][i - 1])) {
                    vector<int> v(sta[u]);
                    v[i - 1] += lowbit(v[i]);
                    v[i] -= lowbit(v[i]);
                    int id = ID(v, n);
                    if(~id) {
                        q.push(id);
                        dp[n][id] = dp[n][u] + 1;
                    }
                }
            }
            if(i < n - 1) {
                if(!sta[u][i + 1] || lowbit(sta[u][i]) < lowbit(sta[u][i + 1])) {
                    vector<int> v(sta[u]);
                    v[i + 1] += lowbit(v[i]);
                    v[i] -= lowbit(v[i]);
                    int id = ID(v, n);
                    if(~id) {
                        q.push(id);
                        dp[n][id] = dp[n][u] + 1;
                    }
                }
            }
        }
    }
}

int fac[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600};

//map the permutation to the k-th number
int KT(int *s, int n) {
    int sum = 0;
    for(int i = 0; i < n; ++i) {
        int cnt = 0;
        //record the number of less than current number(coefficient)
        for(int j = i + 1; j < n; ++j)
            if(s[j] < s[i]) ++cnt;
        sum += cnt * fac[n - i - 1];
    }
    return sum;
}

int a[10], b[10], id[10005];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    for(int i = 1; i <= 6; ++i) bfs(i);
    while(t--) {
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) {
            scanf("%d", a + i);
            b[i] = a[i];
        }

        sort(b, b + n);
        for(int i = 0; i < n; ++i) id[b[i]] = i;

        if(n == 7) {
            for(int i = 0; i < n; ++i) b[i] = id[a[i]];
            int ans = KT(b, n);
            printf("%d\n", dp7[ans]);
            continue;
        }

        vector<int> v;
        for(int i = 0; i < n; ++i)
            v.push_back(1 << id[a[i]]);

        int ans = mp[n].count(v) ? dp[n][mp[n][v]] : -1;
//      for(int i = 0; i < cnt; ++i) printf("%d ", dp[n][i]); puts("");
        printf("%d\n", ans);
    }
    return 0;
}
