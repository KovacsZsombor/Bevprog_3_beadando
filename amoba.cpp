#include "amoba.hpp"
#include <iostream>

using namespace genv;

amoba::amoba(int x,int y, int sx, int sy) : Widget (x,y,sx,sy){
    std::vector<bool> bv;
    for (int n=0;n<20;n++){ //sor
        for (int k=0;k<20;k++){ //oszlop
            bv.push_back(false);
        }
        bm.push_back(bv);
    }

}

void amoba::draw(){
    for (int i=0;i<20;i++){
        for (int j=0;j<20;j++){
            if (bm[j][i]==true){
            gout<<color(255,255,255)<<move_to(_x+(i*meret), _y+(j*meret))<<box(meret,meret)
            <<color(10,150,10)<<move_to((i*meret)+_x+1, (j*20)+_y+1)<<box(18,18);
            }else {
            gout<<color(255,255,255)<<move_to(_x+(i*meret), _y+(j*meret))<<box(meret,meret)
            <<color(150,150,150)<<move_to((i*meret)+_x+1, (j*20)+_y+1)<<box(18,18);
            }
        }
    }
}

void amoba::handle(event ev){
    if (ev.type==ev_key) bm[8][2]=true;

}
