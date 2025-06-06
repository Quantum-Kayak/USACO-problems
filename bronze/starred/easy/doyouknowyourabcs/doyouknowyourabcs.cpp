int main() {
    vi sums(7);
    for (int i = 0; i < 7; i++) {
        cin >> sums[i];
    }
    sort(all(sums));
    int total = sums[6]; // A + B + C

    for (int i = 0; i < 6; i++) {
        for (int j = i + 1; j < 6; j++) {
            for (int k = j + 1; k < 6; k++) {
                if (sums[i] + sums[j] + sums[k] == total) {
                    cout << sums[i] << " " << sums[j] << " " << sums[k] << "\n";
                    return 0;
                }
            }
        }
    }
    cout << "No valid solution found. Please consult a therapist or a debugger.\n";
    return 0;
}
