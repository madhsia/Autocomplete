#include <iostream>
#include <fstream>
#include <sstream>
#include "util.hpp"
#include "DictionaryTrie.hpp"

/* Name: Madeline Hsia
   Login: cs100wew */

using namespace std;

void testStudent(std::string dict_filename){
    std::ifstream in;
    in.open(dict_filename, std::ios::binary);
    DictionaryTrie* dictTrie= new DictionaryTrie();

    Utils::load_dict(*dictTrie, in);
    dictTrie->predictCompletions("a",10);
}

int main(int argc, char *argv[]) {

    string s = "fuck";
    string h = "fuck";
    string i = "mad";
    string x = "dead";
    string dump = "basket";
    string ling = "basketball";
    string guggle = "guggle";
    string bask = "bask";
    string tok = "application";
    string one = "app"; //insert 1
    string two = "are you not entertained"; //insert 1
    string three = "a"; //find 1, reinsert 0
    string four = "never gonna give you up"; //reinsert 0, find 1
    string m = "a job in industry"; //0 find
    string r = "alaska"; //0 find
    string fuck = "azkaban";

   	cout << "----- Testing DictionaryTrie -----" << endl;
   	DictionaryTrie* dictTrie = new DictionaryTrie();

    cout << "should be 1: " << dictTrie->insert(s,20) << endl; //1
    cout << "should be 1: " << dictTrie->find(s) << endl; //1
    cout << "should be 0: " << dictTrie->insert(h,0) << endl; //0
    cout << "should be 1: " << dictTrie->insert(i,0) << endl; //1
    cout << "should be 1: " << dictTrie->find(h) << endl; //1
    //cout << "should be 1: " << dictTrie->find(i) << endl; //1
    //cout << "should be 0: " << dictTrie->find(x) << endl; //0
    cout << "should be 1: " << dictTrie->insert(tok,3) << endl; // application
    cout << "should be 1: " << dictTrie->insert(one,10) << endl;  // app
    cout << "should be 1: " << dictTrie->insert(two,1390) << endl; // are you not 
    cout << "should be 1: " << dictTrie->insert(three,2000) << endl; // a 
    //cout << "should be 0: " << dictTrie->insert(three,3) << endl; // 0
    cout << "should be 1: " << dictTrie->insert(four,1) << endl; // 1
    //cout << "should be 0: " << dictTrie->insert(four,1) << endl; 
    //cout << "should be 1: " << dictTrie->find(four) << endl;
    //cout << "should be 0: " << dictTrie->insert(two,1) << endl;
    //cout << "should be 0: " << dictTrie->insert(two,2) << endl;
    //cout << "should be 0: " << dictTrie->find(m) << endl;
    //cout << "should be 0: " << dictTrie->find(r) << endl; 
    cout << endl;
    dictTrie->insert(m,2); // a job in
    dictTrie->insert(r,2);
    dictTrie->insert(dump,2);
    dictTrie->insert(ling,1);
    dictTrie->insert(fuck,20);
    //tree has tok, one, two, three, four, m, and r, dump, ling
    cout << "----- Testing PredictCompletions -----" << endl;
    testStudent(argv[1]);
    //dictTrie->predictCompletions("a",10);
}