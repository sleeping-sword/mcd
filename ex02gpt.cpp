#include <bits/stdc++.h>
using namespace std;

int Sigma(vector<int> &a, vector<int> &b) {
    int sum = 0;
    int size = min(a.size(), b.size());
    for (int i = 0; i < size; ++i) {
        if (a[i] > b[i]) {
            sum += (a[i] - b[i]) * (a[i] - b[i]);
        } else {
            sum -= (a[i] - b[i]) * (a[i] - b[i]);
        }
    }
    return sum;
}

bool cmp(vector<int> &a, vector<int> &b) {
    if (a.size() != b.size()) {
        return a.size() > b.size();
    }
    return Sigma(a, b) > 0;
}

int main() {
    int N;
    cin >> N;
    vector<vector<int>> vecs(N);
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        vecs[i].resize(a);
        for (int j = 0; j < a; ++j) {
            cin >> vecs[i][j];
        }
        // for (int j = 0; j < a; ++j) {
        //     cout << vecs[i][j] << " ";
        // }
        //cout << "\n";
    }

    sort(vecs.begin(), vecs.end(), cmp);

    //cout << "Sorted Vectors:" << "\n";
    for (auto &vec : vecs) {
    if (!vec.empty()) {
        cout << vec[0];
        for (size_t i = 1; i < vec.size(); i++) {
            cout << " " << vec[i];
        }
    }
    cout << "\n";
}

    return 0;
}