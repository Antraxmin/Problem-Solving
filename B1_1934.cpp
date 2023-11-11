#include <iostream>
using namespace std;

// 최대공약수를 구하는 함수 (유클리드 호제법)
int gcd(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

// 최소공배수를 구하는 함수
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int A, B;
        cin >> A >> B;

        int result = lcm(A, B);
        cout << result << '\n';
    }

    return 0;
}
