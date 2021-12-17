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

auto lexer(string line)
{

    vector<token> wyn = vector<token>();

    for (int i = 0; i < line.size(); ++i)
    {
        //  check if not a space
        while (isspace(line[i]))
        {
            ++i;
            if (i >= line.size())
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

        // check if operator
        // parentheses
        for (auto j : partOps)
        {
        }
        // logical
        for (auto j : logOps)
        {
        }
        // mathematical (including bit)
        for (auto j : mathOps)
        {
        }
        // other
        for (auto j : otherOps)
        {
        }
        // name it just id
        while(! isspace(line[i])){
            
        }
    }

end:

    return 0;
}