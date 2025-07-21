#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Find key with max value in map and remove it
int findMax(unordered_map<int, int>& mpp) {
    int maxVal = -100;
    int maxPos = -1;
    for (auto it : mpp) {
        if (it.second > maxVal) {
            maxVal = it.second;
            maxPos = it.first;
        }
    }
    mpp.erase(maxPos);
    return maxPos;
}

// Find key with min value in map and remove it
int findMin(unordered_map<int, int>& mpp) {
    int minVal = 100;
    int minPos = -1;
    for (auto it : mpp) {
        if (it.second < minVal) {
            minVal = it.second;
            minPos = it.first;
        }
    }
    mpp.erase(minPos);
    return minPos;
}

// Sort strings based on first character
void sortByFirst(const vector<string>& str) {
    unordered_map<int, int> mpp;
    for (int i = 0; i < str.size(); i++) {
        mpp[i] = str[i][0] - 'a';  // assumes lowercase letters
    }
    vector<string> str1;
    for (int i = 0; i < str.size(); i++) {
        int minIdx = findMin(mpp);
        str1.push_back(str[minIdx]);
    }

    cout << "\nStrings sorted by first character:\n";
    for (const auto& s : str1) {
        cout << s << endl;
    }
}

int main() {
    vector<string> str;
    int n;
    cout << "Enter number of strings: ";
    cin >> n;

    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        str.push_back(s);
    }

    // Sort by length using unordered_map
    unordered_map<int, int> mpp;
    for (int i = 0; i < str.size(); i++) {
        mpp[i] = str[i].size();
    }

    vector<string> str1;
    for (int i = 0; i < n; i++) {
        int maxIdx = findMax(mpp);
        str1.push_back(str[maxIdx]);
    }

    cout << "\nStrings sorted by length (descending):\n";
    for (const auto& s : str1) {
        cout << s << endl;
    }

    sortByFirst(str);

    return 0;
}
