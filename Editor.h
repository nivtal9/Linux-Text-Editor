
#include "Document.h"
#include <regex>
#ifndef EDITOR_EDITOR_H
#define EDITOR_EDITOR_H
using namespace std;
class Editor{
    Document doc;
public:
    void loop();

    Editor(string str);

    Editor();
};
#endif //EDITOR_EDITOR_H
