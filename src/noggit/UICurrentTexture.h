// This file is part of Noggit3, licensed under GNU General Public License (version 3).

#pragma once

#include <string>

#include <noggit/UIEventClasses.h>
#include <noggit/UIWindow.h>

class UIMapViewGUI;
class UITexture;

class UICurrentTexture : public UIWindow, public UIEventListener
{
private:
	UIMapViewGUI* mainGui;

public:

	// current active texture
	UITexture* current_texture;
	UICurrentTexture(float x, float y, UIMapViewGUI *setGui);
	void IconSelect(int i);
};
