#ifndef AMOBA_HPP_INCLUDED
#define AMOBA_HPP_INCLUDED
#include "widgets.hpp"
#include "graphics.hpp"
#include <vector>
#include <sstream>
#include <cmath>
#include <string>

struct negyzet{
    int x=0,y=0, meret=0;
    bool nyomva,O,X,foglalt;
};

struct matrixindex{
    int i,j;
    bool sor, oszlop,foatlo,mellekatlo;
};

class amoba : public Widget{
protected:
    std::vector<std::vector<negyzet> > bm;
    int XO=0, palyasize=6, sxmeret, allasx=0, allaso=0;
    matrixindex ij;
    bool gameover=false, winX=false, winO=false, winhez=true;
public:
    amoba (int x, int y,int sx,int sy);
    virtual void draw();
    virtual void handle(genv::event ev);
    virtual void newgame();
    virtual matrixindex ellenoriznk();
};

#endif // AMOBA_HPP_INCLUDED
