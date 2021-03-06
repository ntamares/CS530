/*  
	Team Oregon
	Manuel Bravo, Henry Curtis, David Lane, Nestor Tamares
	SDSU - CS 530 
	Riggins
	
	file_parse_exception.h
*/    

#ifndef FILE_PARSE_EXCEPTION_H
#define FILE_PARSE_EXCEPTION_H
#include 

using namespace std;

class file_parse_exception {

public:
    file_parse_exception(string s) {
        message = s;        
        }
        
    file_parse_exception() {
        message = "An error has occurred";
        }
        
    string getMessage() {
        return message;
    }
    
private:
    string message;
}; 
