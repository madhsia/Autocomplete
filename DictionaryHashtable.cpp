#include "util.hpp"
#include "DictionaryHashtable.hpp"
using namespace std;

/* Create a new Dictionary that uses a Hashset back end */
DictionaryHashtable::DictionaryHashtable(){}

/* Insert a word into the dictionary. */
bool DictionaryHashtable::insert(std::string word)
{
	auto exists = s.insert(word);
	if (exists.second == 1) {
		s.insert(word);
		return true;
	}
	return false;

}

/* Return true if word is in the dictionary, and false otherwise */
bool DictionaryHashtable::find(std::string word) const
{
	if (s.find(word) == s.end()) {
		return false;
	}
	return true;
}

/* Destructor */
DictionaryHashtable::~DictionaryHashtable(){}