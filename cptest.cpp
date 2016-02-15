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
/*int testsPassed = 0;
    
    // CHECKPOINT TEST 1: Hashtable
    cout << "////////// HASHTABLE //////////" << endl;
    DictionaryHashtable table;
    // Valid string insertion
    cout << "Inserting a valid string..."; 
    if (table.insert("lol"))
    {
        testsPassed++;
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED :(" << endl;
    }
    // Duplicate string insertion
    cout << "Inserting a duplicate string..."; 
    if (table.insert("lol") == false)
    {
        testsPassed++;
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED :(" << endl;
    }
    // Empty string insertion
    cout << "Inserting an empty string..."; 
    if (table.insert("") == false)
    {
        testsPassed++;
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED :(" << endl;
    }
    // Valid string search
    cout << "Searching for a word in the dictionary...";
    if (table.find("lol"))
    {
        testsPassed++;
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED :(" << endl;
    }
    // Invalid string search
    cout << "Searching for a word not in the dictionary...";
    if (table.find("") == false)
    {
        testsPassed++;
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED :(" << endl;
    }
    
    // CHECKPOINT TEST 2: BST
    cout << "////////// BST //////////" << endl;
    DictionaryBST bst;
    // Valid string insertion
    cout << "Inserting a valid string..."; 
    if (bst.insert("omg"))
    {
        testsPassed++;
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED :(" << endl;
    }
    // Duplicate string insertion
    cout << "Inserting a duplicate string..."; 
    if (bst.insert("omg") == false)
    {
        testsPassed++;
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED :(" << endl;
    }
    // Empty string insertion
    cout << "Inserting an empty string..."; 
    if (bst.insert("") == false)
    {
        testsPassed++;
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED :(" << endl;
    }
    // Valid string search
    cout << "Searching for a word in the dictionary...";
    if (bst.find("omg"))
    {
        testsPassed++;
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED :(" << endl;
    }
    // Invalid string search
    cout << "Searching for a word not in the dictionary...";
    if (table.find("") == false)
    {
        testsPassed++;
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED :(" << endl;
    }

    // CHECKPOINT TEST 3: Trie
    DictionaryTrie trie;
    cout << "////////// TRIE //////////" << endl;
    // Valid string insertion
    cout << "Inserting a valid string..."; 
    if (trie.insert("omg", 5))
    {
        testsPassed++;
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED :(" << endl;
    }
    // Duplicate string insertion
    cout << "Inserting a duplicate string..."; 
    if (trie.insert("omg", 10) == false)
    {
        testsPassed++;
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED :(" << endl;
    }
    // Empty string insertion
    cout << "Inserting an empty string..."; 
    if (trie.insert("", 10) == false)
    {
        testsPassed++;
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED :(" << endl;
    }
    // Valid string search
    cout << "Searching for a word in the dictionary...";
    if (trie.find("omg"))
    {
        testsPassed++;
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED :(" << endl;
    }
    // Invalid string search
    cout << "Searching for a word not in the dictionary...";
    if (trie.find("") == false)
    {
        testsPassed++;
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED :(" << endl;
    }

    // GOOD TO GO?
    if (testsPassed == 15)
    {
        cout << "////////// RESULTS //////////" << endl;
        cout << "OMG YAY!" << endl;
        cout << "You're good to go! :)" << endl;
    }
    */
    cout << "----- fukthisshit -----" << endl;

    string s = "fuck";
    string h = "fuck";
    string i = "mad";
    string x = "dead";
    string a = "bc";
    string b = "bc";
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

   	cout << "----- Testing DictionaryTrie -----" << endl;
   	DictionaryTrie* dictTrie= new DictionaryTrie();

    cout << "should be 1: " << dictTrie->insert(s,20) << endl; //1
    cout << "should be 1: " << dictTrie->find(s) << endl; //1
    cout << "should be 0: " << dictTrie->insert(h,0) << endl; //0
    cout << "should be 1: " << dictTrie->insert(i,0) << endl; //1
    cout << "should be 1: " << dictTrie->find(h) << endl; //1
    cout << "should be 1: " << dictTrie->find(i) << endl; //1
    cout << "should be 0: " << dictTrie->find(x) << endl; //0
    cout << "should be 1: " << dictTrie->insert(tok,1) << endl;
    cout << "should be 1: " << dictTrie->insert(one,1) << endl; 
    cout << "should be 1: " << dictTrie->insert(two,1) << endl;
    cout << "should be 1: " << dictTrie->insert(three,1) << endl; // 1
    cout << "should be 0: " << dictTrie->insert(three,3) << endl; // 0
    cout << "should be 1: " << dictTrie->insert(four,1) << endl; // 1
    cout << "should be 0: " << dictTrie->insert(four,1) << endl; 
    cout << "should be 1: " << dictTrie->find(four) << endl;
    cout << "should be 0: " << dictTrie->insert(two,1) << endl;
    cout << "should be 0: " << dictTrie->insert(two,2) << endl;
    cout << "should be 0: " << dictTrie->find(m) << endl;
    cout << "should be 0: " << dictTrie->find(r) << endl; 
    cout << endl;
    cout << "----- Testing PredictCompletions -----" << endl;
    dictTrie->predictCompletions("app",10);
    
}