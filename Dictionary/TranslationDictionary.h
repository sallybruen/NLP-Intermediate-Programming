/******** TranslationDictionary.h ************************/
#include <string>
#include <vector>
using namespace std;

// a struct rather than a class will do for this
// has not methods
struct Transpair {
    string french;
    string english;
};

class Trans_Dict {

private:
    vector<Transpair> thewords;

public:
    Trans_Dict();      /* constructor */
    Trans_Dict(string file_name);      /* constructor */
    bool opened_ok;
    bool lookup(string word, string& trans);

    bool frenchWord_lookup( string word, string& trans);

    bool update(string french, string english);

    bool export_to_file(string filename);
};



