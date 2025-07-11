#include <iostream>
#include <vector>
using namespace std;

bool check(string s, char ch) {
    int mid = s.size() / 2;
    int leftCount = 0;
    for (int i = 0; i < mid; i++) {
        if (s[i] == ch) {
            leftCount++;
        }
    }
    int rightCount = 0;
    for (int i = mid + 1; i < s.size(); i++) {
        if (s[i] == ch) {
            rightCount++;
        }
    }
    return leftCount == rightCount;
}

int main() {
    vector<string> s = {"aabaaba", "bbaabb", "abbab", "aaabbb", "abbbbabbb"};
    int count = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i].size() % 2 != 0) {
            char ch = s[i][s[i].size() / 2];
            bool isBalanced = check(s[i], ch);
            if (isBalanced) {
                count++;
            }
        }
    }

    cout << "No. of balanced strings: " << count << endl;
    return 0;
}
