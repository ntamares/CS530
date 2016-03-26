/*
    Team Oregon
	Manuel Bravo, Henry Curtis, David Lane, Nestor Tamares
	SDSU - CS 530 
	Riggins
	
	file_parser.cc
*/

#include <string>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

#include "file_parser.h"
#include "file_parse_exception.h"

//public methods
file_parser::file_parser(string s) {
        contents.reserve(200);
        filename = s;
}

file_parser::~file_parser() {

}

void file_parser::read_file() {
        ifstream infile;
        ofstream outfile;
        string line;
        int line_num = 0;
        char delimiters[] = " \t";
        tokens line_token;

        infile.open(filename.c_str(), ios::in);

        if(!infile) {
            file_parse_exception("File not found");
	    exit(1);
        }

        while(getline(infile,line)) {
                getline(infile,line);

                if(line.length() >99) {
                        stringstream error;
                        error << "Line " << line_num << " is too long";
                        file_parse_exception(error.str());
				exit(1);
                }

		if(isalpha(line[0]) && line != ?\n?) {
                        stringstream error;
			error << "Line " << line_num << " has whitespace as the first character";
                        file_parse_exception(error.str());
			exit(1);
                }
                if(isdigit(line[0]) && line != ?\n?) {
                        stringstream error;
			error << "Line " << line_num << " has whitespace as the first character";
                        file_parse_exception(error.str());
			exit(1);
                }
		
		int last = line.find_first_not_of(delimiters,0);
                int first = line.find_first_of(delimiters,last);
                string token = "";
                token = line.substr(last,first-last);

                while(first != -1 || last != -1) {
                        if(token.find(?.?,last)) {
					line_token.comment = token;
				}
			token = line.substr(last,first-last);
			last = line.find_first_not_of(delimiters,first);
                        first = line.find_first_of(delimiters,last);
				
                        cout << token << ? ?;
                }
                contents.push_back(line_token);
                line_num++;
        }
        infile.close();
}

string file_parser::get_token(unsigned int, unsigned int) {
        return ?Nothing here yet?;
}


void file_parser::print_file() {
	for(int i=0; i<contents.size();i++) {
		cout << setw(12) << contents[i].line_token.label << contents[i].line_token.opcode << contents[i].line_token.operands << contents[i].line_token.comment << endl;
	}
        
}

int file_parser::size() {
        return contents.size();
}

void file_parser::print_file() {
	for(int i=0; i<contents.size();i++) {
		cout << setw(12) << contents[i].line_token.label << contents[i].line_token.opcode << contents[i].line_token.operands << contents[i].line_token.comment << endl;
	}        
}


int file_parser::size() {
        return contents.size();
}
