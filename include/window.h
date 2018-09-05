#ifndef WINDOW_H
#define WINDOW_H

#include "definitions.h"
#include "joypad.h"
#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>


class GameWindow 
{
public:
    GameWindow(Joypad *pad, int scale = 4);
    ~GameWindow();
    bool closed();
    bool frame_drawn();
    void process_input();
    void draw_frame();
    GLubyte *pbo_memory;

private:
    Joypad *joypad;
    SDL_Window *sdl_window;
    SDL_GLContext *gl_context;
    SDL_Event event;
    GLuint shader_id;
    GLuint screen_tex;
    GLuint pbo[2];
    const int window_scale;
    int key_pressed[8];
    bool draw;
    int frame_count;

    void compile_shader();
    void init_window();
    void init_glcontext();
    void init_screen_texture();
};

#endif