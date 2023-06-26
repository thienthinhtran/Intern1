#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include<sstream>

using namespace std;
vector<string> strs;
string s;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> anagramGroups;

    for (const auto& str : strs) {
        string sortedStr = str;
        sort(sortedStr.begin(), sortedStr.end());
        anagramGroups[sortedStr].push_back(str);
    }

    vector<vector<string>> result;
    for (const auto& pair : anagramGroups) {
        result.push_back(pair.second);
    }

    return result;
}

int main() {
    //vector<string> strs = { "eat", "tea", "tan", "ate", "nat", "bat" };
    ios::sync_with_stdio(0);
    cin.tie(0);
    getline(cin, s);
   // cout << s.length() << endl;

    s = s.substr(8, s.length() - 9);
    //cout << "CHECK " << s<<endl;

    //cout << "check " << "// " << s[s.length() - 1] << " ** " << s << endl;
    //
    vector<std::string> substrings;
    stringstream ss(s);
    string substring;

    while (std::getline(ss, substring, ',')) {
        substrings.push_back(substring);
       // cout << "sub " << substring << endl;
    }

    //
    vector<vector<string>> groupedAnagrams = groupAnagrams(substrings);

    bool check = false;
    cout << '[';
    for (const auto& group : groupedAnagrams) {
        if(check)
            cout << ',';
        cout << '[';
        bool check1 = false;
        for (const auto& str : group) {
            if(check1)
                cout << ',';
            cout << str;
            check1 = true;
        }
        cout << ']';
        check = true;
    }
    cout << ']';
    return 0;
}
