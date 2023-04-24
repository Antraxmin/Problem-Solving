#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<long> sum(N, 0);
    vector<long> idx(M, 0);
    long ans = 0;
    cin >> sum[0];

    for (int i = 1; i < N; i++) {
        int tmp = 0;
        cin >> tmp;
        sum[i] = sum[i-1] + tmp;
    }

    for (int i = 0; i < N; i++) {
        int x = sum[i] % M;
        if (x == 0) ans++;
        idx[x]++;
    }

    for (int i = 0; i < M; i++) {
        if (idx[i] > 1) ans += (idx[i] * (idx[i]-1) / 2);
    }
    cout << ans << "\n";
}
