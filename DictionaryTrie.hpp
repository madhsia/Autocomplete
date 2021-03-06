/**
 *  CSE 100 PA3 C++ Autocomplete
 *  Authors: Jor-el Briones, Christine Alvarado
 */

 /* Name: Madeline Hsia
   Login: cs100wew */ 

#ifndef DICTIONARY_TRIE_HPP
#define DICTIONARY_TRIE_HPP

#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <utility>

using namespace std;

/**
 *  The class for a dictionary ADT, implemented as a trie
 *  You may implement this class as either a mulit-way trie
 *  or a ternary search trie, but you must use one or the other.
 *
 */

  //multiway
class TrieNode {
  public:
    vector<TrieNode*>children = vector<TrieNode*>(27, (TrieNode*)0);
    char text;
    unsigned int freq;
    bool isWord;

    /* trieNode constructore w isWord, char text, and freq */
    TrieNode(bool isWord, char text, unsigned int freq){
      this->isWord = isWord;
      this->text = text;
      this->freq = freq;
    }
};

class DictionaryTrie
{
public:

  /* Create a new Dictionary that uses a Trie back end */
  DictionaryTrie();

  /*deleteTrie recursive helper method for destructor*/
  void deleteTrie(TrieNode* ptr);

  /*traverseTrie recursive helper method for predictCompletions*/
  void traverseTrie(std::string prefix, TrieNode*& node, priority_queue<pair<unsigned int, string>>& q);

  /* Insert a word with its frequency into the dictionary.
   * Return true if the word was inserted, and false if it
   * was not (i.e. it was already in the dictionary or it was
   * invalid (empty string) */
  bool insert(std::string word, unsigned int freq);

  /* Return true if word is in the dictionary, and false otherwise */
  bool find(std::string word) const;

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
  std::vector<std::string>
  predictCompletions(std::string prefix, unsigned int num_completions);

  /* Destructor */
  ~DictionaryTrie();

private:
  TrieNode* root;
};

#endif // DICTIONARY_TRIE_HPP
