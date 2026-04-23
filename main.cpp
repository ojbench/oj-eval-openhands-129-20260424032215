
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <algorithm>
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
        
        // Simple scope analysis - count nested blocks
        int depth = 0;
        int max_depth = 0;
        for (char c : line) {
            if (c == '{') {
                depth++;
                max_depth = max(max_depth, depth);
            } else if (c == '}') {
                depth--;
            }
        }
        
        results.push_back(to_string(max_depth));
    }
    
    for (const string& result : results) {
        cout << result << "\n";
    }
    
    return 0;
}
