#ifndef CHOOSEIT_HPP_INCLUDED
#define CHOOSEIT_HPP_INCLUDED
#include "widgets.hpp"
#include <vector>
#include <fstream>



class Chooseit : public Widget {
protected:
    std::vector<std::string> _szv;
    std::string fname;
    int belefer=0, girany=0, elemi=0;
public:
    Chooseit(int x, int y, int sx, int sy);
    virtual void menu(std::string sor);
    virtual void handle(genv::event ev);
    virtual void draw() ;
    virtual void new_menu(std::string newmenu);
    virtual int szovegmag();
    virtual bool kilog();
    virtual double gmeret();
    virtual double glepes();
    virtual void tofile(std::string fn);
};

#endif
