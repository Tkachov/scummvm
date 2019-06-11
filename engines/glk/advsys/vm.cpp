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

#include "glk/advsys/vm.h"

namespace Glk {
namespace AdvSys {

#define TRUE -1

OpcodeMethod VM::_METHODS[0x34] = {
	&VM::opBRT,
	&VM::opBRF,
	&VM::opBR,
	&VM::opT,
	&VM::opNIL,
	&VM::opPUSH,
	&VM::opNOT,
	&VM::opADD,
	&VM::opSUB,
	&VM::opMUL,
	&VM::opDIV,
	&VM::opREM,
	&VM::opBAND,
	&VM::opBOR,
	&VM::opBNOT,
	&VM::opLT,
	&VM::opEQ,
	&VM::opGT,
	&VM::opLIT,
	&VM::opVAR,
	&VM::opGETP,
	&VM::opSETP,
	&VM::opSET,
	&VM::opPRINT,
	&VM::opTERPRI,
	&VM::opPNUMBER,
	&VM::opFINISH,
	&VM::opCHAIN,
	&VM::opABORT,
	&VM::opEXIT,
	&VM::opRETURN,
	&VM::opCALL,
	&VM::opSVAR,
	&VM::opSSET,
	&VM::opSPLIT,
	&VM::opSNLIT,
	&VM::opYORN,
	&VM::opSAVE,
	&VM::opRESTORE,
	&VM::opARG,
	&VM::opASET,
	&VM::opTMP,
	&VM::opTSET,
	&VM::opTSPACE,
	&VM::opCLASS,
	&VM::opMATCH,
	&VM::opPNOUN,
	&VM::opRESTART,
	&VM::opRAND,
	&VM::opRNDMIZE,
	&VM::opSEND,
	&VM::opVOWEL
};

VM::VM(OSystem *syst, const GlkGameDescription &gameDesc) : GlkInterface(syst, gameDesc), Game(),
		_fp(_stack), _pc(0), _status(IN_PROGRESS) {
	Common::fill(&_nouns[0], &_nouns[20], 0);
	Common::fill(&_nounWords[0], &_nounWords[20], -1);
	Common::fill(&_adjectives[0], &_adjectives[20], (int *)nullptr);
	Common::fill(&_adjectiveWords[0], &_adjectiveWords[100], -1);
	Common::fill(&_adjectiveLists[0], &_adjectiveLists[100], -1);
}

ExecutionResult VM::execute(int offset) {
	// Set the code pointer
	_pc = offset;

	// Clear the stack
	_stack.clear();

	// Iterate through the script
	for (_status = IN_PROGRESS; !shouldQuit() && _status == IN_PROGRESS;)
		executeOpcode();

	return _status;
}

void VM::executeOpcode() {
	// Get next opcode
	uint opcode = getCodeByte(_pc);
	++_pc;

	if (opcode >= OP_BRT && opcode <= OP_VOWEL) {
		(this->*_METHODS[(int)opcode - 1])();
	} else if (opcode >= OP_XVAR && opcode < OP_XSET) {
		_stack.top() = getVariable((int)opcode - OP_XVAR);
	} else if (opcode >= OP_XSET && opcode < OP_XPLIT) {
		setVariable((int)opcode - OP_XSET, _stack.top());
	} else if (opcode >= OP_XPLIT && opcode < OP_XNLIT) {
		_stack.top() = (int)opcode - OP_XPLIT;
	} else if (opcode >= OP_XNLIT && (int)opcode < 256) {
		_stack.top() = OP_XNLIT - opcode;
	} else {
		error("Unknown opcode %x at offset %d", opcode, _pc);
	}
}
void VM::opBRT() {
	_pc = _stack.top() ? readCodeWord() : _pc + 2;
}

void VM::opBRF() {
	_pc = !_stack.top() ? readCodeWord() : _pc + 2;
}

void VM::opBR() {
	_pc = readCodeWord();
}

void VM::opT() {
	_stack.top() = TRUE;
}

void VM::opNIL() {
	_stack.top() = NIL;
}

void VM::opPUSH() {
	_stack.push(NIL);
}

void VM::opNOT() {
	_stack.top() = _stack.top() ? NIL : TRUE;
}

void VM::opADD() {
	int v = _stack.pop();
	_stack.top() += v;
}

void VM::opSUB() {
	int v = _stack.pop();
	_stack.top() -= v;
}

void VM::opMUL() {
	int v = _stack.pop();
	_stack.top() *= v;
}

void VM::opDIV() {
	int v = _stack.pop();
	_stack.top() = (v == 0) ? 0 : _stack.top() / v;
}

void VM::opREM() {
	int v = _stack.pop();
	_stack.top() = (v == 0) ? 0 : _stack.top() % v;
}

void VM::opBAND() {
	int v = _stack.pop();
	_stack.top() &= v;
}

void VM::opBOR() {
	int v = _stack.pop();
	_stack.top() |= v;
}

void VM::opBNOT() {
	_stack.top() = ~_stack.top();
}

void VM::opLT() {
	int v = _stack.pop();
	_stack.top() = (_stack.top() < v) ? TRUE : NIL;
}

void VM::opEQ() {
	int v = _stack.pop();
	_stack.top() = (_stack.top() == v) ? TRUE : NIL;
}

void VM::opGT() {
	int v = _stack.pop();
	_stack.top() = (_stack.top() > v) ? TRUE : NIL;
}

void VM::opLIT() {
	_stack.top() = readCodeWord();
}

void VM::opVAR() {
	_stack.top() = getVariable(readCodeWord());
}

void VM::opGETP() {
	int v = _stack.pop();
	_stack.top() = getObjectProperty(_stack.top(), v);
}

void VM::opSETP() {
	int v3 = _stack.pop();
	int v2 = _stack.pop();
	_stack.top() = setObjectProperty(_stack.top(), v2, v3);
}

void VM::opSET() {
	setVariable(readCodeWord(), _stack.top());
}

void VM::opPRINT() {
	Common::String msg = readString(_stack.top());
	print(msg);
}

void VM::opTERPRI() {
	print("\n");
}

void VM::opPNUMBER() {
	print(_stack.top());
}

void VM::opFINISH() {
	_status = FINISH;
}

void VM::opCHAIN() {
	_status = CHAIN;
}

void VM::opABORT() {
	_status = ABORT;
}

void VM::opEXIT() {
	quitGame();
	_status = ABORT;
}

void VM::opRETURN() {
	if (_stack.empty()) {
		_status = CHAIN;
	} else {
		int val = _stack.top();
		_stack.resize(_fp);
		_fp = _stack.pop();
		_pc = _stack.pop();

		int argsSize = _stack.pop();
		_stack.resize(_stack.size() - argsSize);
		_stack.top() = val;
	}
}

void VM::opCALL() {
	int argsSize = readCodeByte();

	_stack.push(argsSize);
	_stack.push(_pc);
	_stack.push(_fp);

	_fp.set();
	_pc = getActionField(_fp[_fp[FP_ARGS_SIZE] + FP_ARGS], A_CODE);
}

void VM::opSVAR() {
	_stack.top() = getVariable(readCodeByte());
}

void VM::opSSET() {
	setVariable(readCodeByte(), _stack.top());
}

void VM::opSPLIT() {
	_stack.top() = readCodeByte();
}

void VM::opSNLIT() {
	_stack.top() = readCodeByte();
}

void VM::opYORN() {
	Common::String line = getLine();
	_stack.top() = line[0] == 'Y' || line[0] == 'y' ? TRUE : NIL;
}

void VM::opSAVE() {
	if (saveGame().getCode() != Common::kNoError)
		print("Sorry, the savegame couldn't be created");
}

void VM::opRESTORE() {
	if (saveGame().getCode() != Common::kNoError)
		print("Sorry, the savegame couldn't be restored");
}

void VM::opARG() {
	int argNum = readCodeByte();
	int varsSize = _stack[_fp - 3];
	if (argNum >= varsSize)
		error("Invalid argument number");
	_stack.top() = _stack[_fp - 4 - argNum];
}

void VM::opASET() {
	int argNum = readCodeByte();
	int varsSize = _stack[_fp - 3];
	if (argNum >= varsSize)
		error("Invalid argument number");
	_stack[_fp - 4 - argNum] = _stack.top();
}

void VM::opTMP() {
	int val = readCodeByte();
	_stack.top() = _fp[-val - 1];
}

void VM::opTSET() {
	int val = readCodeByte();
	_fp[-val - 1] = _stack.top();
}

void VM::opTSPACE() {
	_stack.allocate(readCodeByte());
}

void VM::opCLASS() {
	_stack.top() = getObjectField(_stack.top(), O_CLASS);
}

void VM::opMATCH() {
	int idx = _stack.pop() - 1;
	_stack.top() = match(_stack.top(), _nouns[idx], _adjectives[idx]) ? TRUE : NIL;
}

void VM::opPNOUN() {
	int noun = _stack.top();
	Common::String str;

	// Add the adjectives
	bool space = false;
	for (int *aPtr = _adjectives[noun - 1]; *aPtr; ++aPtr, space = true) {
		if (space)
			str += " ";
		str += _wordText[_adjectiveWords[aPtr - _adjectiveLists]];
	}

	// Add the noun
	if (space)
		str += " ";
	str += _wordText[_nounWords[noun - 1]];

	print(str);
}

void VM::opRESTART() {
	restart();
}

void VM::opRAND() {
	_stack.top() = getRandomNumber(_stack.top());
}

void VM::opRNDMIZE() {
	// No implementation
}

void VM::opSEND() {
	int argsSize = readCodeByte();
	_stack.push(argsSize);
	_stack.push(_pc);
	_stack.push(_fp);
	_fp.set();

	int val = _fp[_fp[FP_ARGS_SIZE] + FP_ARGS];
	if (val)
		val = getObjectField(val, O_CLASS);
	else
		val = _fp[_fp[FP_ARGS_SIZE] + FP_ARGS];

	if (val && (val = getObjectProperty(val, _fp[_fp[FP_ARGS_SIZE] + 1])) != 0) {
		_pc = getActionField(val, A_CODE);
	} else {
		// Return NIL if there's no action for the given message
		opRETURN();
	}
}

void VM::opVOWEL() {
	// No implementation
}

} // End of namespace AdvSys
} // End of namespace Glk