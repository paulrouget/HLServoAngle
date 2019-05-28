#pragma once

#include "pch.h"

namespace foobar
{
    class SimpleRenderer
    {
    public:
        SimpleRenderer();
        ~SimpleRenderer();
        void Draw();
        void UpdateWindowSize(GLsizei width, GLsizei height);

    private:
        GLsizei mWindowWidth;
        GLsizei mWindowHeight;
    };
}
