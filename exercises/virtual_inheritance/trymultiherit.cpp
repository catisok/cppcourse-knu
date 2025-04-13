#include "TextBox.hpp"
#include <iostream>

int main() {
    // create a TextBox and call draw
    TextBox tb("textbox", 4, 10);
    tb.draw();
    // Fix the code to call both draws by using types
    Rectangle &r = tb;
    r.draw();
    Text &t = tb;
    t.draw();



}
