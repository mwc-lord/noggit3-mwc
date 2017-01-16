// This file is part of Noggit3, licensed under GNU General Public License (version 3).

#include <iostream>
#include <sstream>
#include <string>
#include <boost/bind.hpp>

#include <noggit/DBC.h>
#include <noggit/Log.h>
#include <noggit/Misc.h>
#include <noggit/application.h> // app.getArial14(), arialn13
#include <noggit/World.h>
#include <noggit/UIButton.h>
#include <noggit/UIListView.h>
#include <noggit/UIMapViewGUI.h>
#include <noggit/UIScrollBar.h>
#include <noggit/UIText.h> // UIText
#include <noggit/UICloseWindow.h> // UICloseWindow
#include <noggit/UIWaterTypeBrowser.h>
#include <noggit/UIWater.h>

UIWaterTypeBrowser::UIWaterTypeBrowser(float xPos, float yPos, float w, float h, UIMapViewGUI *setGui)
	: UICloseWindow(xPos, yPos, w, h, "", true)
	, mainGui(setGui)
{
	addChild(new UIText(10.0f, 3.0f, "Select a water type", app.getArial14(), eJustifyLeft));
	buildTypeList();
}


void UIWaterTypeBrowser::buildTypeList()
{
	removeChild(WaterTypeList);
	WaterTypeList = new UIListView(4, 24, width() - 8, height() - 28, 20);
	WaterTypeList->clickable(true);
	addChild(WaterTypeList);




	//LiquidTypeDB::getLiquidName(gWorld->getWaterType(tileX, tileY));

	for (DBCFile::Iterator i = gLiquidTypeDB.begin(); i != gLiquidTypeDB.end(); ++i)
	{

		UIFrame *curFrame = new UIFrame(1, 1, 1, 1);
		std::stringstream ss;
		ss << i->getInt(LiquidTypeDB::ID) << "-" << LiquidTypeDB::getLiquidName(i->getInt(LiquidTypeDB::ID));
		UIButton *tempButton = new UIButton(0.0f,
			0.0f,
			200.0f,
			28.0f,
			ss.str(),
			"Interface\\DialogFrame\\UI-DialogBox-Background-Dark.blp",
			"Interface\\DialogFrame\\UI-DialogBox-Background-Dark.blp",
			boost::bind(&UIWaterTypeBrowser::setWaterTypeID, this, _1, _2), //steff: kidding me? we talked about this some h before u did this
			i->getInt(LiquidTypeDB::ID)
			);
		tempButton->setLeft();
		curFrame->addChild(tempButton);
		WaterTypeList->addElement(curFrame);

	}

	WaterTypeList->recalcElements(1);
}

void UIWaterTypeBrowser::setWaterTypeID(UIFrame *f, int id)
{
	mainGui->guiWater->changeWaterType(id);
}
