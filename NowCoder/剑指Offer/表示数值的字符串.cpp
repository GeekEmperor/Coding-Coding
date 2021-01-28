#include <regex>
class Solution {
public:
    bool isNumeric(char* s)
    {
        string pattern = "[+-]?\\d*(\\.\\d+)?([Ee][+-]?\\d+)?";
        return regex_match(s, regex(pattern));
    }
 
};