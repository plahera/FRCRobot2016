#ifndef MoveServos_H
#define MoveServos_H

#include "Commands/Subsystem.h"
#include "../Robot.h"
#include "WPILib.h"

class MoveServos: public Command {
public:
	MoveServos();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	//bool Open;
	std::shared_ptr<Joystick> joy;
};

#endif
