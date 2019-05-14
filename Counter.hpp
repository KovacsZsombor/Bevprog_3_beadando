#ifndef COUNTER_HPP_INCLUDED
#define COUNTER_HPP_INCLUDED
#include "widgets.hpp"
#include <sstream>
#include <fstream>

class counter : public Widget {
protected:
    bool _checked;
    std::string _num, fname;
    int szam=0,cmax,cmin;
public:
    counter(int x, int y, int sx, int sy);
    virtual void draw() ;
    virtual void handle(genv::event ev);
    virtual void tofile(std::string fn);
    virtual void tartomany(int minszam, int maxszam);
};


#endif
