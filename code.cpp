/***Karankumar Patoliya***/
/***CS 280 Fall19***/


#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include "lex.h"
using namespace std;

int main(int argc, char *argv[]){
    
    istream *in = &cin;
    ifstream file;
    
    cout<< "Enter the string: ";
    

    int linenum = 0;
    
    bool vFlag = false;
    bool constsFlag = false;
    bool idsFlag = false;
    
    vector<string> identifiers;
    bool temp = true;
    
    int tokCount = 0;
    
    for(int i=1; i<argc; i++){
        string arg(argv[i]);
        if(arg == "-v")            
            vFlag = true;
        else if(arg == "-consts")
            constsFlag = true;
        else if(arg == "-ids")
            idsFlag = true;
        else if(arg[0] == '-'){
            cerr << "UNRECOGNIZED FLAG " << arg << endl;
            return 0;
        }
        else if(in != &cin){
            cerr << "ONLY ONE FILE NAME ALLOWED" << endl;
            return 0;
        }
        else{ 
            file.open(arg);
            if( !file.is_open() ) {
                cerr << "CANNOT OPEN " << arg << endl;
                return 0;
            }
            in = &file;    
        }
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
    