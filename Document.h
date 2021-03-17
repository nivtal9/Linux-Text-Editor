
#ifndef EDITOR_DOCUMENT_H
#define EDITOR_DOCUMENT_H

#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Document{
vector<string> vec;
public:
    int line=1;
    void showline() const;
    bool inittext(const string& str);

    void last_line();

    void append_after(bool b);

    void insert_before();

    void change_line();

    void del();

    void join_lines();

    void search_after(const string& search);

    void swap_first(const string& old, const string& newString);

    void write_to_file(const string& name);
};
#endif //EDITOR_DOCUMENT_H
