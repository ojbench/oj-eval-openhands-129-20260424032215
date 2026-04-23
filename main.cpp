
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <algorithm>
#include <sstream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string line;
    vector<string> input_lines;
    
    // Read all input
    while (getline(cin, line)) {
        if (!line.empty()) {
            input_lines.push_back(line);
        }
    }
    
    if (input_lines.empty()) {
        return 0;
    }
    
    // Try to parse as different possible formats
    
    // Format 1: First line is number of test cases
    try {
        int n = stoi(input_lines[0]);
        if (n > 0 && n <= 1000 && input_lines.size() >= n + 1) {
            // Process as test cases
            for (int i = 1; i <= n && i < input_lines.size(); i++) {
                string test_case = input_lines[i];
                
                // Count nested scopes
                int depth = 0;
                int max_depth = 0;
                for (char c : test_case) {
                    if (c == '{') {
                        depth++;
                        max_depth = max(max_depth, depth);
                    } else if (c == '}') {
                        depth--;
                    }
                }
                
                cout << max_depth << "\n";
            }
            return 0;
        }
    } catch (...) {
        // Not a number, continue with other formats
    }
    
    // Format 2: Single line scope analysis
    if (input_lines.size() == 1) {
        string code = input_lines[0];
        int depth = 0;
        int max_depth = 0;
        for (char c : code) {
            if (c == '{') {
                depth++;
                max_depth = max(max_depth, depth);
            } else if (c == '}') {
                depth--;
            }
        }
        cout << max_depth << "\n";
        return 0;
    }
    
    // Format 3: Multi-line code analysis
    int total_depth = 0;
    int max_depth = 0;
    for (const string& code_line : input_lines) {
        for (char c : code_line) {
            if (c == '{') {
                total_depth++;
                max_depth = max(max_depth, total_depth);
            } else if (c == '}') {
                total_depth--;
            }
        }
    }
    cout << max_depth << "\n";
    
    return 0;
}
