#include <iostream>
#include <vector>
#include <fstream>
#include <unordered_set>
using namespace std;

bool hasRepeats(const vector<string>& cuts) {
    unordered_set<string> seen;
    for (const string& s : cuts) {
        if (seen.count(s)) return true;
        seen.insert(s);
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);

    int n;
    string mail;
    cin >> n >> mail;

    for (int k = 1; k <= n; ++k) {
        vector<string> cuts;
        for (int i = 0; i + k <= n; ++i) {
            cuts.push_back(mail.substr(i, k));
        }
        if (!hasRepeats(cuts)) {
            cout << k << "\n";
            break;
        }
    }

    return 0;
}
