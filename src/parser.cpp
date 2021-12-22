#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <stdexcept>

#define index unsigned long long
#define PB push_back

#include "lexer.cpp"

using namespace std;

// opPriority
/*
    |
    &
    ==
    =       
    +       
    -     
    *     
    /   
    <<
    >>
    %
    ^
*/



TokenNode blockF(vector<token> toParse, index beg, index end, TokenNode &parent){

    for (auto op : opsP){
        for (int i = beg; i < end; ++i){
            if(toParse[i].id == "op" && toParse[i].text == op){
                parent.id = "op";
                parent.text = op;
                TokenNode left, right;
                left.sub.PB(parent);
                right.sub.PB(parent);
                parent.sub.PB(blockF(toParse, beg, i, left));
                parent.sub.PB(blockF(toParse, i+1, end, right));
                goto end;
            }
        }

    }
    end:
    cout << parent.id << ' ' << parent.text<< "\n";
    return parent;
}



auto parse(vector<token> toParse)
{
    TokenNode program, None = {"", "out of program"};
    program.sub.PB(None);
    TokenNode* pCurrent = &program;
    TokenNode* block;
    int regPartLvl= 0, kPartLvl = 0;

    // parse through the vector and change it to the tree
    for (unsigned long long i = 0; i < toParse.size(); ++i)
    {
        
        auto current = *pCurrent;
        /*
            block - space inside parentheses 
                in one line without separator inside

        */
        if (toParse[i].id == "keyword"){
            if (toParse[i].text == "def"){
                ++i;
                if (toParse[i].id != "id"){
                    throw std::invalid_argument("Function identifier not found");
                }
                TokenNode func;
                
                func.id = "func";
                func.text = toParse[i].text;
                func.sub.PB(current);
                ++i;
                if(toParse[i].text != "("){
                    throw std::invalid_argument("Didn't found list od arguments for function: " + func.text);
                }
                goto block;
                


            }else if (toParse[i].text == "class"){

            }else if (toParse[i].text == "var" || toParse[i].text == "const"){
                goto block;
            }
        }else if(toParse[i].id == "id"){
            goto block;
        }       



        continue;
        // blocking
        block:
            ++i;
            index beg = i, end;
            
            if (toParse[i].text == "(") {
                TokenNode blockS;
                blockS.id = toParse[i].id;
                blockS.text = toParse[i].text;
                blockS.sub.PB(current);
                goto lvlDown;
            }
            
            if (toParse[i].text == ")"){
                end = i;
                TokenNode parent;
                parent.sub.PB(current);
                current.sub.PB(blockF(toParse, beg, end, parent));
                goto lvlUp;
            }
            
            if (toParse[i].id == "newline"){
                end = i;
                TokenNode parent;
                parent.sub.PB(current);
                current.sub.PB(blockF(toParse, beg, end, parent));
            }
            
            if (toParse[i].id == "sep"){
                end = i;
                TokenNode parent;
                parent.sub.PB(current);
                current.sub.PB(blockF(toParse, beg, end, parent));
                goto block;
            }
            
            ++i;
        
        continue;

        // lvlUp
        // less deep
        lvlUp:
            if (current.sub[0].id == ""){
                cout << "No open parentheses to be closed";
                throw -1;
            }
            pCurrent = &(current.sub[0]);
            regPartLvl -=1;
            continue;
        // lvlDown
        // deeper
        lvlDown:
            regPartLvl +=1;
            pCurrent = &(current.sub[current.sub.size()-1]);
            continue;
    }
    if(regPartLvl ||  kPartLvl){
        cout << "Not all parnetheses had been closed";
        throw -1;
    }

    return program;
}