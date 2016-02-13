#include "util.hpp"
#include "DictionaryBST.hpp"
using namespace std;

/* Create a new Dictionary that uses a BST back end */
DictionaryBST::DictionaryBST(){}

/* Insert a word into the dictionary. */
bool DictionaryBST::insert(std::string word)
{
	if (word.empty()) return false;
	auto exists = s.insert(word);
	if (exists.second == 1) {
		s.insert(word);
		return true;
	}
	return false;
}

/* Return true if word is in the dictionary, and false otherwise */
bool DictionaryBST::find(std::string word) const
{
	if (s.find(word) == s.end()) {
		return false;
	}
	return true;
}

/* Destructor */
DictionaryBST::~DictionaryBST(){

}