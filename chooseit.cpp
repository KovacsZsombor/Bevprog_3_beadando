#include "chooseit.hpp"
#include "graphics.hpp"
#include <iostream>
using namespace genv;


Chooseit::Chooseit(int x, int y, int sx, int sy)
    : Widget(x,y,sx,sy){
    }


void Chooseit::menu(std::string sor){
    std::string uj;
    for (unsigned i=0;i<sor.length();i++){
        if (sor[i] != ','){
            uj += sor[i];
        }
        else {
            _szv.push_back(uj);
            uj="";
        }
    }
    _szv.push_back(uj);
    for (unsigned i=0;i*szovegmag()+szovegmag()<_size_y;++i) belefer++;
}

void Chooseit::new_menu(std::string newmenu){
    if (!newmenu.empty()) _szv.push_back(newmenu);
}

int Chooseit::szovegmag() {
    return 16;
}

double Chooseit::gmeret(){
    return (_size_y+0.0-2.0*15.0)*((belefer+0.0)/(_szv.size()+0.0));
}

double Chooseit::glepes(){
    return ((_size_y+0.0-2.0*15.0)-gmeret()+0.0)/(0.0+_szv.size()-belefer+0.0);
}

bool Chooseit::kilog(){
    return (szovegmag()*_szv.size() > _size_y-1);
}

void Chooseit::draw()
{

    gout<<color(100,100,100)<<move_to(_x-2,_y-2)<<box(_size_x+21+4,_size_y+4)
    <<color(250,250,250)<<move_to(_x,_y)<<box(_size_x,_size_y)
    <<move_to(_x+_size_x,_y)<<color(230,230,230)<<box(21,_size_y);


    gout<<move_to(_x+_size_x,_y)<<color(210,210,210)<<box(21,15)   //felbox
    <<move_to(_x+_size_x,_y+_size_y-1)<<box(21,-15)             //lebox
    <<color(20,20,20)<<move_to(_x+_size_x+1,_y+_size_y-11)<<line(10,10)<<line(10,-10)  //le nyil
    <<move_to(_x+_size_x+1,_y+10)<<line(10,-10)<<line(10,10);   //fel nyil

    if (!kilog()) gout<<move_to(_x+_size_x,_y+15)<<color(210,210,210)<<box(21,_size_y-2*15);  //gorgo
    else {
        gout<<move_to(_x+_size_x,_y+15+(girany*glepes()))<<color(180,180,180)<<box(21,gmeret()+1);
    }

    if (elemi < belefer+girany)  gout<<color(0,100,255)<<move_to(_x,_y+elemi*szovegmag()-(girany*szovegmag()))<<box(_size_x,szovegmag());
    else  gout<<color(0,100,255)<<move_to(_x,_y+(belefer-1)*szovegmag())<<box(_size_x,szovegmag());

    for (int i=0+girany;i!=_szv.size();i++){
        if (i*szovegmag()+szovegmag()-(szovegmag()*girany)<_size_y){
        if (elemi == i) gout<<color(255,255,255)<<move_to(_x,(12+_y+i*szovegmag())-(szovegmag()*girany))<<text(_szv[i]);
        else gout<<color(0,0,0)<<move_to(_x,12+_y+i*szovegmag()-(szovegmag()*girany))<<text(_szv[i]);
        }
    }
}

void Chooseit::tofile(std::string fn){
    fname=fn;
}


void Chooseit::handle(event ev)
{

    if (ev.type==ev_mouse && ev.button == btn_left){
    for (int i=0;i!=_szv.size();i++){
        if (ev.pos_x > _x && ev.pos_x < _x+_size_x){
            if (ev.pos_y > _y+(i-girany)*szovegmag() && ev.pos_y <  _y+(i-girany)*szovegmag()+szovegmag()) {
            elemi=i;
            }
        }
    }
    }
    if (ev.type == ev_mouse && ev.button == btn_left){
        if (ev.pos_x > _x+_size_x && ev.pos_x < _x+_size_x+21){
            if (elemi > 0 && ev.pos_y >_y && ev.pos_y < _y+15) {
                if (elemi <= girany) girany--;
                elemi--;
            }
        if (elemi < _szv.size()-1 && ev.pos_y > _y+_size_y-15 && ev.pos_y < _y+_size_y){

            if (elemi >= belefer-1+girany) girany++;
            elemi++;
        }
        }
    }
    if (elemi!=0){
    if (ev.keycode == key_up || ev.button==btn_wheelup) {
            if (elemi <= girany) girany--;
            elemi--;
    }}

    if (elemi < _szv.size()-1 && (ev.keycode == key_down || ev.button==btn_wheeldown)) {
            if (elemi >= belefer-1+girany) girany++;
            elemi++;
    }
    std::ofstream f(fname);
    f<<_szv[elemi];
}
