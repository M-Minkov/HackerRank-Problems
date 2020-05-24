#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


int main() {
    
    unordered_map <int, int> amounts;
    float median, mean;
    float most, num;
    most = 0;
    int N;
    float N1;
    cin >> N;
    N1 = N;
    long long sum=0;
    float x[N];
    for(int i;i<N;i++) {
        cin >> x[i];
        sum += x[i];
        if(amounts.count(x[i])) {
            amounts[x[i]]++;
        }
        else {
            amounts[x[i]] = 1;
        }

        if(amounts[x[i]] > most) {
            most = amounts[x[i]];
            num = x[i];
        }
        else if(amounts[x[i]] == most && num > x[i]) {
            num = x[i];
        }
    }
    int n = sizeof(x)/sizeof(x[0]);
    sort(x, x+n);
    if ((N-1) % 2 == 0) {
        median = x[(N-1)/2];
    }
    else {
        median = (x[(N-1)/2] + x[((N-1)/2)+1])/2;
    }
    mean = sum/N1;

    cout << mean << endl << median << endl << num;
}
