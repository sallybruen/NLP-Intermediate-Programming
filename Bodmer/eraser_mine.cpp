#include <string>
#include <iostream>
#include <fstream>
using namespace std;

bool is_vowel(char c);
bool is_cons(char c);

int main() {
    ifstream thefile;
    thefile.open("afile_from_bodmer.txt");

    cout << "elim which?: enter 1 for vowels or 2 for cons\n";
    int choice;
    cin >> choice;

    string s;
    while (getline(thefile, s)) {
        for (int i = 0; i < s.length(); i++) {
            if (choice == 1 && is_vowel(s[i])) {
                s[i] = '*';

            }else if (choice == 2 && is_cons(s[i])) {
                s[i] = '*';
            }

        }
        cout << s;
    }
}

    bool is_vowel(char c) {

        if (c == 'a') {
            return true;
        }
        else if (c == 'e') {
            return true;
        }
        else if (c == 'i') {
            return true;
        }
        else if (c == 'o') {
            return true;
        }
        else if (c == 'u') {
            return true;
        }
        else {
            return false;
        }

    }


    bool is_cons(char c) {
        if(is_vowel(c)) {
            return false;
        }
        else if(c >= 97 && c <= 122) {
            return true;
        }
        else {
            return false;
        }
    }




