#include<iostream>
#include<vector>
using namespace std;

void combina(vector<int>& pos, int idx, int target, vector<int>& combin, vector<vector<int>>& res) {
    if (target == 0) {
        res.push_back(combin);
        return;
    }

    if (idx == pos.size() || target < 0) {
        return;
    }
    combin.push_back(pos[idx]);
    combina(pos, idx, target - 1, combin, res);
    combin.pop_back();
    combina(pos, idx + 1, target, combin, res);
}

int main() {
    vector<vector<int>> res;
    int target = 10;
    vector<int> pos = {0, 1};
    vector<int> combin;
    combina(pos, 0, target, combin, res);

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
