#include<vector>
#include<string>

using namespace std;

struct TokenNode{
    string id, text;
    // sub[0] == parent
    vector<TokenNode> sub;

};

class ATS
{
    TokenNode first;
public:
    ATS(TokenNode first){
        this->first = first;
    }
    ATS(){
        
    }
    TokenNode getBegin(){
        return first;
    }

};


struct token
{
    std::string id, text;
};
