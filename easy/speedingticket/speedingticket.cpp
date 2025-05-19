#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Road {
    int seg;
    int lim;
};

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    freopen("speedingticket.in", "r", stdin);   
    freopen("speedingticket.out", "w", stdout); 

    vector<Road> roadSegments, bessieSegments;

    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int seg, lim;
        cin >> seg >> lim;
        roadSegments.push_back({seg, lim});
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        int seg, lim;
        cin >> seg >> lim;
        bessieSegments.push_back({seg, lim});
    }

    int road[100] = {};
    int bessie[100] = {};

    int pos = 0;
    for (auto& r : roadSegments) {
        for (int i = 0; i < r.seg; i++) {
            road[pos++] = r.lim;
        }
    }

    pos = 0;
    for (auto& r : bessieSegments) {
        for (int i = 0; i < r.seg; i++) {
            bessie[pos++] = r.lim;
        }
    }

    int maxOver = 0;
    for (int i = 0; i < 100; i++) {
        maxOver = max(maxOver, bessie[i] - road[i]);
    }

    cout << maxOver << '\n';
    return 0;
}
