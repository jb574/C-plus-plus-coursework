#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
using namespace std;


//typedef because i cant be bothered to type the extra characters.
typedef unordered_map<string, int> phraseMapper;

/**
 * file that completes task three
 * of the lz assessment
 *@author Jack Davey
 *@version 6th January 2014
 */

/**
 *functiont hat devides
 * the file into phrases and gives a sequence
 * number to each
 *@parameters the map of phrases and sequence numbers to use
 **/
void computePhrasePairs(phraseMapper & phrases);


/**
 * check if we have already found
 * the supplied phrase
 *@param phrase the phrase to look
 * @param phrases the set of phrases to search in
 *@return  true if this phrase it in here, false if not
 */
bool isPhraseFound(phraseMapper & phrases,string phrase);

/**
 *@param currentChar the character that we are attempting to read into
 *@return whether we still have input left to process
 **/
bool stillInputToProcess(char & currentChar);

/**
 * function that outputs the found phrase to the console
 * and adds it to the provided map along with the new sequence number
 *@param phrases the map of phrases to add to
 *@param sequenceNumber the new sequenceNumber
 @param currentPhrase the phrase to deal with
 **/
void recordNewPhrase(phraseMapper & phrases, string & currentPhrase,int seqenceNumber);




/**
 *function that escapes
 * the char parameter given
 *@parameters as above
 *@return a string containing the escaped char
 **/
string escapeChar(char ch);


/**
 *pretty standaard faucntion
 * to escape chers that are unseaual
 *@parameters the char we want to escape
 *@return the escaped char
 **/
string escapeDodgyChar(char ch);


int main()
{
    phraseMapper phrases;
    phrases.insert(make_pair("", 0));
    computePhrasePairs(phrases);
    return 0;
}

void computePhrasePairs(unordered_map< string, int> & phrases)
{
    string currentPhrase;
    char currentChar;
    currentPhrase = "";
    int sequenceNumber = 1;
    while (stillInputToProcess(currentChar))
    {
        currentPhrase = currentPhrase + currentChar;
        if(!isPhraseFound(phrases, currentPhrase))
        {
            recordNewPhrase(phrases, currentPhrase, sequenceNumber);
            sequenceNumber = sequenceNumber + 1;
        }
    }
    if(!currentPhrase.empty())
    {
        recordNewPhrase(phrases, currentPhrase,sequenceNumber);
    }}




bool stillInputToProcess(char & currentChar)
{
    if(cin.get(currentChar))
    {
        return true;
    }
    return false;
}



bool isPhraseFound(phraseMapper & phrases, string phrase)
{
    return (phrases.find(phrase) != phrases.end());
}

void recordNewPhrase(phraseMapper & phrases, string & currentPhrase, int sequenceNumber)
{
    string temp = string(currentPhrase);
    char lastChar = temp.back();
    temp.pop_back();
    auto lastPhrase = phrases.find(temp);
    int oldNumber = lastPhrase->second;
    cout << oldNumber << escapeChar(lastChar) << endl;
    phrases.insert(make_pair(currentPhrase, sequenceNumber));
    currentPhrase = "";
}





string escapeChar(char ch)
{
    if(isdigit(ch) || ch == '\\')
    {
        string result = "\\";
        return result + ch;
    }
    return escapeDodgyChar(ch);
}

string escapeDodgyChar( char ch)
{
    switch (ch)
    {
        case ' ':
            return "\\s";
        case'\t':
            return "\\t";
        case '\r':
            return "\\r";
        case '\n':
            return "\\n";
        default:
            return string(1,ch);
    }
}


