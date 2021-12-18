#include <string>


const char COMCHAR = '#';
const char LINEEND = ';';

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
