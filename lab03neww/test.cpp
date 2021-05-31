#include "svg.h"
#include<iostream>
#include <cassert>
#include <sstream>
void check1(){
    stringstream colour (" gfg; black;black");
    string col=fillcolor(colour);
    assert(col=="black");


}
void check2(){
stringstream colour("#ffeeee");
string col=fillcolor(colour);
assert(col=="#ffeeee");
}

int
main() {

    check1();
    check2();
}
