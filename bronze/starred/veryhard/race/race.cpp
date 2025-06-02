#include <iostream>
#include <climits>
using namespace std;

typedef long long ll;

void setIO(const string& name = "") {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main() {
    setIO("race");
    int N;
    ll tot_dis;
    cin >> tot_dis >> N;

    for (int i = 0; i < N; i++) {
        int X;
        cin >> X;

        int min_time = INT_MAX;

        // Case 1: If distance is small enough, just accelerate to some peak ≤ X
        if (tot_dis <= (ll)X * (X + 1) / 2) {
            int speed = 0, dis = 0, time_ = 0;
            while (dis < tot_dis) {
                speed++;
                dis += speed;
                time_++;
            }
            min_time = time_;
        } else {
            // Case 2: Need to go beyond X, peak > X
            for (int peak_speed = X; peak_speed <= 100000; peak_speed++) {
                ll dis = 0;
                int speed = 0;
                int time_ = 0;

                // Accelerate
                while (speed < peak_speed) {
                    speed++;
                    dis += speed;
                    time_++;
                }

                // Decelerate
                int tmp_speed = peak_speed;
                while (tmp_speed > X) {
                    tmp_speed--;
                    dis += tmp_speed;
                    time_++;
                }

                if (dis > tot_dis) continue;

                // Cruise if needed
                ll remaining_dis = tot_dis - dis;
                if (remaining_dis > 0) {
                    time_ += (remaining_dis + peak_speed - 1) / peak_speed;
                }

                if (time_ < min_time) {
                    min_time = time_;
                }
            }
        }

        cout << min_time << '\n';
    }

    return 0;
}
