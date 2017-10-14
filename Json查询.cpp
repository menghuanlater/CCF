#include <iostream>
#include <cstring>
#include <string>
#define SEARCH_OBJECT "OBJECT"
#define SEARCH_NO_EXIST "NOTEXIST"
#define LINE_CHAR_MAX 88
#define LINE_MAX 100

using namespace std;

union Value{
    string value;
    void * ptr;
}

typedef struct Node{
    string key;
    bool valueIsObject;
    Value value;
    Node * next;
}*Nodeptr;

int JsonLine,SearNum; 
Nodeptr head; //List head

//functions ---------------------------------

//functions ---------------------------------

int main(void){
    cin>>JsonLine>>SearNum;
    //I think first we should get all the strings and memorize in two array;
    char JsonInitStr[LINE_CHAR_MAX*LINE_MAX] = {'\0'};
    char JsonQueryStr[LINE_CHAR_MAX*LINE_MAX] = {'\0'};



    return 0;
}