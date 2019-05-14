#include "gomb.hpp"

using namespace genv;

gomb::gomb (int x, int y, int sx, int sy) : Widget (x, y, sx, sy) {}

void gomb::draw(){

    if (push) {
    gout<<move_to(_x-2,_y-2)<<color(155,155,155)<<box(_size_x+4, _size_y+4)
    <<color(55,155,245)<<move_to(_x, _y)<<box(_size_x,_size_y)
    <<color(255,255,255)<<move_to(_x+20, _y+20)<<text(gombnev);
    }
    else {
    gout<<move_to(_x-2,_y-2)<<color(100,100,100)<<box(_size_x+4, _size_y+4)
    <<color(200,100,10)<<move_to(_x, _y)<<box(_size_x,_size_y)
    <<color(0,0,0)<<move_to(_x+20, _y+20)<<text(gombnev);
    }
}

void gomb::szoveg(std::string sz){
    gombnev=sz;
}

bool gomb::nyomva() {return push;}

void gomb::handle(event ev){
    if (ev.type == ev_mouse && ev.button == btn_left){
    if (ev.pos_x > _x && ev.pos_x < _x+_size_x && ev.pos_y > _y && ev.pos_y < _y+_size_y){
        push=true;
    }
    }
    else push = false;
}
