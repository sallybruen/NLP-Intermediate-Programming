#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

bool is_an_email(string s);

int main() {

    string filename;
    cout << "Enter file: \n";
    cin >> filename;

    ifstream f;
    f.open(filename);
    if(!f) {
        cout << "Could not open file\n";
        return 0;
    }

    vector<string> file_strings;
    string word;
    bool is_top_secret = false;

    while(f >> word) {
        file_strings.push_back(word);
    }

    for(int i = 0; i < file_strings.size(); i++) {
        if(file_strings[i] == "TOP-SECRET") {
            is_top_secret = true;
            break;
        }
    }

    if(is_top_secret) {
        ofstream email_file(filename + "_emails");
        for(int i; i < file_strings.size(); i++) {
            if(is_an_email(file_strings[i])) {
                cout << file_strings[i] << "\n";
                email_file << file_strings[i] << "\n";
            }
        }
    }
}

// vector<string> emails = {"amy@blah", "@blah", "blah@"};

// for(int i=0; i < emails.size(); i++) {
//   cout << emails[i] << ": ";
//   if(is_an_email(emails[i])) {
//     cout << "yep\n";
//   }
//   else {
//     cout << "nope\n";
//   }
// }

bool is_an_email(string s) {
    size_t pos;
    if(s.find('@') != string::npos) {
        pos = s.find('@');
        if(pos != 0 && pos != s.size()-1) {
            return true;
        }
    }
    return false;
}