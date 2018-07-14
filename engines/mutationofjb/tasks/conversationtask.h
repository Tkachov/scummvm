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

#include "mutationofjb/tasks/task.h"
#include "mutationofjb/gamedata.h"
#include "mutationofjb/widgets/conversationwidget.h"

namespace MutationOfJB {

class SayTask;

class ConversationTask : public Task, public ConversationWidgetCallback {
public:
	ConversationTask(uint8 sceneId, const ConversationInfo& convInfo) : _sceneId(sceneId), _convInfo(convInfo), _currentLineIndex(0), _currentItem(nullptr), _sayTask(nullptr), _substate(IDLE), _haveChoices(false) {}
	virtual ~ConversationTask() {}

	virtual void start() override;
	virtual void update() override;

	virtual void onChoiceClicked(ConversationWidget *, int response, uint32 data) override;
private:
	void showChoicesOrPick();
	const ConversationInfo::Line *getCurrentLine() const;
	void finish();

	uint8 _sceneId;
	const ConversationInfo &_convInfo;
	uint _currentLineIndex;
	const ConversationInfo::Item *_currentItem;
	SayTask* _sayTask;

	enum Substate {
		IDLE,
		SAYING_CHOICE,
		SAYING_RESPONSE,
		SAYING_NO_CHOICES
	};

	Substate _substate;
	bool _haveChoices;
};

}