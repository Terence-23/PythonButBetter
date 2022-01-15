#include <string>

const char COMCHAR = '#';
const char LINEEND = ';';
const char SEP = ',';

const int MON = 25;
const std::string mathOps[MON] = {
    // equal
    "=",
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
    "<<=", ">>=", "!=", "^=", "&=", "|="};

const int CON = 6;
const std::string compareOps[6]{
    ">", "<", "==", "!=", "<=", ">="};

const int PON = 3;
const std::string partBegOps[PON] = {
    "(", "[", "{"};
const std::string partEndOps[PON] = {
    ")", "]", "}"};

const int OON = 1;
const std::string otherOps[OON] = {
    ":"};

const int ON = MON + CON + PON + OON;
const std::string ops[ON] = {
    //
    "=",
    // comparsion
    ">", "<", "==", "!=", "<=", ">=",

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

const int KWC = 11;
const std::string keywords[KWC] = {
    // defining
    "def", "class", "var", "const",

    // error handling
    "try", "except", "finally",

    // returning data
    "return", "raise",

    // conditions and loops
    "if", "for"};

const int ONP = MON + CON + PON + OON - 1;
const std::string opsP[ONP] = {

    // with equal

    "=",
    // other
    ":",
    // simple maths
    "+=",
    "-=",
    "*=",
    "/=",
    "%=",

    // Bit operations
    "<<=",
    ">>=",
    "!=",
    "^=",
    "&=",
    "|=",
    // comparsion
    ">",
    "<",
    "==",
    "!=",
    "<=",
    ">=",
    "^",
    "&",
    "|",
    // increment / decrement
    "++",
    "--",

    // simple maths
    "+",
    "-",
    "*",
    "/",
    "%",

    // Bit operations
    "<<",
    ">>",

};
