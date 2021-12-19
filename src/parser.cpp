#include<string>
#include<vector>
#include<unordered_map>
#include<iostream>

#define push_back PB

#include "operators.hpp"
#include "dataStructs.cpp"

using namespace std;

vector<TokenNode> inTypes(vector<token> in){
    for (int i = 0; i < in.size(); ++i){
        if(in[i].id == "id"){

        }
    }
}

auto parse(vector<token> toParse){

    vector<ATS> parsed = vector<ATS>();

    //def ATS for every  function
    for (int it = 0; it < toParse.size(); it++){
        token i = toParse[it];
        if(i.id == "id" && i.text == "def"){
            if(toParse[it+1].id != "id"){
                cout << "Invalid function declaration\n";
                throw -1;
            }
            it +=2;
            TokenNode mainNode;
            mainNode.dType = "func";
            mainNode.text = toParse[it].text;
            mainNode.id = "func";
            if (toParse[it].id != "beg" && toParse[it].text != "("){

            }

            auto input = inTypes();
        }
    }




    return parsed;
}