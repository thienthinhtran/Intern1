#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;
vector<string> strs;
string s;

unordered_map<string, vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> anagramGroups;

    for (const auto& str : strs) {
        //string sortedStr = str;
        // Sort sortedStr using counting sort
        int count[26] = {0};  // lowercase only
        for (char ch : str) {
            count[ch - 'a']++;
        }
        string sortedStr = "";
        for (int i = 0; i < 26; i++) {
            sortedStr += string(count[i], i + 'a');
        }
        // End of counting sort

        anagramGroups[sortedStr].push_back(str);
    }
    return anagramGroups;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    getline(cin, s);

    s = s.substr(8, s.length() - 9);

    vector<std::string> substrings;
    stringstream ss(s);
    string substring;

    while (std::getline(ss, substring, ',')) {
        substrings.push_back(substring);
    }
    cout <<'[';
    unordered_map<string, vector<string>> ans = groupAnagrams(substrings);
    bool check1 = false;
    for (const auto& pair : ans) {
        if(check1 == true)
            cout << ',';
        bool check = false;
        cout << '[';
        for (const auto& str : pair.second) {
            if(check)
                cout << ',';
            cout << str;
            check = true;
        }
        cout << ']';
    check1 = true;
    }
    cout << ']';
    return 0;
}
