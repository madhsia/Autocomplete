#include "util.hpp"
#include "DictionaryBST.hpp"
using namespace std;

/* Create a new Dictionary that uses a BST back end */
DictionaryBST::DictionaryBST(){}

/* Insert a word into the dictionary. */
bool DictionaryBST::insert(std::string word)
{
	//null check
	if (word.empty() || this->find(word)) return false;
	//if doesnt exist, insert
	else {
		s.insert(word);
		return true;
	}
	return false;
}

/* Return true if word is in the dictionary, and false otherwise */
bool DictionaryBST::find(std::string word) const
{
	//if find is not at end, its not found
	if (s.find(word) == s.end()) return false;
	return true;
}

/* Destructor */
DictionaryBST::~DictionaryBST(){
}