#ifndef AMOBA_HPP_INCLUDED
#define AMOBA_HPP_INCLUDED
#include "widgets.hpp"
#include "graphics.hpp"
#include <vector>


class amoba : public Widget{
protected:
    std::vector<std::vector<bool> > bm;

    int meret=20;
public:
    amoba (int x, int y,int sx,int sy);
    virtual void draw();
    virtual void handle(genv::event ev);
};

#endif // AMOBA_HPP_INCLUDED
