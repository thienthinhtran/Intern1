#include <iostream>
#include <string>
#include <stack>
using namespace std;
string s, s1;
stack<char> st;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    getline(cin, s);

    s = s.substr(5, s.length() - 6);
   // cout << "check " << s << endl;

    for(int i = 0; i < s.length(); ++i){
        if(!st.empty() && ((st.top() == 'A' && s[i] == 'B') || (st.top() == 'C' && s[i] == 'D'))){
            st.pop();
        }
        else
            st.push(s[i]);
    }

    cout << st.size();
}
