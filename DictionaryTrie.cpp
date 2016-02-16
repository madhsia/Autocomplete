#include "util.hpp"
#include "DictionaryTrie.hpp"
#include <queue>

using namespace std;

/* Create a new Dictionary that uses a Trie back end */
DictionaryTrie::DictionaryTrie(){
	root = new TrieNode(false,0,0);
}

/* Insert a word with its frequency into the dictionary.
 * Return true if the word was inserted, and false if it
 * was not (i.e. it was already in the dictionary or it was
 * invalid (empty string) */

bool DictionaryTrie::insert(std::string word, unsigned int freq)
{
    TrieNode* curr = root;

    if (find(word)) {
        return false;
    }
    if (word.empty()) {
        return false;
    }
    for (unsigned int i=0; i < word.length(); i++) {
        int letter = (int)word[i]-(int)'a';
        if (word[i] == ' ') {
            letter = 26;
        }
        if (curr->children[letter] == NULL) {
            curr->children[letter] = new TrieNode(false,word[i],0);
        }

        if (i == word.length()-1) {
            curr->freq = freq;
        }
        curr = curr->children[letter];        
    }
    curr->isWord = true;
	return true;
}

/* Return true if word is in the dictionary, and false otherwise */
bool DictionaryTrie::find(std::string word) const
{
    TrieNode* curr = root;
    if (word.empty()) return false;

    for (unsigned int i=0; i<word.length(); i++) {
        int letter = (int)word[i]-(int)'a';
        if (word[i] == ' ') {
            letter = 26;
        }
        if ((curr->children[letter]) == NULL) {
            return false;
        }
        if ((curr->children[letter]->isWord) && (i==word.length()-1)) {
            return true;
        }
        curr = curr->children[letter];
    }
    return false;
}

string DictionaryTrie::traverseTrie(std::string prefix, TrieNode*& node) {
	string word;
	int x =0;
	if (node->isWord) {
		//cout << prefix << endl;
	}
	for (char i=0; i<27;++i) {
		char next = i + 'a';
		TrieNode* current = node->children[i];
		if(current) {
			prefix += next;
			//prefix.push_back();
			traverseTrie(prefix,current);
			//prefix.pop_back();
		}
	}
	return prefix;
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

  TrieNode* curr = root;
  
  if (num_completions == 0 || prefix.empty() || !root) {
    return words;
  }

  for (unsigned int i=0; i<prefix.length(); i++) {
    int letter = (int)prefix[i]-(int)'a';
    if (curr->children[letter] == NULL) break;
    if (curr->children[letter]->text == prefix[i]) {
        curr = curr->children[letter];
        //cout << i+1 << "th for loop" << endl;
        //cout << curr->text << endl;
    }
    else return words;
  }

  cout << "the prefix searched for is: " << prefix << endl;
  cout << "curr is now pointing to: " << curr->text << endl;

  /*for (unsigned int i=0; i<27; i++) {
    if (curr->children[i] != NULL) {
        theWord += curr->children[i]->text;
    	//curr = curr->children[i];
	}
  }
    cout << "theWord: " << theWord << endl;*/

  string theWord = traverseTrie(prefix,curr);
  cout << "word found in trie with prefix: " << theWord << endl;

  priority_queue<TrieNode*> q;

  for (q.push(root); !q.empty(); q.pop()){
    const TrieNode* const temp = q.top();
    cout << temp->text << " ";
    //if (temp->children[]) {
    //    q.push ??
    //}
  }

  /* 
    1. get all words that have that prefix
        2) The next step is to search through the subtree rooted at the end of the 
        prefix to find the num_completion most likely completions of the prefix.  
    2. compare the frequencies
    3. put num_completions amount of it in words
  */
  
  return words;
}

/* Destructor */
DictionaryTrie::~DictionaryTrie(){
    deleteTrie(root);
    root = NULL;
}

void DictionaryTrie::deleteTrie(TrieNode* ptr) {
    if (ptr == NULL) return;
    for (int i=0; i<27; i++) {
        deleteTrie(ptr->children[i]);
    }
    delete ptr;
}