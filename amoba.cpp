#include "amoba.hpp"
#include <iostream>

using namespace genv;

std::string to_str(const double x, const int tizedes) {
    std::stringstream ss;
    ss << std::fixed;
    ss.precision(tizedes); // set # places after decimal
    ss << x;
    return ss.str();
}


amoba::amoba(int x,int y, int sx, int sy) : Widget (x,y,sx,sy)
{
    std::vector<negyzet> bv;
    negyzet nzt;
    sxmeret=sx;
    for (int n=0; n<palyasize; n++)
    {
        for (int k=0; k<palyasize; k++)
        {
            nzt.meret=sx/palyasize;
            nzt.x=_x+(k*nzt.meret);
            nzt.y=_y+(n*nzt.meret);
            nzt.nyomva=false;
            nzt.O=false;
            nzt.X=false;
            nzt.foglalt=false;
            bv.push_back(nzt);
        }
        bm.push_back(bv);
        bv.clear();
    }
}

void amoba::draw()
{
    int mrt=bm[0][0].meret, r,kx,ky;
    double pi = 3.14159;
    gout<<color(0,0,0)<<move_to(_x,_size_y)<<box(_size_x,12);
    for (int i=0; i<palyasize; i++)
    {
        for (int j=0; j<palyasize; j++)
        {

            if (!bm[i][j].foglalt){
            if (bm[i][j].X)
            {
                gout<<color(100,250,250)<<move_to(bm[i][j].x+2, bm[i][j].y+2)<<line(mrt-4,mrt-4)
                    <<move_to(bm[i][j].x+2, bm[i][j].y+mrt-2)<<line(mrt-4,-mrt+4);
                    bm[i][j].foglalt=true;
            }
            else if (bm[i][j].O)
            {
                gout<<color(100,255,100);
                r=mrt/2-2;
                kx=bm[i][j].x+(mrt/2)-1;
                ky=bm[i][j].y+(mrt/2)-1;

                for (double i = 0; i < 360 ; i+=0.1)
                {
                    double alpha = i/180*pi;
                    int yy = r*sin(alpha);
                    int xx = r*cos(alpha);
                    gout << move_to(xx+kx,yy+ky) << dot <<move_to(kx,ky);
                }
                bm[i][j].foglalt=true;
            }
            else
            {
                gout<<color(200,200,200)<<move_to(bm[i][j].x, bm[i][j].y)<<box(mrt,mrt)
                    <<color(10,10,10)<<move_to(bm[i][j].x+1, bm[i][j].y+1)<<box(mrt-2,mrt-2);
            }
            }
            if (ellenoriznk().i!=-1 && ellenoriznk().j!=-1) {

                    if (ij.sor && ij.oszlop && ij.foatlo){
                    gout<<color(255,0,0)<<move_to(bm[ij.i][ij.j].x, bm[ij.i][ij.j].y)
                    <<line_to(bm[ij.i+4][ij.j+4].x+mrt,bm[ij.i+4][ij.j+4].y+mrt)
                    <<move_to(bm[ij.i][ij.j].x, bm[ij.i][ij.j].y+1)
                    <<line_to(bm[ij.i+4][ij.j+4].x+mrt-1,bm[ij.i+4][ij.j+4].y+mrt);
                    gameover=true;
                    }
                    else if (ij.sor && ij.oszlop && ij.mellekatlo){
                    gout<<color(255,0,0)<<move_to(bm[ij.i][ij.j].x+mrt, bm[ij.i][ij.j].y)
                    <<line_to(bm[ij.i+4][ij.j-4].x,bm[ij.i+4][ij.j-4].y+mrt)
                    <<move_to(bm[ij.i][ij.j].x+mrt, bm[ij.i][ij.j].y+1)
                    <<line_to(bm[ij.i+4][ij.j-4].x+1,bm[ij.i+4][ij.j-4].y+mrt);
                    gameover=true;
                    }
                    else if (ij.sor){
                    gout<<color(255,0,0)<<move_to(bm[ij.i][ij.j].x, bm[ij.i][ij.j].y+mrt/2)
                    <<line_to(bm[ij.i][ij.j+4].x+mrt,bm[ij.i][ij.j+4].y+mrt/2)
                    <<move_to(bm[ij.i][ij.j].x, bm[ij.i][ij.j].y+mrt/2+1)
                    <<line_to(bm[ij.i][ij.j+4].x+mrt,bm[ij.i][ij.j+4].y+mrt/2);
                    gameover=true;
                    }
                    else if (ij.oszlop){
                    gout<<color(255,0,0)<<move_to(bm[ij.i][ij.j].x+mrt/2, bm[ij.i][ij.j].y)
                    <<line_to(bm[ij.i+4][ij.j].x+mrt/2,bm[ij.i+4][ij.j].y+mrt)
                    <<move_to(bm[ij.i][ij.j].x+mrt/2+1, bm[ij.i][ij.j].y)
                    <<line_to(bm[ij.i+4][ij.j].x+mrt/2,bm[ij.i+4][ij.j].y+mrt);
                    gameover=true;
                    }
                }
        }
    }
    gout<<color(100,250,250)<<move_to(_x,_size_y+10)<<text("X: ")<<text(to_str(allasx,0))
    <<color(100,250,100)<<move_to(_x+60,_size_y+10)<<text("O: ")<<text(to_str(allaso,0));
}

void amoba::handle(event ev)
{
    if (ev.type == ev_mouse && ev.button== btn_left)
    {
        for (int i=0; i<palyasize; i++)
        {
            for (int j=0; j<palyasize; j++)
            {
                if (ev.pos_x > bm[i][j].x && ev.pos_x < bm[i][j].x+bm[i][j].meret &&
                    ev.pos_y > bm[i][j].y && ev.pos_y < bm[i][j].y+bm[i][j].meret &&
                    !bm[i][j].foglalt && !gameover)
                {
                    bm[i][j].nyomva=true;
                    XO++;
                    if (XO%2) bm[i][j].X=true;
                    else if (XO%2==0) bm[i][j].O=true;
                }
            }
        }
    }

        if (winX && winhez) {
            allasx++;
            winhez=false;
        }
        else if (winO && winhez ) {
            allaso++;
            winhez=false;
        }
}

matrixindex amoba::ellenoriznk(){
    ij.i=-1;
    ij.j=-1;
    ij.sor=ij.oszlop=ij.foatlo=ij.mellekatlo=false;
    for (int i=0;i<palyasize;i++){
        for (int j=0;j<palyasize;j++){
        if (i<palyasize && j<palyasize-4) {
            if (bm[i][j].X && bm[i][j+1].X && bm[i][j+2].X && bm[i][j+3].X && bm[i][j+4].X){
                ij.i=i;
                ij.j=j;
                ij.sor=true;
                winX=true;
                return ij;
            }
            if (bm[i][j].O && bm[i][j+1].O && bm[i][j+2].O && bm[i][j+3].O && bm[i][j+4].O){
                ij.i=i;
                ij.j=j;
                ij.sor=true;
                winO=true;
                return ij;
            }
            }
            if (i<palyasize-4 && j<palyasize) {
             if (bm[i][j].X && bm[i+1][j].X && bm[i+2][j].X && bm[i+3][j].X && bm[i+4][j].X){
                ij.i=i;
                ij.j=j;
                ij.oszlop=true;
                winX=true;
                return ij;
            }
            if (bm[i][j].O && bm[i+1][j].O && bm[i+2][j].O && bm[i+3][j].O && bm[i+4][j].O){
                ij.i=i;
                ij.j=j;
                ij.oszlop=true;
                winO=true;
                return ij;
            }
            }
            if (i<palyasize-4 && j< palyasize-4){
            if (bm[i][j].X && bm[i+1][j+1].X && bm[i+2][j+2].X && bm[i+3][j+3].X && bm[i+4][j+4].X){
                ij.i=i;
                ij.j=j;
                ij.sor=ij.oszlop=ij.foatlo=true;
                winX=true;
                return ij;
            }
            if (bm[i][j].O && bm[i+1][j+1].O && bm[i+2][j+2].O && bm[i+3][j+3].O && bm[i+4][j+4].O){
                ij.i=i;
                ij.j=j;
                ij.sor=ij.oszlop=ij.foatlo=true;
                winO=true;
                return ij;
            }
            }
            if (i<palyasize-4 && j<palyasize){
            if (bm[i][j].X && bm[i+1][j-1].X && bm[i+2][j-2].X && bm[i+3][j-3].X && bm[i+4][j-4].X){
                ij.i=i;
                ij.j=j;
                ij.sor=ij.oszlop=ij.mellekatlo=true;
                winX=true;
                return ij;
            }
            if (bm[i][j].O && bm[i+1][j-1].O && bm[i+2][j-2].O && bm[i+3][j-3].O && bm[i+4][j-4].O){
                ij.i=i;
                ij.j=j;
                ij.sor=ij.oszlop=ij.mellekatlo=true;
                winO=true;
                return ij;
            }
            }
        }
    }
    return ij;
}

void amoba::newgame(){
    bm.clear();
    gameover=false;
    XO=0;
    std::vector<negyzet> bv;
    negyzet nzt;
    for (int n=0; n<palyasize; n++)
    {
        for (int k=0; k<palyasize; k++)
        {
            nzt.meret=sxmeret/palyasize;
            nzt.x=_x+(k*nzt.meret);
            nzt.y=_y+(n*nzt.meret);
            nzt.nyomva=false;
            nzt.O=false;
            nzt.X=false;
            nzt.foglalt=false;
            winX=winO=false;
            winhez=true;
            bv.push_back(nzt);
        }
        bm.push_back(bv);
        bv.clear();
    }
}
