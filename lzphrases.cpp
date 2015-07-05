
#include <string>
#include <algorithm>
#include <iostream>
#include <set>
#include <set>
using namespace std;

/**
 * file that does task 2
 * of the lz assessment
 *@author Jack Davey
 *@version 30th December 2015
 */


/**
 * function to write the input into phrases
 *@parameters the set to store the phrases in
 */
void buildPhrases(set<string> & phrases);

/**
 * check if we have already found
 * the supplied phrase
 *@param phrase the phrase to look
 * @param phrases the set of phrases to search in
 *@return  true if this phrase it in here, false if not
 */
bool isPhraseFound(set<string> & phrases, string phrase);

/**
 *@param currentChar the character that we are attempting to read into
 *@return whether we still have input left to process
 **/
bool stillInputToProcess(char & currentChar);

/**
 * function that outputs the found phrase to the console
 * and adds it to the provided set
 *@param phrases the set of phrases to add to
 @param currentPhrase the phrase to deal with
 **/
void recordNewPhrase(set<string> & phrases, string & currentPhrase);
/**
 * escapes a whole string
 *
 *@param str the string to escape
 *@return the escaped string
 **/
std::string escapeString(const string& str);


/**
 *function that escapes
 * the char parameter given
 *@parameters as above
 *@return a string containing the escaped char
 **/
std::string escapeChar(char ch);


/**
 *pretty standaard faucntion
 * to escape chers that are unseaual
 *@parameters the char we want to escape
 *@return the escaped char
 **/
string escapeDodgyChar(char ch);




int main()
{
    set<string> phrases;
    buildPhrases(phrases);
    return 0;
}

void buildPhrases(set<string> & phrases)
{
    string currentPhrase;
    char currentChar;
    currentPhrase = "";
    while (stillInputToProcess(currentChar))
    {
        currentPhrase = currentPhrase + currentChar;
        if(!isPhraseFound(phrases, currentPhrase))
        {
            recordNewPhrase(phrases, currentPhrase);
        }
    }
    if(!currentPhrase.empty())
    {
        recordNewPhrase(phrases, currentPhrase);
    }
        
}

bool stillInputToProcess(char & currentChar)
{
   if(cin.get(currentChar))
   {
       return true;
   }
    return false;
}

bool isPhraseFound(set<string> & phrases, string phrase)
{
    return (phrases.find(phrase) != phrases.end());
}

void recordNewPhrase(set<string> & phrases, string & currentPhrase)
{
    phrases.insert(currentPhrase);
    cout << escapeString(currentPhrase) << endl;
    currentPhrase = "";
}

std::string escapeString(const string& str)
{
    string result = "";
    for (auto it = str.cbegin(); it != str.cend(); it++)
    {
        result = result + escapeChar(*it);
    }
    return result;
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






