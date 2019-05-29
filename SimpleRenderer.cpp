//
// This file is used by the template to render a basic scene using GL.
//

#include "pch.h"
#include "SimpleRenderer.h"
#include "MathHelper.h"

extern "C" {
#include <simpleservo.h>
}

static bool dirty = false;
static bool animating = false;

using namespace Platform;

using namespace foobar;

void loadServo(int, int);

SimpleRenderer::SimpleRenderer() :
    mWindowWidth(0),
    mWindowHeight(0)
{

	loadServo(mWindowWidth, mWindowHeight);

}

SimpleRenderer::~SimpleRenderer()
{

}

bool SimpleRenderer::Draw()
{

    // glEnable(GL_DEPTH_TEST);
    // glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// glClearColor(1.0, 1.0, 1.0, 1.0);

	perform_updates();
	if (dirty || animating) {
		dirty = false;
		return true;
	}
	else {
		return false;
	}
}

void SimpleRenderer::UpdateWindowSize(GLsizei width, GLsizei height)
{
	if (width != mWindowWidth || height != mWindowHeight) {
		glViewport(0, 0, width, height);
		mWindowWidth = width;
		mWindowHeight = height;
		resize(mWindowWidth, mWindowHeight);
	}
}


void flush() {
	dirty = true;
}

void make_current() {
}

void wakeup() {
	dirty = true;
}

void on_load_started() {}
void on_load_ended() {}
void on_title_changed(const char *foo) {}
void on_url_changed(const char* foo) {}
void on_history_changed(bool back, bool fwd) {}
void on_animating_changed(bool aAnimating) {
	animating = aAnimating;
}
void on_shutdown_complete() {}

void loadServo(int width, int height) {

	CInitOptions o;
	o.args = NULL;
	o.url = "https://example.com";
	o.width = width;
	o.height = height;
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