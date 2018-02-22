#include "functions.h"


void init_opengl()
{
        //OpenGL initialization
        glViewport(0, 0, gl.xres, gl.yres);
        //Initialize matrices
        glMatrixMode(GL_PROJECTION); glLoadIdentity();
        glMatrixMode(GL_MODELVIEW); glLoadIdentity();
        //This sets 2D mode (no perspective)
        glOrtho(0, gl.xres, 0, gl.yres, -1, 1);
        //
        glDisable(GL_LIGHTING);
        glDisable(GL_DEPTH_TEST);
        glDisable(GL_FOG);
        glDisable(GL_CULL_FACE);
        //
        //Clear the screen to black 
        glClearColor(0.0, 0.0, 0.0, 1.0);
        //Do this to allow fonts
        glEnable(GL_TEXTURE_2D);
        initialize_fonts();
}

void normalize2d(Vec v)
{
        Flt len = v[0]*v[0] + v[1]*v[1];
        if (len == 0.0f) {
                v[0] = 1.0;
                v[1] = 0.0;
                return;
        }
        len = 1.0f / sqrt(len);
        v[0] *= len;
        v[1] *= len;
}

int check_keys(XEvent *e)
{
        //keyboard input?
        static int shift=0;
        if (e->type != KeyPress && e->type != KeyRelease)
                return 0;
        int key = (XLookupKeysym(&e->xkey, 0) & 0x0000ffff);
        //Log("key: %i\n", key);
        if (e->type == KeyRelease) {
                gl.keys[key]=0;
                if (key == XK_Shift_L || key == XK_Shift_R)
                        shift=0;
                return 0;
        }
        gl.keys[key]=1;
        if (key == XK_Shift_L || key == XK_Shift_R) {
                shift=1;
                return 0;
        }
        (void)shift;
        switch (key) {
                case XK_Escape:
                        return 1;
                case XK_w:
                        break;
                case XK_a:
                        g.ship.vel[0] -= .2;
                        break;
                case XK_s:
                        break;
                case XK_d:
                        g.ship.vel[0] += .2;
                        break;
                case XK_equal:
                        break;
                case XK_minus:
                        break;
        }
        return 0;
}

