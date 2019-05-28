//
// This file is used by the template to render a basic scene using GL.
//

#include "pch.h"
#include "SimpleRenderer.h"
#include "MathHelper.h"

extern "C" {
#include <simpleservo.h>
}

using namespace Platform;

using namespace foobar;

void loadServo();

SimpleRenderer::SimpleRenderer() :
    mWindowWidth(0),
    mWindowHeight(0)
{
	const char* version = servo_version();
	std::string s_str = std::string(version);
	std::wstring wid_str = std::wstring(s_str.begin(), s_str.end());
	OutputDebugString(wid_str.c_str());

	loadServo();
}

SimpleRenderer::~SimpleRenderer()
{

}

void SimpleRenderer::Draw()
{
    glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// perform_updates();
}

void SimpleRenderer::UpdateWindowSize(GLsizei width, GLsizei height)
{
    glViewport(0, 0, width, height);
    mWindowWidth = width;
    mWindowHeight = height;
}


void flush() {
}

void make_current() {
}

void wakeup() {
}

void on_load_started() {}
void on_load_ended() {}
void on_title_changed(const char *foo) {}
void on_url_changed(const char* foo) {}
void on_history_changed(bool back, bool fwd) {}
void on_animating_changed(bool animating) {}
void on_shutdown_complete() {}

void loadServo() {
	CInitOptions o;
	o.args = "[\"https://example.com\"]";
	o.url = "https://servo.org";
	o.width = 600;
	o.height = 600;
	o.density = 1.0;
	o.enable_subpixel_text_antialiasing = true;

	CHostCallbacks c;
	c.flush = &flush;
	c.make_current = &make_current;
	c.on_load_started = &on_load_started;
	c.on_load_ended = &on_load_ended;
	c.on_title_changed = &on_title_changed;
	c.on_url_changed = &on_url_changed;
	c.on_history_changed = &on_history_changed;
	c.on_animating_changed = &on_animating_changed;
	c.on_shutdown_complete = &on_shutdown_complete;

	init_with_egl(o, &wakeup, c);
}