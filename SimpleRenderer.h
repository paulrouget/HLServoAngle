#pragma once

#include "pch.h"

namespace foobar
{
    class SimpleRenderer
    {
    public:
        SimpleRenderer();
        ~SimpleRenderer();
        bool Draw();
        void UpdateWindowSize(GLsizei width, GLsizei height);

    private:
        GLsizei mWindowWidth;
        GLsizei mWindowHeight;
    };
}
