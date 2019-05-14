#include <vector>
#include "graphics.hpp"
#include "widgets.hpp"
#include "Counter.hpp"
#include "chooseit.hpp"
#include "text.hpp"

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
    gout.open(400,400);
    vector<Widget*> w;
    counter * co1 = new counter(10,10,110,30);
    counter * co2 = new counter(10,100,50,50);
    Chooseit *ch1 = new Chooseit(200,200,120,120);
    Chooseit *ch2 = new Chooseit(200,20,150,100);
    Text * txt = new Text(20,340,60,40);
    w.push_back(co1);
    w.push_back(co2);
    w.push_back(ch1);
    w.push_back(ch2);
    w.push_back(txt);
    ch1->menu("Vissza,Szin,Meret,Vezerlopult,Nyelv,Hatter");
    ch2->menu("Asztal,Hirek,Memoria,Dokumentumok,Uj mappa,Datum,Fotok,Internet,Bluetooth,Skype,Ido,Etel,Zene");
    co2->tartomany(-10,313);
    co1->tofile("Szamlalo1.txt");
    co2->tofile("Szamlalo2.txt");
    ch1->tofile("valaszto1.txt");
    ch2->tofile("valaszto2.txt");


    for (Widget * wg : w) {
    }
    gout <<color(0,0,0)<<move_to(0,0)<<box_to(400,400)<<refresh;
    event_loop(w);
    return 0;
}
