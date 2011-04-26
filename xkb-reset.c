/*  cc -L /usr/X11R6/lib   -lX11 xkb-reset.c -o xkb-reset  */
#include <X11/Xlib.h>
#include <X11/extensions/XKB.h>

 #include <stdlib.h>


// todo: switch off mouse-emulation!

main ()
{
        Display* dpy= XOpenDisplay(NULL);
        if (! dpy){
                perror("XOpenDisplay failed\n");
                exit(-1);
        }
        
        XkbLockModifiers(dpy, XkbUseCoreKbd, 255, 0);

        XkbLockGroup(dpy, XkbUseCoreKbd, XkbGroup1Index);

        XCloseDisplay(dpy);
        exit(0);
}
