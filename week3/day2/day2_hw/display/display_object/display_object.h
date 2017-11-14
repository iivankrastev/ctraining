#ifndef _DISPLAY_OBJECT_
#define _DISPLAY_OBJECT_

void *display_create(unsigned char *, int, int);
void display_destroy(void *);

void setpixel(void *, int, int, unsigned char); 
unsigned char getpixel(void *, int, int);
void bresenham_line (void *, int, int, int, int);
void bresenham_circle (void *, int, int, int);
void bresenham_ellipse (void *, int, int, int, int);

#endif
