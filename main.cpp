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

amoba * am= new amoba(25,0,500,500);
gomb * gmb = new gomb(10,520,100,40);

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
        if (gmb->nyomva()) am->newgame();
        gout << refresh;
    }
}

int main()
{
    gout.open(600,600);
    vector<Widget*> w;


    gmb->szoveg("Uj jatek");

    w.push_back(gmb);
    w.push_back(am);


    /*for (Widget * wg : w) {
    }*/

    event_loop(w);
    return 0;
}
