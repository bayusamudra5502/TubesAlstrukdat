#include "gadget.h"

#include <stdio.h>

void g_set_gadget(Gadget *gadget, int type) {
  if (type == 1) {
    gadget->gadgetID = 1;
    gadget->label = 'K';
    gadget->price = 800;
  } else if (type == 2) {
    gadget->gadgetID = 2;
    gadget->label = 'S';
    gadget->price = 1200;
  } else if (type == 3) {
    gadget->gadgetID = 3;
    gadget->label = 'P';
    gadget->price = 1500;
  } else if (type == 4) {
    gadget->gadgetID = 4;
    gadget->label = 'M';
    gadget->price = 3000;
  }
}
