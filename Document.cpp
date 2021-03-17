
#include "Document.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void Document::showline() const {
    cout<< "line is: "<<line<<endl;
}

bool Document::inittext(const string& str) {
    ifstream in(str.c_str());
    if(!in){
        cerr << "Cannot open the File : "<<str<<endl;
        return false;
    }
    string temp;
    while(getline(in,temp)){
        if(!temp.empty()) this->vec.push_back(temp);
    }
    in.close();
    return true;

}

void Document::last_line() {
    if(!this->vec.empty()){
        this->line=vec.size();
    }
}

void Document::append_after(bool b) {
    vector<string>::iterator iterator;
    if(line>vec.size()){
        while (line>vec.size()){
            vec.insert(vec.begin()+(vec.size()),"");
        }
    }
    if(b){
        line=line-2;
    }
    while(true){
        if(b){
            iterator=vec.begin()+(++line);
        }
        else{
            iterator=vec.begin()+(line++);
        }
        string temp;
        getline(cin,temp);
        if(temp==".") break;
        vec.insert(iterator,temp);
    }
}

void Document::insert_before() {
    append_after(true);
}

void Document::change_line() {
    del();
    append_after(false);
    line--;
}

void Document::del() {
    vec.erase(vec.begin()-1+(line));
    line--;
}

void Document::join_lines() {
    if(line!=vec.size()) {
        string temp = vec[line - 1];
        temp += " " + vec[line];
        del();
        vec.insert(vec.begin() + line, temp);
        line = line + 2;
        del();
    }
}

void Document::search_after(const string& search) {
    int t;bool found=false;
    //t for temp, found for if found in text
    if(line!=1){
        t= line - 2;
    }
    else{
        t= line - 1;
    }
    //run from recent line till end
    for(int i=t; i < vec.size(); i++){  if(vec.at(i).find(search) != string::npos){

            found=true;
            line=i+1;

            break;
        }
    }
    //run for start till recent line
        for(int i=0; i < t&&!found; i++){   if(vec.at(i).find(search) != string::npos){
                line=i+1;

                break;
            }
        }

}


void Document::swap_first(const string& old, const string& newString) {
        if(vec.at(line-1).find(old)!=-1){
            vec.at(line-1).replace(vec.at(line-1).find(old),old.size(),newString);
        }
}


void Document::write_to_file(const string& name) {
    ofstream File(name);
    for (int i = 0; i <vec.size() ; ++i) {
        if((i==0&&vec[i].empty())||(i==vec.size() && vec[i].empty())){}
        else{
            File << vec[i] << "\n";

        }
    }
    File.close();
}
