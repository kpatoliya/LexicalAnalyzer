/***Karan Patoliya***/



#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include "lex.h"
using namespace std;

int main(int argc, char *argv[]){
     
    int linenum = 0;
	istream* in = &cin;

    bool vFlag = false;
    bool constsFlag = false;
    bool idsFlag = false;
    
    vector<string> identifiers;
    bool temp = true;
    
    int tokCount = 0;

	string line;
	ifstream myfile("command.txt");
	if (myfile.is_open())
	{
	while (getline(myfile, line)){
        if(line == "-v")            
            vFlag = true;
        else if(line == "-consts")
            constsFlag = true;
        else if(line == "-ids")
            idsFlag = true;
        else if(line[0] == '-'){
            cerr << "UNRECOGNIZED FLAG " << arg << endl;
            return 0;
        }		
        else{ 
            file.open(line);
            if( !file.is_open() ) {
                cerr << "CANNOT OPEN " << arg << endl;
                return 0;
            }
            in = &file;    
        }
		myfile.close();
    }
    
    while( (tok=getNextToken(*in, linenum)) != DONE && tok != ERR ) {
    
        if( vFlag )
            cout << tok << endl;
        ++tokCount;
        if( idsFlag ){   
            if(tok == ID)
                identifiers.push_back(tok.GetLexeme());            
        }        
        if( constsFlag ){}
                
    }
    
    if( tok == ERR ) {
        cout << "Error on line " << linenum << " (" << tok.GetLexeme() << ")" << endl;
        return 0;
    }
    
    if(idsFlag)
    {
        sort(identifiers.begin(), identifiers.end());
        temp = true;
        for(vector<string>::iterator iit = identifiers.begin(); iit != identifiers.end(); ++iit)
        {
            if(temp)
            {
                cout << "IDENTIFIERS: " << *iit;
                temp = false;
            }
            else
            {
                cout << ", ";
                cout << *iit;
            }
        }
        if(!identifiers.empty())
            cout << endl;
    }
    
    if(linenum == 0){
        cout << "Lines: " << linenum << endl;
    }
    else{
        cout << "Lines: " << linenum << endl;
        cout << "Tokens: " << tokCount << endl;
    }
    
    return 0;
}
    