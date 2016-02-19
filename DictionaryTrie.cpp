/* Name: Madeline Hsia
   Login: cs100wew */ 

#include "util.hpp"
#include "DictionaryTrie.hpp"
#include <queue>

using namespace std;

/* Create a new Dictionary that uses a Trie back end */
DictionaryTrie::DictionaryTrie(){
  //create empty trienode
	root = new TrieNode(false,0,0);
}

/* Insert a word with its frequency into the dictionary.
 * Return true if the word was inserted, and false if it
 * was not (i.e. it was already in the dictionary or it was
 * invalid (empty string) */

bool DictionaryTrie::insert(std::string word, unsigned int freq)
{
    TrieNode* curr = root;
    //null check if word is present or empty
    if (find(word) || word.empty()) return false;

    //for all letters in word
    for (unsigned int i=0; i < word.length(); i++) {
        //get the index
        int letter = (int)word[i]-(int)'a';
        if (word[i] == ' ') {
            letter = 26; //hardcode space
        }
        //create new nodes with word[i] as the text
        if (curr->children[letter] == NULL) {
            curr->children[letter] = new TrieNode(false,word[i],0);
        }
        //traverse down tree
        curr = curr->children[letter];
        //set freq and isword if reach end of word
        if (i == word.length()-1) {
            curr->freq = freq;
            curr->isWord = true;
        }        
    }
	return true;
}

/* Return true if word is in the dictionary, and false otherwise */
bool DictionaryTrie::find(std::string word) const
{
    TrieNode* curr = root;
    if (word.empty()) return false;
    //for the word searched
    for (unsigned int i=0; i<word.length(); i++) {
        int letter = (int)word[i]-(int)'a'; //get index of letter
        if (word[i] == ' ') letter = 26; //hardcode space
        if ((curr->children[letter]) == NULL) return false;
        //see if its a word when reached end of word
        if ((curr->children[letter]->isWord) && (i==word.length()-1)) {
            return true;
        }
        //traverse trie
        curr = curr->children[letter];
    }
    //else return false
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
  priority_queue<pair<unsigned int, string>> q;
  vector<std::string> words;
  TrieNode* curr = root;
  int letter;
  //null checks
  if (num_completions <= 0 || prefix.empty() || !root) return words;

  //find the prefix
  for (unsigned int i=0; i < prefix.length(); i++) {
    //if its a space, hard code to the 26th index
    if (prefix[i] == ' ') letter = 26;
    else letter = (int)prefix[i]-(int)'a'; //else find index
    //null test
    if (curr->children[letter] == NULL) return words; 
    //traverse down tree based on prefix char's location
    if (curr->children[letter]->text == prefix[i]) {
        curr = curr->children[letter];
    }
    else return words; //if not found return vector
  }

  //traverse tree
  traverseTrie(prefix,curr,q);
  
  //get num completion freqs
  for (unsigned int i=0; i < num_completions; i++) {
    //if empty, break
    if (q.empty()) break;
    //get pair from top of priorityqueue and add to vector
    pair<unsigned int,string> add = q.top();
    words.push_back(add.second);
    q.pop();
  }
  return words;
}

void DictionaryTrie::traverseTrie(std::string prefix, TrieNode*& node, 
                                  priority_queue<pair<unsigned int,string>>& q) {
  string word = prefix;
  char next;
  //null check
  if (node == NULL) return;
  //if isword, create pair w/ freq and word and add to pq
  if (node->isWord) {
    pair<unsigned int,string> p = make_pair(node->freq,word);
    q.push(p);
  }
  //for the node arrays
  for (char i=0; i<27;i++) { 
    //hardcode if space  
    if (i == 26) next = ' ';
    else next = i + 'a';
    //traverse trie 
    TrieNode* current = node->children[i];
    if(current) {
      word.push_back(next);
      //recursive call
      traverseTrie(word,current,q);
      word.pop_back(); //remove letter to reset prefix
    }
  }
}

/* Destructor */
DictionaryTrie::~DictionaryTrie(){
    deleteTrie(root);
    root = NULL;
}
  
/*recursive destructor*/
void DictionaryTrie::deleteTrie(TrieNode* ptr) {
    if (ptr == NULL) return;
    for (int i=0; i<27; i++) {
        deleteTrie(ptr->children[i]);
    }
    delete ptr;
}