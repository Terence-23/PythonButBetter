#include <vector>
#include <fstream>
#include <unordered_map>
#include <string>
#include "operators.hpp"

#define PB push_back

using namespace std;

struct token
{
    std::string text, id;
};

auto lexLine(string line)
{

    vector<token> wyn = vector<token>();

    for (int i = 0; i < line.size(); ++i)
    {
        // check if not a space
        while (isspace(line[i]))
        {
            ++i;
            if (i >= line.size())
                goto end;
        }
        if(line[i] == COMCHAR){
            goto end;
        }

        // check if number
        if ((line[i] - 48 < 10 && line[i] - 48 > -1) || line[i] == '.')
        {
            token pom;
            pom.id = "num";
            int begin = i;
            bool wP = !line[i] == '.';
            while ((line[i] - 48 < 10 && line[i] - 48 > -1) || (line[i] == '.' && wP))
            {
                if (line[i] == '.')
                    wP = false;
                i++;
            }
            i--;

            pom.text = line.substr(begin, i - begin);
            wyn.PB(pom);
            continue;
        }
        
        // check if text
        if(line[i] == '\'' || line[i] == '\"'){
            token pom = {id: "str"};
            ++i;
            int len, begin = i;
            while(line[i] != '\'' && line[i] != '\"'){
                i++
            }
            len = i - begin;
            pom.text = line.substr(begin, len);
            continue;
        }

        // check if operator
        
        // parentheses
        for (auto j : partBegOps)
        {
            if(j == line.substr(i, j.size())){
                token pom = {id: "beg", j};
                wyn.PB(pom);
                continue;
            }

        }

        for(auto j : partEndOps)
        {

            if(j == line.substr(i, j.size())){
                token pom = {id: "end", j};
                wyn.PB(pom);
                continue;
            }
        }

        // logical
        for (auto j : logOps)
        {
            if(j == line.substr(i, j.size())){
                token pom = {id: "op", text: j};
                i+= j.size() - 1;
                wyn.PB(pom);
                continue;
            }
        }
        // mathematical (including bit)
        for (auto j : mathOps)
        {
            if(j == line.substr(i, j.size())){
                token pom = {id: "op", text: j};
                i+= j.size() - 1;
                wyn.PB(pom);
                continue;
            }
        }
        // other
        for (auto j : otherOps)
        {
            if(j == line.substr(i, j.size())){
                token pom = {id: "op", text: j};
                i+= j.size() - 1;
                wyn.PB(pom);
                continue;
            }
        }

        // name it just id
        token pom;
        pom.id = "id";
        int begin = i;
        while(! isspace(line[i])){
            ++i;
        }
        --i;
        pom.text = line.substr(begin, i - begin);
        wyn.PB(pom);
    }

    end:
        token NL;
        NL.id = "newline";
        wyn.PB(NL);
        return wyn;
}


auto lexer(string fileTxt){
    vector<token> wyn = vector<token>();  
    for(int i = 0; i < fileTxt; ++i){
        int beg = i, len;
        while (fileTxt[i] != LINEEND && fileTxt[i-1] != '\\'){
            ++i;
        }
        
        len = i - 1 - beg;
        auto pom = lexLine(fileTxt.substr(beg, len));
        for( auto j : pom){
            wyn.PB(j);
        }
    }
    return wyn;
}

