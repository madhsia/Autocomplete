#include "util.hpp"
#include "DictionaryTrie.hpp"
using namespace std;

/* Create a new Dictionary that uses a Trie back end */
DictionaryTrie::DictionaryTrie(){
	root = new TrieNode();
}

/* Insert a word with its frequency into the dictionary.
 * Return true if the word was inserted, and false if it
 * was not (i.e. it was already in the dictionary or it was
 * invalid (empty string) */
 
bool DictionaryTrie::insert(std::string word, unsigned int freq)
{
    cout << "insert method started" << endl;
    TrieNode* curr = new TrieNode();
    curr = root;
    cout << "curr children at b is: " << curr->children[1] << endl;
    for (unsigned int i=0; i < word.length(); i++) {
        int letter = (int)word[i]-(int)'a';
        cout << "trying to insert letter b: " << letter << endl;
        if (curr->children[letter] == NULL) {
            curr->children[letter] = new TrieNode();
        }
        cout << "now children at b is: " << curr->children[1] << endl;
        cout << "now children at c is: " << curr->children[2] << endl;
        curr = curr->children[letter];
    }
    curr->isWord = true;
    //if word does not already exist
    //insert word and freq
    /*Node* curr = this;
    int length = word.length();
    string::const_iterator it = word.begin();

    for (int i=0; i < length, i++) {
        if (curr == NULL) {
            Node* temp = new Node(s[i]);
            curr = temp;
        }
        if (temp->data > s[i]){
            //add left
            curr = curr->left;

        }
        else if (temp->data < s[i]){
            //add right
            curr = curr->right;

        }
        else{
            //if wordended stop
            //else add mid 
        }

    }*/
	return true;
}

/* Return true if word is in the dictionary, and false otherwise */
bool DictionaryTrie::find(std::string word) const
{
    TrieNode* curr = new TrieNode();
    for (unsigned int i=0; i<word.length(); i++) {
        int letter = (int)word[i]-(int)'a';
        if ((curr->children[letter]) == NULL) {
            return false;
        }
        curr = curr->children[letter];
    }
    return curr->isWord;
}

/* Return up to num_completions of the most frequent completions
 * of the prefix, such that the completions are words in the dictionary.
 * These completions should be listed from most frequent to least.
 * If there are fewer than num_completions legal completions, this
 * function returns a vector with as many completions as possible.
 * If no completions exist, then the function returns a vector of size 0.
 * The prefix itself might be included in the returned words if the prefix
 * is a word (and is among the num_completions most frequent completions
 * of the prefix)
 */
std::vector<std::string> DictionaryTrie::predictCompletions(std::string prefix, unsigned int num_completions)
{
  std::vector<std::string> words;
  return words;
}

/* Destructor */
DictionaryTrie::~DictionaryTrie(){}