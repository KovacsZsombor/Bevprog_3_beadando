#ifndef TEXT_HPP_INCLUDED
#define TEXT_HPP_INCLUDED
#include "widgets.hpp"
#include <sstream>
#include <fstream>

class Text : public Widget {
protected:
    std::string _num, fname;
public:
    Text(int x, int y, int sx, int sy);
    virtual void draw() ;
    virtual void handle(genv::event ev);
    virtual void tofile(std::string fn);
};

#endif // TEXT_HPP_INCLUDED
