#include "windevent.hpp"
#include "chooseit.hpp"
#include "Counter.hpp"
#include "text.hpp"
using namespace genv;

Windevent::~Windevent(){
  for(Widget *widget: widgets){   //minden widgetet felszabadit
    delete widget;
  }
}

void Windevent::new_widget(Widget *w) {
  widgets.push_back(w);
}

void Windevent::event_loop() {
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
        gout << move_to(0,0) << color(0,0,0) << box(400,400);
        for (Widget * w : widgets) {
            w->draw();
        }
        gout << refresh;
    }
}
