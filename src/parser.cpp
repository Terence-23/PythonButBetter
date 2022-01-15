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

TokenNode* blockF(vector<token> toParse, index beg, index end, TokenNode &parent)
{
    if (beg - end == -2 && toParse[beg].id == "keyword"){
        TokenNode keyword = {toParse[beg].id, toParse[beg].text};
        TokenNode id = {toParse[beg+1].id, toParse[beg+1].text};
        id.parent = &keyword;
        keyword.parent = &parent;
        keyword.sub.PB(&id);
        parent.sub.PB(&keyword);
    }

    if (beg - end == -1)
    {
        TokenNode lt = {toParse[beg].id, toParse[beg].text};
        lt.sub.PB(&parent);
        parent.sub.PB(&lt);

        goto end;
    }
    for (auto op : opsP)
    {
        for (int i = beg; i < end; ++i)
        {
            if (toParse[i].id == "op" && toParse[i].text == op)
            {
                parent.id = "op";
                parent.text = op;
                TokenNode left, right;
                left.parent = &parent;
                right.parent = &parent;
                parent.sub.PB(blockF(toParse, beg, i, left));
                parent.sub.PB(blockF(toParse, i + 1, end, right));
                goto end;
            }
        }
    }
end:
    cout << parent.id << ' ' << parent.text << "\n";
    return &parent;
}

void blockF1(vector<token> toParse, index &i, TokenNode &parent, token ePart)
{
    ++i;
    if (toParse[i] == ePart)
    {
        return;
    }
    index beg = i, end;
    while (i < toParse.size())
    {

        // zagnieżdzone bloki
        if (toParse[i].text == "(")
        {
            TokenNode blockS;
            blockS.id = toParse[i].id;
            blockS.text = toParse[i].text;
            blockS.parent = &parent;
            parent.sub.PB(&blockS);
            token pePart = {"end", ")"};
            blockF1(toParse, i, blockS, pePart);
        }

        if (toParse[i].text == "[")
        {
            TokenNode blockS;
            blockS.id = toParse[i].id;
            blockS.text = toParse[i].text;
            blockS.parent = &parent;
            parent.sub.PB(&blockS);
            token pePart = {"end", "]"};
            blockF1(toParse, i, blockS, pePart);
        }

        if (toParse[i].text == "{")
        {
            TokenNode blockS;
            blockS.id = toParse[i].id;
            blockS.text = toParse[i].text;
            blockS.parent = &parent;
            parent.sub.PB(&blockS);
            token pePart = {"end", "}"};
            blockF1(toParse, i, blockS, pePart);
        }

        //  w bloku
        if (toParse[i].id == "newline")
        {
            end = i;
            TokenNode parent1;
            parent1.parent = &parent;
            parent.sub.PB(blockF(toParse, beg, end, parent1));
            beg = i + 1;
        }

        if (toParse[i].id == "sep")
        {
            end = i;
            TokenNode parent1;
            parent1.parent = &parent;
            parent.sub.PB(blockF(toParse, beg, end, parent1));
            beg = i + 1;
        }

        ++i;
        if (toParse[i] == ePart){
            parent.sub.PB(blockF(toParse, beg, end, parent));
            return;
        }
    }
}

auto parse(vector<token> toParse)
{
    TokenNode program, None = {"", "out of program"};
    program.parent = (&None);
    TokenNode *pCurrent = &program;
    TokenNode *block;
    int regPartLvl = 0, kPartLvl = 0;
    bool inFunc = false, inLoop = false;

    // parse through the vector and change it to the tree
    for (unsigned long long i = 0; i < toParse.size(); ++i)
    {

        auto current = *pCurrent;
        /*
            block - space inside parentheses 
                in one line without separator inside

        */
        if (toParse[i].id == "keyword")
        {
            if (toParse[i].text == "def")
            {
                ++i;
                if (toParse[i].id != "id")
                {
                    throw std::invalid_argument("Function identifier not found");
                }
                TokenNode func;

                func.id = "func";
                func.text = toParse[i].text;
                func.parent = &current;
                ++i;

                if (toParse[i].text != "(")
                {
                    throw std::invalid_argument("Didn't found list of arguments for function: " + func.text);
                }

                token ePart = {"end", ")"};
                blockF1(toParse, i, func, ePart);
                cout << i;
                ++i;
                if (toParse[i].text != "{")
                {
                    throw std::invalid_argument("Function definition not found.");
                }
                ePart.text = "}";
                blockF1(toParse, i, func, ePart);

                program.sub.PB(&func);
            }
            else if (toParse[i].text == "class")
            {
            }
            else if (toParse[i].text == "var" || toParse[i].text == "const")
            {
                blockF1(toParse, i, current, NL);
            }
        }

        continue;

    // lvlUp
    // less deep
    lvlUp:
        TokenNode * cp = current.parent;
        \
        if ( (*cp).id == "")
        {
            cout << "No open parentheses to be closed";
            throw -1;
        }
        
        pCurrent = current.parent;
        regPartLvl -= 1;
        continue;
    // lvlDown
    // deeper
    lvlDown:
        regPartLvl += 1;
        pCurrent = (current.sub[current.sub.size() - 1]);
        continue;
    }
    if (regPartLvl || kPartLvl)
    {
        cout << "Not all parnetheses had been closed";
        throw -1;
    }

    return program;
}