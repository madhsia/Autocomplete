#include "util.hpp"
#include "DictionaryHashtable.hpp"
using namespace std;

/* Create a new Dictionary that uses a Hashset back end */
DictionaryHashtable::DictionaryHashtable(){}

/* Insert a word into the dictionary. */
bool DictionaryHashtable::insert(std::string word)
{
	//null check
	if (word.empty() || this->find(word)) return false;
	//auto exists = s.insert(word);
	//if doesnt exists, insert
	else {
		s.insert(word);
		return true;
	}
	return false;

}

/* Return true if word is in the dictionary, and false otherwise */
bool DictionaryHashtable::find(std::string word) const
{
	//if findWord is not end, then it's not found
	if (s.find(word) == s.end()) return false;
	return true;
}

/* Destructor */
DictionaryHashtable::~DictionaryHashtable(){}