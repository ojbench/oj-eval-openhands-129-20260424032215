
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        
        int balance = 0;
        int max_depth = 0;
        
        for (char c : s) {
            if (c == '(') {
                balance++;
                max_depth = max(max_depth, balance);
            } else if (c == ')') {
                balance--;
            }
        }
        
        cout << max_depth << "\n";
    }
    
    return 0;
}
