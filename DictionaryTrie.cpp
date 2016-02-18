/* Name: Madeline Hsia
   Login: cs100wew */ 

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

    if (find(word) || word.empty()) {
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
  int letter;
  int freq;

  if (num_completions == 0 || prefix.empty() || !root) {
    return words;
  }

  //find the prefix
  for (unsigned int i=0; i < prefix.length(); i++) {
    if (prefix[i] == ' ') letter = 26;
    else letter = (int)prefix[i]-(int)'a';
    
    if (curr->children[letter] == NULL) {
      cout << "Prefix '" << prefix << "' is not found" << endl;
      return words;
    }
    if (curr->children[letter]->text == prefix[i]) {
        curr = curr->children[letter];
    }
    else return words;
  }

  cout << "The prefix searched for is: " << prefix << endl;
  cout << "Curr is now pointing to: " << curr->text << endl;

  //traverse tree
  for (unsigned int i=0; i<26; i++) {
    if (curr->children[i] != NULL) {
    	  traverseTrie(prefix,curr,words);
        curr = curr->children[i];
	  }
  }

  cout << "Vector size: " << words.size() << endl;
  cout << words[5] << endl;

  pair<string,int> thePair (words[2], freq);
  priority_queue<TrieNode*> q;

  for (q.push(root); !q.empty(); q.pop()){
    //const TrieNode* const temp = q.top();
  }
  return words;
}

void DictionaryTrie::traverseTrie(std::string prefix, TrieNode*& node, vector<std::string>& words) {
  string word = prefix;
  char next; 
  if (node->isWord) {
    words.push_back(word);
  }
  for (char i=0; i<27;i++) {   
    if (i == 26) next = ' ';
    else next = i + 'a';

    TrieNode* current = node->children[i];
    if(current) {
      word.push_back(next);
      cout << word << endl;
      traverseTrie(word,current,words);
      word.pop_back();
    }
  }
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