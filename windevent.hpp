#ifndef WINDEVENT_HPP_INCLUDED
#define WINDEVENT_HPP_INCLUDED
#include "widgets.hpp"
#include <vector>

class Widget;

class Windevent {
protected:
  std::vector<Widget*> widgets;

public:
  void event_loop();
  void new_widget(Widget *);
  virtual ~Windevent();
};

#endif // WINDEVENT_HPP_INCLUDED
