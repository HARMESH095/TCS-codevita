#include <bits/stdc++.h>
using namespace std;


struct P {
    double a, b;
    P(double a = 0, double b = 0) : a(a), b(b) {}
};

P r(const P &p, double t) {
    return P(p.a * cos(t) - p.b * sin(t),
             p.a * sin(t) + p.b * cos(t));
}

pair<double, double> g(const vector<P> &q, double t) {
    double x1 = 1e9, x2 = -1e9, y1 = 1e9, y2 = -1e9;
    for (const auto &p : q) {
        P s = r(p, t);
        x1 = min(x1, s.a);
        x2 = max(x2, s.a);
        y1 = min(y1, s.b);
        y2 = max(y2, s.b);
    }
    return {x2 - x1, y2 - y1};
}

int main() {
    int n;
    cin >> n;
    vector<P> q(n);

    for (int i = 0; i < n; ++i) {
        cin >> q[i].a >> q[i].b;
    }

    double m = 1e9, w = 0, h = 0;

    for (int i = 0; i < 360; ++i) {
        double t = i * M_PI / 180.0;
        auto [cw, ch] = g(q, t);
        double a = cw * ch;
        if (a < m) {
            m = a;
            w = cw;
            h = ch;
        }
    }

    if (w > h) {
        swap(w, h);
    }

    cout << fixed << setprecision(0) << round(w) << " "
         << fixed << setprecision(0) << round(h);

    return 0;
}

