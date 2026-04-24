#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> words;
int pos_idx = 0;
string res = "";
bool error_flag = false;

void parse() {
    if (pos_idx >= words.size()) {
        error_flag = true;
        return;
    }
    
    if (words[pos_idx] == "int") {
        res += "int";
        pos_idx++;
    } else {
        res += "pair<";
        pos_idx++;
        
        parse(); // Left child
        res += ",";
        parse(); // Right child
        
        res += ">";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    if (!(cin >> n)) return 0;
    
    string s;
    while (cin >> s) {
        words.push_back(s);
    }
    
    parse();
    
    if (error_flag || pos_idx < words.size()) {
        cout << "Error occurred\n";
    } else {
        cout << res << "\n";
    }
    
    return 0;
}