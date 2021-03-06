#include "item.h"

static int __i_item_id = 0;

boolean i_is_equal(Item i1, Item i2) {
  return i1.expired == i2.expired && i1.itemID == i2.itemID &&
         i1.type == i2.type;
}

void i_create_item(Item* i, char type, int expired) {
  i->expired = expired;
  i->itemID = __i_item_id;
  i->type = type;

  __i_item_id++;
}

boolean i_is_expired(Item i, Time currentTime) {
  return i.expired >= currentTime;
}

boolean i_is_perishable(Item i) { return i.type == 'P'; }

boolean i_is_heavy(Item i) { return i.type == 'H'; }

char* i_item_type_name(Item i) {
  switch (i.type) {
    case 'N':
      return "Normal Item";
    case 'P':
      return "Perishable Item";
    case 'H':
      return "Heavy Item";
    case 'V':
      return "VIP Item";
    default:
      return "";
  }
}