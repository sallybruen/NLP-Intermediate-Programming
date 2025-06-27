#include "Grammar.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

int main(int argc, char *argv[]) {

    /*if(argc != 2) {
       cout << "need to give a filename for the grammar\n";
        exit(1);
    }

    string fname;
    fname = string(argv[1]);*/

    Grammar g("computergram.txt");
    g.show();

}