#include "render.h"

void render()
{
	Rect r;
        glClear(GL_COLOR_BUFFER_BIT);
        //
        r.bot = gl.yres - 20;
        r.left = 10;
        r.center = 0;
        ggprint8b(&r, 16, 0x00ff0000, "3350 - Asteroids");
        ggprint8b(&r, 16, 0x00ffff00, "n bullets: %i", g.nbullets);
        ggprint8b(&r, 16, 0x00ffff00, "n asteroids: %i", g.nasteroids);
        ggprint8b(&r, 16, 0x00ffff00, "n asteroids destroyed: ");
        //
        //-------------
        //Draw the ship
        glColor3fv(g.ship.color);
        glPushMatrix();
        glTranslatef(g.ship.pos[0], g.ship.pos[1], g.ship.pos[2]);
        glRotatef(g.ship.angle, 0.0f, 0.0f, 1.0f);
        glBegin(GL_TRIANGLES);
                glVertex2f(-12.0f, -10.0f);
                glVertex2f(  0.0f, 20.0f);
                glVertex2f(  0.0f, -6.0f);
                glVertex2f(  0.0f, -6.0f);
                glVertex2f(  0.0f, 20.0f);
                glVertex2f( 12.0f, -10.0f);
        glEnd();
        glColor3f(1.0f, 0.0f, 0.0f);
        glBegin(GL_POINTS);
                glVertex2f(0.0f, 0.0f);
        glEnd();
        glPopMatrix();
        if (gl.keys[XK_Up] || g.mouseThrustOn) {
                int i;
                //draw thrust
                Flt rad = ((g.ship.angle+90.0) / 360.0f) * PI * 2.0;
                //convert angle to a vector
                Flt xdir = cos(rad);
                Flt ydir = sin(rad);
                Flt xs,ys,xe,ye,r;
                glBegin(GL_LINES);
                        for (i=0; i<16; i++) {
                                xs = -xdir * 11.0f + rnd() * 4.0 - 2.0;
                                ys = -ydir * 11.0f + rnd() * 4.0 - 2.0;
                                r = rnd()*40.0+40.0;
                                xe = -xdir * r + rnd() * 18.0 - 9.0;
                                ye = -ydir * r + rnd() * 18.0 - 9.0;
                                glColor3f(rnd()*.3+.7, rnd()*.3+.7, 0);
                                glVertex2f(g.ship.pos[0]+xs,g.ship.pos[1]+ys);
                                glVertex2f(g.ship.pos[0]+xe,g.ship.pos[1]+ye);
                        }
                glEnd();
        }
        //------------------
        //----------------
        //Draw the bullets
        Bullet *b = &g.barr[0];
        for (int i=0; i<g.nbullets; i++) {
                //Log("draw bullet...\n");
                glColor3f(1.0, 1.0, 1.0);
                glBegin(GL_POINTS);
                        glVertex2f(b->pos[0],      b->pos[1]);
                        glVertex2f(b->pos[0]-1.0f, b->pos[1]);
                        glVertex2f(b->pos[0]+1.0f, b->pos[1]);
                        glVertex2f(b->pos[0],      b->pos[1]-1.0f);
                        glVertex2f(b->pos[0],      b->pos[1]+1.0f);
                        glColor3f(0.8, 0.8, 0.8);
                        glVertex2f(b->pos[0]-1.0f, b->pos[1]-1.0f);
                        glVertex2f(b->pos[0]-1.0f, b->pos[1]+1.0f);
                        glVertex2f(b->pos[0]+1.0f, b->pos[1]-1.0f);
                        glVertex2f(b->pos[0]+1.0f, b->pos[1]+1.0f);
                glEnd();
                ++b;
        }
}

