
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    if (!(cin >> n)) {
        return 0;
    }
    
    vector<string> results;
    
    for (int i = 0; i < n; i++) {
        string line;
        cin.ignore();
        getline(cin, line);
        
        // Count variable declarations and scope levels
        int scope_level = 0;
        int max_scope = 0;
        set<string> variables;
        
        for (char c : line) {
            if (c == '{') {
                scope_level++;
                max_scope = max(max_scope, scope_level);
            } else if (c == '}') {
                scope_level--;
            }
        }
        
        results.push_back(to_string(max_scope));
    }
    
    for (const string& result : results) {
        cout << result << "\n";
    }
    
    return 0;
}
