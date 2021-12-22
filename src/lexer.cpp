#include <vector>
#include <fstream>
#include <unordered_map>
#include <string>
#include "operators.hpp"
#include "dataStructs.cpp"

#define PB push_back

using namespace std;

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
        if (line[i] == COMCHAR)
        {
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

            pom.text = line.substr(begin, i - begin);
            wyn.PB(pom);
            continue;
        }

        // check if text
        if (line[i] == '\'' || line[i] == '\"')
        {
            token pom = {id : "str"};
            ++i;
            int len, begin = i;
            while (line[i] != '\'' && line[i] != '\"')
            {
                ++i;
            }
            len = i - begin;
            pom.text = line.substr(begin, len);
            wyn.PB(pom);
            i++;
            continue;
        }

        // check if separator 
        if (line[i] == SEP){
            token pom = {"sep"};
            wyn.PB(pom);
            continue;            
        }
        

        // check if operator
        bool isop = false;
        
        // keyword
        for (auto j : keywords)
        {
            if (j == line.substr(i, j.size()))
            {
                token pom = {"beg", j};
                wyn.PB(pom);
                isop = true;
                break;
            }
        }
        // parentheses
        for (auto j : partBegOps)
        {
            if (j == line.substr(i, j.size()))
            {
                token pom = {"beg", j};
                wyn.PB(pom);
                isop = true;
                break;
            }
        }

        for (auto j : partEndOps)
        {
            if (j == line.substr(i, j.size()))
            {
                token pom = {"end", j};
                wyn.PB(pom);
                isop = true;
                break;
            }
        }
        
        // mathematical (including bit)
        for (auto j : mathOps)
        {
            if (j == line.substr(i, j.size()))
            {
                token pom = {"op", j};
                i += j.size() - 1;
                wyn.PB(pom);
                isop = true;
                break;
            }
        }

        // comparsion ops
        for (auto j : compareOps)
        {
            if (j == line.substr(i, j.size()))
            {
                token pom = {"op", j};
                i += j.size() - 1;
                wyn.PB(pom);
                isop = true;
                break;
            }
        }
        
        // other
        for (auto j : otherOps)
        {
            if (j == line.substr(i, j.size()))
            {
                token pom = {"op", j};
                i += j.size() - 1;
                wyn.PB(pom);
                isop = true;
                break;
            }
        }

        if (isop)
        {
            isop = false;
            continue;
        }

        // name it just id
        token pom;
        pom.id = "id";
        int begin = i;
        while (!isspace(line[i]))
        {
            for (auto j : ops)
            {
                if (line.substr(i, j.size()) == j)
                {
                    goto endOfId;
                }
            }
            ++i;
        }
    endOfId:
        pom.text = line.substr(begin, i - begin);
        wyn.PB(pom);
        i--;
    }

end:
    token NL;
    NL.id = "newline";
    wyn.PB(NL);
    return wyn;
}

auto lexer(string fileTxt)
{
    vector<token> wyn = vector<token>();
    for (int i = 0; i < fileTxt.size(); ++i)
    {
        int beg = i;
        while (fileTxt[i] != LINEEND && fileTxt[i - 1] != '\\')
        {
            ++i;
        }

        // int len = i - beg;
        auto pom = lexLine(fileTxt.substr(beg, i - beg));
        for (auto j : pom)
        {
            wyn.PB(j);
        }
    }
    return wyn;
}
