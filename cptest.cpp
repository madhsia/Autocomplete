#include <iostream>
#include <fstream>
#include <sstream>
#include "DictionaryBST.hpp"
#include "DictionaryHashtable.hpp"
#include "DictionaryTrie.hpp"

using namespace std;

int main(int argc, char *argv[]) {

    //std::ifstream in;
    //in.open(dict_filename, std::ios::binary);

    DictionaryBST* dict = new DictionaryBST();
    string s = "fuck";
    string h = "fuck";
    string i = "mad";
    string x = "dead";
    string a = "bc";
    string b = "bc";
    cout << dict->insert(s) << endl; //1
   	cout << dict->find(s) << endl; //1
   	cout << dict->insert(h) << endl; //0
   	cout << dict->insert(i) << endl; //1
   	cout << dict->find(h) << endl; //1
   	cout << dict->find(i) << endl; //1
   	cout << dict->find(x) << endl; //0

    cout << endl;
   	cout << "testing hashtable" << endl;
   	DictionaryHashtable* dictHash = new DictionaryHashtable();
    cout << dictHash->insert(s) << endl; //1
   	cout << dictHash->find(s) << endl; //1
   	cout << dictHash->insert(h) << endl; //0
   	cout << dictHash->insert(i) << endl; //1
   	cout << dictHash->find(h) << endl; //1
   	cout << dictHash->find(i) << endl; //1
   	cout << dictHash->find(x) << endl; //0

    cout << endl;
   	cout << "testing trie" << endl;
   	DictionaryTrie* dictTrie= new DictionaryTrie();
    cout << dictTrie->insert(a,0) << endl; //1
    cout << dictTrie->insert(b,0) << endl; //1

}