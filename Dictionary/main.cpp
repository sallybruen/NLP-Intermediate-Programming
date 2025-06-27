/*********************************/
/* tests the Trans_Dict class    */
/*********************************/
#include <iostream>
#include "TranslationDictionary.h"
#include <stdlib.h>

using namespace std;

void tester_function(Trans_Dict& d, string name, vector<string> fr_words);
void tester_function1(Trans_Dict& d, string name, vector<string> en_words);


int main() {
    Trans_Dict d1("translist.txt");
    Trans_Dict d2("translist2.txt");

    if (!d1.opened_ok) {
        cerr << "dictionary to translist did not open ok\n";
        exit(0);
    }
    if (!d2.opened_ok) {
        cerr << "dictionary to translist2 did not open ok\n";
        exit(0);
    }

    vector<string> fr_words;
    fr_words = {"soulier", "jupe", "chien"};
    tester_function(d1, "translist", fr_words);
    cout << "------------\n";

    fr_words.clear();
    fr_words = {"chien", "oiseau", "soulier"};
    tester_function(d2, "translist2", fr_words);
    cout << "------------\n";

    vector<string> en_words;
    en_words = {"shoe" , "hat"};
    tester_function1(d1, "translist", en_words);
    cout << "------------\n";

    d1.update("chapeau","hat");
    cout << "test d1 after adding chapeau/hat\n";
    tester_function1(d1, "translist", en_words);
    cout << "------------\n";

    fr_words.clear();
    fr_words.emplace_back("chien");
    d1.update("chien","hound");
    cout << "test d2 after adding chien/hound\n";
    tester_function1(d2, "translist2", fr_words);
    cout << "------------\n";



}
    /* you could replace the above series of tests with the following
       more economical code which use a function to run the tests

     */
    // fr_words = {"soulier", "jupe", "chien"};
    // tester_function(d1, "translist", fr_words);
    // fr_words = {"chien", "oiseau", "soulier"};
    // tester_function(d2, "translist2", fr_words);



void tester_function(Trans_Dict& d, string name, vector<string> fr_words) {
    string trans_english;
    for(unsigned int i=0; i < fr_words.size(); i++) {
        if(d.lookup(fr_words[i],trans_english)) {
            cout << name << " trans of " << fr_words[i] << " is " << trans_english << endl;
        }
        else {
            cout << "no " << name << " trans of " << fr_words[i] << endl;
        }
    }

}

void tester_function1(Trans_Dict& d, string name, vector<string> en_words) {
    string trans_french;
    for(unsigned int i=0; i < en_words.size(); i++) {
        if(d.frenchWord_lookup(en_words[i],trans_french)) {
            cout << name << " trans of " << en_words[i] << " is " << trans_french << endl;
        }
        else {
            cout << "no " << name << " trans of " << en_words[i] << endl;
        }
    }
}