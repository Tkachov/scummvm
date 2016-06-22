/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#include "common/util.h"
#include "gui/widgets/scrollcontainer.h"
#include "gui/gui-manager.h"

#include "gui/ThemeEval.h"

namespace GUI {

ScrollContainerWidget::ScrollContainerWidget(GuiObject *boss, int x, int y, int w, int h)
	: Widget(boss, x, y, w, h) {
	init();
}

ScrollContainerWidget::ScrollContainerWidget(GuiObject *boss, const Common::String &name)
	: Widget(boss, name) {
	init();
}

void ScrollContainerWidget::init() {
	setFlags(WIDGET_ENABLED);
	_type = kScrollContainerWidget;
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
	_verticalScroll = new ScrollBarWidget(this, _w-16, 0, 16, _h);
	_verticalScroll->setTarget(this);
	_scrolledX = 0;
	_scrolledY = 0;
	_limitH = 140;
=======
	_verticalScroll = nullptr;
=======
>>>>>>> baa5cc8... GUI: Cleanup in ScrollContainer
	_verticalScroll = new ScrollBarWidget(this, _w-16, 0, 16, _h);
	_verticalScroll->setTarget(this);
	_scrolledX = 0;
	_scrolledY = 0;
	_limitH = 140;
<<<<<<< HEAD
	_clippingArea = Common::Rect(0, 0, _w, _h);
>>>>>>> 75117ff... GUI: Add ScrollContainer
=======
>>>>>>> 2ef853d... GUI: Remove _clippingArea from ScrollContainer
=======
	_verticalScroll = nullptr;
=======
>>>>>>> baa5cc8... GUI: Cleanup in ScrollContainer
	_verticalScroll = new ScrollBarWidget(this, _w-16, 0, 16, _h);
	_verticalScroll->setTarget(this);
	_scrolledX = 0;
	_scrolledY = 0;
	_limitH = 140;
<<<<<<< HEAD
	_clippingArea = Common::Rect(0, 0, _w, _h);
>>>>>>> 75117ff... GUI: Add ScrollContainer
=======
>>>>>>> 2ef853d... GUI: Remove _clippingArea from ScrollContainer
	recalc();
}

void ScrollContainerWidget::recalc() {
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
	int scrollbarWidth = g_gui.xmlEval()->getVar("Globals.Scrollbar.Width", 0);
	_limitH = _h;
=======
	int scrollbarWidth = g_gui.xmlEval()->getVar("Globals.Scrollbar.Width", 0);
<<<<<<< HEAD

	//calculate _limitH - available height (boss's height - boss's "offset")
	int d = _boss->getChildY() - _boss->getAbsY();	
	_limitH = _boss->getHeight() - d;
>>>>>>> bc49259... GUI: Update ScrollContainerWidget
=======
	_limitH = _h;
>>>>>>> cdea070... GUI: Add ThemeLayoutTabWidget
	
	//calculate virtual height
	const int spacing = g_gui.xmlEval()->getVar("Global.Font.Height", 16); //on the bottom
	int h = 0;
	int min = spacing, max = 0;
	Widget *ptr = _firstWidget;
	while (ptr) {
		if (ptr != _verticalScroll) {
			int y = ptr->getAbsY() - getChildY();
			min = MIN(min, y - spacing);
			max = MAX(max, y + ptr->getHeight() + spacing);
		}
		ptr = ptr->next();
	}
	h = max - min;

	_verticalScroll->_numEntries = h;
<<<<<<< HEAD
	_verticalScroll->_currentPos = _scrolledY;
	_verticalScroll->_entriesPerPage = _limitH;
	_verticalScroll->setPos(_w - scrollbarWidth, _scrolledY+1);
	_verticalScroll->setSize(scrollbarWidth, _limitH -2);
}


ScrollContainerWidget::~ScrollContainerWidget() {}

int16 ScrollContainerWidget::getChildX() const {
	return getAbsX() - _scrolledX;
}

int16 ScrollContainerWidget::getChildY() const {
	return getAbsY() - _scrolledY;
}

uint16 ScrollContainerWidget::getWidth() const {
	return _w - (_verticalScroll->isVisible() ? _verticalScroll->getWidth() : 0);
=======
	_verticalScroll->_numEntries = _h;
=======
	_verticalScroll->_numEntries = _h + 40;
>>>>>>> ef58fcf... GUI: drawRoundedSquareAlgClip
=======
>>>>>>> bc49259... GUI: Update ScrollContainerWidget
	_verticalScroll->_currentPos = _scrolledY;
	_verticalScroll->_entriesPerPage = _limitH;
	_verticalScroll->setPos(_w - scrollbarWidth, _scrolledY+1);
	_verticalScroll->setSize(scrollbarWidth, _limitH -2);
}


ScrollContainerWidget::~ScrollContainerWidget() {}

int16 ScrollContainerWidget::getChildX() const {
	return getAbsX() - _scrolledX;
}

int16 ScrollContainerWidget::getChildY() const {
	return getAbsY() - _scrolledY;
}

uint16 ScrollContainerWidget::getWidth() const {
<<<<<<< HEAD
<<<<<<< HEAD
	return (_boss ? _boss->getWidth() : _w);
>>>>>>> 75117ff... GUI: Add ScrollContainer
=======
	return _w - _verticalScroll->getWidth();
>>>>>>> bc49259... GUI: Update ScrollContainerWidget
=======
	return _w - (_verticalScroll->isVisible() ? _verticalScroll->getWidth() : 0);
>>>>>>> cf05c6a... GUI: Hide scrollbar in ScrollContainerWidget when needed
=======
	_verticalScroll->_numEntries = _h;
=======
	_verticalScroll->_numEntries = _h + 40;
>>>>>>> ef58fcf... GUI: drawRoundedSquareAlgClip
	_verticalScroll->_currentPos = _scrolledY;
	_verticalScroll->_entriesPerPage = _limitH;
	_verticalScroll->setPos(_w - 16, _scrolledY);
	_verticalScroll->setSize(16, _limitH);
}


ScrollContainerWidget::~ScrollContainerWidget() {}

int16 ScrollContainerWidget::getChildX() const {
	return getAbsX() - _scrolledX;
}

int16 ScrollContainerWidget::getChildY() const {
	return getAbsY() - _scrolledY;
}

uint16 ScrollContainerWidget::getWidth() const {
	return (_boss ? _boss->getWidth() : _w);
>>>>>>> 75117ff... GUI: Add ScrollContainer
}

uint16 ScrollContainerWidget::getHeight() const {
	return _limitH;
}

void ScrollContainerWidget::handleCommand(CommandSender *sender, uint32 cmd, uint32 data) {
	Widget::handleCommand(sender, cmd, data);	
	switch (cmd) {
	case kSetPositionCmd:
		_scrolledY = _verticalScroll->_currentPos;
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
		reflowLayout();
		draw();
		g_gui.doFullRedraw();
		break;
	}	
}

void ScrollContainerWidget::reflowLayout() {
<<<<<<< HEAD
	Widget::reflowLayout();

	//reflow layout of inner widgets
	Widget *ptr = _firstWidget;
	while (ptr) {
		ptr->reflowLayout();
		ptr = ptr->next();
	}
	
	//recalculate height
	recalc();

	//hide those widgets which are out of visible area
	ptr = _firstWidget;
	while (ptr) {
		int y = ptr->getAbsY() - getChildY();
		int h = ptr->getHeight();
		bool visible = true;
		if (y + h - _scrolledY < 0) visible = false;
		if (y - _scrolledY > _limitH) visible = false;
		ptr->setVisible(visible);
		ptr = ptr->next();
	}

	_verticalScroll->setVisible(_verticalScroll->_numEntries > _limitH); //show when there is something to scroll
}

void ScrollContainerWidget::drawWidget() {
	g_gui.theme()->drawDialogBackgroundClip(Common::Rect(_x, _y, _x + _w, _y + getHeight() - 1), getBossClipRect(), ThemeEngine::kDialogBackgroundDefault);
}

Widget *ScrollContainerWidget::findWidget(int x, int y) {
	if (_verticalScroll->isVisible() && x >= _w - _verticalScroll->getWidth())
		return _verticalScroll;
=======
		recalc();
=======
		reflowLayout();
>>>>>>> f651de2... GUI: Make ScrollContainerWidget hide children
		draw();
		g_gui.doFullRedraw();
		break;
	}	
}

void ScrollContainerWidget::reflowLayout() {
	recalc();
=======
>>>>>>> bc49259... GUI: Update ScrollContainerWidget
	Widget::reflowLayout();

	//reflow layout of inner widgets
	Widget *ptr = _firstWidget;
	while (ptr) {
		ptr->reflowLayout();
		ptr = ptr->next();
	}
	
	//recalculate height
	recalc();

	//hide those widgets which are out of visible area
	ptr = _firstWidget;
	while (ptr) {
		int y = ptr->getAbsY() - getChildY();
		int h = ptr->getHeight();
		bool visible = true;
		if (y + h - _scrolledY < 0) visible = false;
		if (y - _scrolledY > _limitH) visible = false;
		ptr->setVisible(visible);
		ptr = ptr->next();
	}

	_verticalScroll->setVisible(_verticalScroll->_numEntries > _limitH); //show when there is something to scroll
}

void ScrollContainerWidget::drawWidget() {
	g_gui.theme()->drawDialogBackgroundClip(Common::Rect(_x, _y, _x + _w, _y + getHeight() - 1), getBossClipRect(), ThemeEngine::kDialogBackgroundDefault);
}

Widget *ScrollContainerWidget::findWidget(int x, int y) {
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
		recalc();
=======
		reflowLayout();
>>>>>>> f651de2... GUI: Make ScrollContainerWidget hide children
		draw();
		break;
	}	
}

void ScrollContainerWidget::reflowLayout() {
	recalc();
	Widget::reflowLayout();
	Widget *ptr = _firstWidget;
	while (ptr) {
		int y = ptr->getAbsY() - getChildY();
		int h = ptr->getHeight();
		bool visible = true;
		if (y + h - _scrolledY < 0) visible = false;
		if (y - _scrolledY > _limitH) visible = false;
		ptr->setVisible(visible);
		ptr = ptr->next();
	}
}

void ScrollContainerWidget::drawWidget() {
	g_gui.theme()->drawDialogBackground(Common::Rect(_x, _y, _x + _w, _y + getHeight()), ThemeEngine::kDialogBackgroundDefault);
}

Widget *ScrollContainerWidget::findWidget(int x, int y) {
<<<<<<< HEAD
>>>>>>> 75117ff... GUI: Add ScrollContainer
	/*
	if (y < _tabHeight) {
		if (_tabWidth * _tabs.size() > _w) {
			if (y >= _butTP && y < _butTP + _butH) {
				if (x >= _w - _butRP - _butW * 2 - 2 && x < _w - _butRP - _butW - 2)
					return _navLeft;
				if (x >= _w - _butRP - _butW &&  x < _w - _butRP)
					return _navRight;
			}
		}

		// Click was in the tab area
		return this;
	} else {	
		// Iterate over all child widgets and find the one which was clicked
		return Widget::findWidgetInChain(_firstWidget, x, y - _tabHeight);
	}
	*/
<<<<<<< HEAD
>>>>>>> 75117ff... GUI: Add ScrollContainer
=======
>>>>>>> baa5cc8... GUI: Cleanup in ScrollContainer
=======
	if (x >= _w - _verticalScroll->getWidth())
=======
	if (_verticalScroll->isVisible() && x >= _w - _verticalScroll->getWidth())
>>>>>>> cf05c6a... GUI: Hide scrollbar in ScrollContainerWidget when needed
		return _verticalScroll;
>>>>>>> bc49259... GUI: Update ScrollContainerWidget
=======
>>>>>>> 75117ff... GUI: Add ScrollContainer
=======
>>>>>>> baa5cc8... GUI: Cleanup in ScrollContainer
	return Widget::findWidgetInChain(_firstWidget, x + _scrolledX, y + _scrolledY);
}

} // End of namespace GUI
