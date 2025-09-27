#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <queue>
using namespace std;

struct Event {
    long long t, x, y;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int G, N;
    if (!(cin >> G >> N)) return 0;

    vector<Event> graz(G);
    for (auto &e : graz) {
        cin >> e.x >> e.y >> e.t;
    }
    sort(graz.begin(), graz.end(), [](const Event& a, const Event& b){
        return a.t < b.t;
    });

    int innocent = 0;

    for (int i = 0; i < N; ++i) {
        Event a; // alibi
        cin >> a.x >> a.y >> a.t;

        // find first grazing with time >= a.t
        auto it = lower_bound(
            graz.begin(), graz.end(), a.t,
            [](const Event& e, long long t){ return e.t < t; }
        );

        bool canBeGuilty = false;

        // Case A: alibi time is between two consecutive grazings
        if (it != graz.begin() && it != graz.end()) {
            const auto &L = *(it - 1); // left grazing (t <= a.t)
            const auto &R = *it;       // right grazing (t >= a.t)

            if (L.t <= a.t && a.t <= R.t) {
                long long dx1 = a.x - L.x, dy1 = a.y - L.y, dt1 = a.t - L.t;
                long long dx2 = R.x - a.x, dy2 = R.y - a.y, dt2 = R.t - a.t;

                long long need1 = dx1*dx1 + dy1*dy1; // distance^2 L -> alibi
                long long have1 = dt1*dt1;          // time^2
                long long need2 = dx2*dx2 + dy2*dy2; // distance^2 alibi -> R
                long long have2 = dt2*dt2;

                if (need1 <= have1 && need2 <= have2) {
                    canBeGuilty = true;
                }
            }
        }

        // Case B: before the first grazing
        if (!canBeGuilty && it == graz.begin()) {
            const auto &F = *it; // first grazing
            if (a.t <= F.t) {
                long long dx = F.x - a.x, dy = F.y - a.y, dt = F.t - a.t;
                long long need = dx*dx + dy*dy;
                long long have = dt*dt;
                if (need <= have) canBeGuilty = true;
            }
        }

        // Case C: after the last grazing
        if (!canBeGuilty && it == graz.end()) {
            const auto &L = graz.back();
            if (a.t >= L.t) {
                long long dx = a.x - L.x, dy = a.y - L.y, dt = a.t - L.t;
                long long need = dx*dx + dy*dy;
                long long have = dt*dt;
                if (need <= have) canBeGuilty = true;
            }
        }

        if (!canBeGuilty) ++innocent;
    }

    cout << innocent << '\n';
    return 0;
}
