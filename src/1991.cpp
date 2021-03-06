//
// Created by BugenZhao on 2019/3/17.
//
// 二分答案

/*
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;
int n, k;
double minD = 1e7;

void getAnswer(double *x, double currentD, int pos, int remCircle) {
    if (remCircle == 0 && pos != n) return;
    if (currentD > minD) return;
    if (n - pos < remCircle) return;
    if (pos == n) {
        minD = min(currentD, minD);
        return;
    }
    for (int i = pos; i < n; ++i) {
        getAnswer(x, max(currentD, x[i] - x[pos]), i + 1, remCircle - 1);
    }
}

int main() {

    cin >> n >> k;
    double *x = new double[n]{};
    double begin;
    cin >> begin;
    double tmp;
    for (int i = 1; i < n; ++i) {
        cin >> tmp;
        x[i] = tmp - begin;
    }
    getAnswer(x, 0, 0, k);
    cout << fixed << setprecision(6) << minD / 2.0 << endl;
    return 0;
}
*/

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;
int n, k;
double minD = 1e7;
double *x;

int getRank(int lo, int hi, double num) {
    if (hi == lo + 1)
        return lo;
    int mi = lo + (hi - lo) / 2;
    if (x[mi] <= num)
        return getRank(mi, hi, num);
    else
        return getRank(lo, mi, num);
}

int main() {
    cin >> n >> k;
    x = new double[n]{};
    double tmp, begin;
    cin >> begin;
    for (int i = 1; i < n; ++i) {
        scanf("%lf", &tmp);
        x[i] = tmp - begin;
    }
    double min = 0.0, mid, max = x[n - 1];
    while (fabs(max - min) >= 1e-7) {
        mid = (min + max) / 2;
        int curr = 0;
        bool flag = false;
        for (int i = 0; i < k; ++i) {
            curr = getRank(curr, n, x[curr] + mid);
            if (curr == n - 1) {
                flag = true;
                break;
            }
            ++curr;
        }
        if (flag) max = mid;
        else min = mid;
    }
    cout << fixed << setprecision(6) << mid / 2.0 << endl;
}