#include "Counter.hpp"
#include "graphics.hpp"
#include <iostream>

using namespace genv;

counter::counter(int x, int y, int sx, int sy)
    : Widget(x,y,sx,sy){}

std::string sswap(int a, int c){
    std::stringstream ss;
    a+=c;
    std::string b;
    ss<<a;
    ss>>b;
    return b;
}

int szamvizsgal(char szov){
    std::stringstream ss;
    int szam;
    ss<<szov;
    ss>>szam;
    return szam;
}

void counter::tofile(std::string fn){
    fname=fn;
}

void counter::tartomany(int minszam, int maxszam){
    if (minszam!=0 && maxszam!=0){
        cmin=minszam;
        cmax=maxszam;
    }
}

void counter::draw()
{
    gout<<move_to(_x-2,_y-2)<<color(100,100,100)<<box(_size_x+21+4,_size_y+4)
    << move_to(_x, _y) << color(255,250,255) << box(_size_x, _size_y)
    <<color(60,60,60)
    <<move_to(_x+_size_x,_y+_size_y-1)<<box(21,-(_size_y/2)) ///lghatter
    <<color(210,210,210)<<move_to(_x+_size_x+1,_y+_size_y-2)<<box(19,-(_size_y/2)+2) ///legomb
    <<color(60,60,60)<<move_to(_x+_size_x,_y)<<box(21,(_size_y/2)) ///fghatter
    <<color(210,210,210)<<move_to(_x+_size_x+1,_y+1)<<box(19,(_size_y/2)-2) ///felgomb
    <<color(0,0,0)<<move_to(_x+_size_x+1,_y+_size_y/2+_size_y/8)<<line(10,10)<<line(10,-10)  ///le
    <<color(0,0,0)<<move_to(_x+_size_x+1,_y+_size_y/2-_size_y/8)<<line(10,-10)<<line(10,10); ///fel
        gout << color(0,0,0)<<move_to(_x+5,_y+_size_y/2+5)<<text(_num);
}

void counter::handle(event ev)
{
    if (cmin==0 && cmax==0){
        cmin=-200000000;
        cmax=200000000;
    }
    if ((ev.type == ev_key && ev.keycode != key_backspace && ev.keycode >= 48 && ev.keycode<= 57 &&
         gout.twidth(_num)<_size_x-10) || ev.keycode == 45 ) {
            char sz;
            sz=szamvizsgal((char)ev.keycode);
            if (szam*10+9 <= cmax && szam*10-9 >= cmin) _num+=(char)ev.keycode;
            else if (szam*10+(sz%10) <= cmax && szam*10-(sz%10) >= cmin) _num+=(char)ev.keycode;
    }

    if (szam < cmax && (ev.keycode == key_up || ev.button == btn_wheelup)) _num=sswap(szam,1);
    else if (ev.keycode== key_pgup && szam+9<cmax) _num=sswap(szam,10);

    if (szam-9 > cmin && ev.keycode == key_pgdn) _num=sswap(szam,-10);
    else if (szam > cmin && (ev.keycode == key_down || ev.button == btn_wheeldown)) _num=sswap(szam,-1);

    if (ev.type == ev_mouse && ev.button == btn_left){
    if (ev.pos_x > (_x+_size_x) && ev.pos_x < _x+_size_x+21){
        if (szam > cmin && ev.pos_y <= _y+_size_y && ev.pos_y >= (_y+_size_y/2+2)){
            _num=sswap(szam,-1);
        }
        else if (szam < cmax && ev.pos_y < _y+_size_y/2 && ev.pos_y > _y){
            _num=sswap(szam,1);
        }
    }
    }

    if (ev.keycode == key_backspace || gout.twidth(_num)>_size_x-10){
        if (!_num.empty()){
            _num.erase(std::prev(_num.end()));
        }
    }
    std::stringstream ss;
    ss<<_num;
    ss>>szam;

    std::ofstream f(fname);
    f<<szam;
}


