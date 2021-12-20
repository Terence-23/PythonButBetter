#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

#define index unsigned long long
#define PB push_back

#include "lexer.cpp"

using namespace std;

// opPriority
/*
    =       
    +       
    -   ||  
    *   &&  
    /   ==
    <<
    >>
    %
*/

auto block(){
    
}



auto parse(vector<token> toParse)
{
    TokenNode program, None = {"", "out of program"};
    program.sub.PB(None);
    TokenNode* pCurrent = &program;
    TokenNode* block;
    int partLvl = 0;

    // parse through the vector and change it to the tree
    for (unsigned long long i = 0; i < toParse.size(); ++i)
    {
        
        auto current = *pCurrent;
        /*
            block - space inside parentheses 
                in one line without separator inside

        */



        // blocking
        block:
            ++i;
            index beg = i, end;
            


        // lvlUp
        lvlUp:
            if (current.sub[0].id == ""){
                cout << "No open parentheses to be closed";
                throw -1;
            }
            pCurrent = &(current.sub[0]);
            partLvl -=1;
            continue;
        // lvlDown
        lvlDown:
            pCurrent = &(current.sub[current.sub.size()-1]);
            continue;
    }
    if( partLvl){
        cout << "Not all parnetheses had been closed";
        throw -1;
    }

    return program;
}