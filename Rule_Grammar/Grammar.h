//
// Created by ahmed on 20/11/2021.
//

#include "Rule.h"
#include <vector>

using namespace std;

class Grammar {
public:
    Grammar();
    Grammar(string filename);
    vector<Rule> rules;
    void show();

};