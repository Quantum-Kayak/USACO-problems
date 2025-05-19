#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;
int main() {
    int n;
    vector<int> arr;
    unordered_map<int, int> freq;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int num : arr) {
        freq[num]++;
    }
    
    vector<int> only_once;
    for (const auto& [key, count] : freq) {
        if (count == 1) {
            only_once.push_back(key);
        }
    }
    for (int num : only_once) {
        cout << num << " ";
    }
    return 0;
}
