

#include <iostream>
#include <utility>
#include "Editor.h"
using namespace std;
void Editor::loop() {
    //this regex is for write into a file
    regex w(R"(w \w+\.\w+)");
    //this regex is to swap text for another text
    regex swap(R"(s/\w+\s*/\w*/?)");
    //this regex is for searching text inside our file
    regex search(R"(/\w+/)");
    string x;
    while(/*cin>> x*/getline(cin,x)){
        if(x=="q"){
            break;
        }
        else if(x=="$"){
            this->doc.last_line();
        }
        else if(x=="a"){
            this->doc.append_after(false);
        }
        else if(x=="i"){
            this->doc.insert_before();
        }
        else if(x=="c"){
            this->doc.change_line();
        }
        else if(x=="d"){
            this->doc.del();
        }
        else if(x=="j"){
            this->doc.join_lines();
        }
        else if(x=="s"){
            this->doc.showline();
        }
        else if(regex_match(x,swap)){
            string main;int f1,f2;string str1,str2;
            main= x.substr(2);
            f1 = main.find('/');
            f2 = main.rfind('/');
            str1= main.substr(0,f1);
            if(f2 != f1){
                str2=main.substr((f1+1),f2-f1-1);
            }
            else{
                str2=main.substr(f1+1);
            }
            this->doc.swap_first(str1,str2);
        }
        else if(regex_match(x,search)){
            this->doc.search_after(x.substr(1,x.size()-2));
        }
        else if(regex_match(x,w)) {
            this->doc.write_to_file(x.substr(2));
        }

        try{
            int sign=0; //0 for no sign, 1 for - sign, 2 for + sign.
            if(x.at(0)=='+'){
                sign=2;
            }
            else if(x.at(0)=='-'){
                sign=1;
            }
            if(sign==1||sign==2){
                x=x.substr(1);
            }
            int num=stoi(x);
            if(to_string(num).length()==x.length()&&num>0) {
                switch(sign){
                    case 0:
                        doc.line=num;
                        doc.showline();
                        break;
                    case 1:
                        doc.line-=num;
                        doc.showline();
                        break;
                    case 2:
                        doc.line+=num;
                        doc.showline();
                        break;
                }
            }
        }
        catch(exception &e){}
    }
}

Editor::Editor(std::string str) {
    this->doc.inittext(str);
}

Editor::Editor() {}
