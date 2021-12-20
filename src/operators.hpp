#include <string>


const char COMCHAR = '#';
const char LINEEND = ';';
const char SEP = ',';

const int MON = 24;
const std::string mathOps[MON] = {
    // Increment / Decrement
    "++", "--",

    // simple maths
    "+", "-", "*", "/", "%",

    // Bit operations
    "<<", ">>", "!", "^", "&", "|",

    // with equal
    // simple maths
    "+=", "-=", "*=", "/=", "%=",

    // Bit operations
    "<<=", ">>=", "!=", "^=", "&=", "|="
};

const int LON = 4;
const std::string logOps[LON] = {
    "!", "||", "&&", "^"
};

const int PON  = 3;
const std::string partBegOps[PON] = {
    "(", "[", "{"
};
const std::string partEndOps[PON] = {
    ")", "]", "}"
};

const int OON = 1;
const std::string otherOps[OON] = {
    ":"
};

const int ON = MON + LON + PON + OON;
const std::string ops[ON] = {
    // logic
    "!", "||", "&&", "^",

    // increment / decrement
    "++", "--",

    // simple maths
    "+", "-", "*", "/", "%",

    // Bit operations
    "<<", ">>", "!", "^", "&", "|",

    // with equal
    // simple maths
    "+=", "-=", "*=", "/=", "%=",

    // Bit operations
    "<<=", ">>=", "!=", "^=", "&=", "|=",

    // parentheses
    "(", "[", "{",

    // other
    ":"

};

const int BTC = 6;
std::string buildInTypes[BTC] = {
    "bool",
    "float",
    "int",
    "list",
    "map",
    "string",
};

const int KWC = 9;
const std::string keywords[KWC] = {
    // defining
    "def", "class", "var", "const",

    // error handling
    "try", "except", "finally",

    // returning data
    "return", "raise" 
};