#ifndef _DISPLAY_
#define _DISPLAY_

#include "display_object.h"

struct display {
    int rows;
    int columns;
    unsigned char *d;
};
typedef struct display display;


#endif
