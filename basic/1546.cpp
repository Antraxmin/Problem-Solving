#include <iostream>
using namespace std;

int main() {
    int cnt = 0; 
    int score[1000];
    long sum = 0, max = 0;
    cin >> cnt;

    for (int i = 0; i < cnt; i++) {
        cin >> score[i];
    }
    
    for(int i =0 ; i < cnt; i++) {
        if (score[i] > max) max = score[i];
        sum += score[i];
    }

    double result = sum * 100.0 / max / cnt;
    cout << result << "\n";
}
