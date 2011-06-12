#ifndef __ZONEIDBROWSER_H
#define __ZONEIDBROWSER_H

#include <string>

#include "window.h"
#include "buttonUI.h"

class Gui;
class ui_ListView;

class ui_ZoneIdBrowser : public window
{
public:
	ui_ZoneIdBrowser(int xPos,int yPos, int w, int h, Gui *setGui);
	void setMapID(int id);
	void setZoneID( int id );
	void ButtonMapPressed( int id );
	void refreshMapPath();
	void setChangeFunc( void (*f)( frame *, int ));
private:
	void ( *changeFunc )( frame *, int );
	Gui *mainGui;
	ui_ListView *ZoneIdList;
	int heightExpanded;
	int mapID;
	unsigned int zoneID;
	int subZoneID;
	int selectedAreaID;
	void buildAreaList();
	void expandList();
	void collapseList();
	std::string MapName;
	std::string ZoneName;
	std::string SubZoneName;
	buttonUI *backZone;
	textUI *ZoneIDPath;
};

#endif