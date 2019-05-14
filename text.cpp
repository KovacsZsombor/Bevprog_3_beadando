#include "text.hpp"
#include "graphics.hpp"
#include <iostream>

using namespace genv;

Text::Text(int x, int y, int sx, int sy)
    : Widget(x,y,sx,sy){}

void Text::tofile(std::string fn){
    fname=fn;
}

void Text::draw()
{
    gout<<move_to(_x-2,_y-2)<<color(100,100,100)<<box(_size_x+21+4,_size_y+4)
    << move_to(_x, _y) << color(255,250,255) << box(_size_x+21, _size_y)
    <<color(60,60,60)<< color(0,0,0)<<move_to(_x+5,_y+_size_y/2+5)<<text(_num);
}

void Text::handle(event ev)
{
    if ((ev.type == ev_key && ev.keycode != key_backspace &&
         ev.keycode > 0 && ev.keycode < 300)) {
            _num+=(char)ev.keycode;
            std::cout<<ev.keycode<<"\n";
    }
    if (ev.keycode == key_backspace || gout.twidth(_num)>_size_x+12){
        if (!_num.empty()){
            _num.erase(std::prev(_num.end()));
        }
    }

    std::ofstream f(fname);
    f<<_num;
}


