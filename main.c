#include <X11/xpm.h>
#include <stdio.h>
#include <stdlib.h>
#include <X11/Xlib.h>
#include <string.h>
#include "vroot.h"

int main(){
    Display *dpy;
    Window root;
    GC g;
    XWindowAttributes wa;
    XImage *cows;
    int cownum;

    dpy = XOpenDisplay(getenv("DISPLAY"));
    root = DefaultRootWindow(dpy);
    g = XCreateGC (dpy, root, 0, NULL);

    if(XpmReadFileToImage(dpy, "cow.xpm", &cows, NULL, NULL)){
        printf("whoops! you have to put the cd, in your computer.\n");
        exit(1);
    }

    XSetForeground(dpy, g, WhitePixelOfScreen(DefaultScreenOfDisplay(dpy)));

    while(1){
        cownum = random()&52;
        char stringthing[30] = "cows/FUNNY";
        strcat(stringthing, itoa(cownum));
        strcat(stringthing, ".xpm");

        XpmReadFileToImage(dpy, stringthing, &cows, NULL, NULL);
        XPutImage(dpy, root, g, cows, 0, 0, XDisplayWidth(dpy, root) / 2, XDisplayHeight(dpy, root) / 2, cows->width, cows->height);
    
        //XClearWindow(dpy, root);
        XFlush(dpy);
        usleep(1000);
    }
    XCloseDisplay(dpy);
}