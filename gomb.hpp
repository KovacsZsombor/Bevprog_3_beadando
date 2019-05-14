#ifndef GOMB_HPP_INCLUDED
#define GOMB_HPP_INCLUDED
#include "widgets.hpp"
#include "graphics.hpp"

class gomb : public Widget {
protected:
    std::string gombnev="G";
    bool push=false;
public:
    gomb(int x, int y, int sx, int sy);
    virtual void draw() ;
    virtual void szoveg(std::string sz) ;
    virtual void handle(genv::event ev);
    virtual bool nyomva();
};


#endif // GOMB_HPP_INCLUDED
