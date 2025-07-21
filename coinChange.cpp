#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void findChange(int target, vector<int>& coins, int idx, int& amt) {
    if (target == 0 || idx < 0) {
        return;
    }

    if (target >= coins[idx]) {
        int count = target / coins[idx];
        amt += count;
        target -= count * coins[idx];
    }

    findChange(target, coins, idx - 1, amt);
}

int main() {
    vector<int> coins = {1,2,5,10,20,50,100,200,500,2000};
    sort(coins.begin(), coins.end());
    int target;
    cout << "Enter target" << endl;
    cin >> target;
    int amt = 0;
    findChange(target, coins, coins.size() - 1, amt);
    cout << amt << endl;
    return 0;
}
