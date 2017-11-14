#ifndef _DISPLAY_
#define _DISPLAY_

#include "display_object.h"

struct display {
    unsigned char *d;
    int rows;
    int columns;
};
typedef struct display display;


#endif
