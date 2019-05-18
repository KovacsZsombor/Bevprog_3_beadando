#include "graphics.hpp"
#include "widgets.hpp"
#include "Counter.hpp"
#include "gomb.hpp"
#include "amoba.hpp"
#include "chooseit.hpp"
#include "text.hpp"
#include "windevent.hpp"
#include <iostream>

using namespace std;
using namespace genv;



void event_loop(vector<Widget*>& widgets) {
    event ev;
    int focus = -1;
    while(gin >> ev ) {
        if (ev.type == ev_mouse && ev.button==btn_left) {
            for (size_t i=0;i<widgets.size();i++) {
                if (widgets[i]->selected(ev.pos_x, ev.pos_y)) {
                        focus = i;
                }
            }
        }
        if (focus!=-1) {
            widgets[focus]->handle(ev);
        }
        for (Widget * w : widgets) {
            w->draw();
        }
        gout << refresh;
    }
}

int main()
{
    gout.open(600,600);
    vector<Widget*> w;

    amoba * am= new amoba(25,0,400,400);
    gomb * gmb = new gomb(10,420,100,40);
    gmb->szoveg("Uj jatek");
    if (gmb->nyomva()) {
    am->newgame();
    std::cout<<"Uj jatek"<<"  ";
    }
    w.push_back(gmb);
    w.push_back(am);


    /*for (Widget * wg : w) {
    }*/

    event_loop(w);
    return 0;
}
