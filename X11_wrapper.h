#pragma once
#include "zlib.h"

class X11_wrapper {
private:
        Display *dpy;
        Window win;
        GLXContext glc;
public:
        X11_wrapper();
        ~X11_wrapper();
        void set_title();
        void check_resize(XEvent *e);
        void reshape_window(int, int);
        void setup_screen_res(const int, const int);
        void swapBuffers();
        bool getXPending();
        XEvent getXNextEvent();
        void set_mouse_position(int, int);
	void show_mouse_cursor(const int);
} x11;

