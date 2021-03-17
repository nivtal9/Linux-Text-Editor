
#include "Editor.h"
#include <string>
using namespace std;
int main(int argc, char* argv[]) {
    switch(argc){
        case 1: {
            Editor ed;
            ed.loop();
            break;
        }
        case 2: {
            string filename=argv[1];
            Editor ed(filename);
            ed.loop();
            break;
        }
    }
    return 0;
}
