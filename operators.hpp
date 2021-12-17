#include <string>

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
const std::string partOps[PON] = {
    "(", "[", "{"
};

const int OON = 1;
const std::string otherOps[OON] = {
    "in"
};
