#ifndef GROCER_H_OWNED_STATES_H
#define GROCER_H_OWNED_STATES_H

//------------------------------------------------------------------------
//
//  Name:   GrocerOwned States.h
//
//  Desc:   Contains scripting and dialouge for a grocer character.
//
//  Author: Jared Jones  2017 (jared.randall.jones@gmail.com)
//
//------------------------------------------------------------------------


#include "fsm/State.h"

class Grocer;

//------------------------------------------------------------------------
//

//------------------------------------------------------------------------
class GrocersGlobalState : public State<Grocer>
{
private:

	GrocersGlobalState() {}

	//copy ctor and assignment should be private
	GrocersGlobalState(const GrocersGlobalState&);
	GrocersGlobalState& operator=(const GrocersGlobalState&);

public:

	//this is a singleton
	static GrocersGlobalState* Instance();

	virtual void Enter(Grocer* grocer) {}

	virtual void Execute(Grocer* grocer);

	virtual void Exit(Grocer* grocer) {}

	virtual bool OnMessage(Grocer* grocer, const Telegram& msg);
};


//------------------------------------------------------------------------
//

//------------------------------------------------------------------------

class StandAtCounter : public State<Grocer>
{
private:

	StandAtCounter() {}

	//copy ctor and assignment should be private
	StandAtCounter(const StandAtCounter&);
	StandAtCounter& operator=(const StandAtCounter&);

public:

	//this is a singleton
	static StandAtCounter* Instance();

	virtual void Enter(Grocer* grocer);

	virtual void Execute(Grocer* grocer);

	virtual void Exit(Grocer* grocer);

	virtual bool OnMessage(Grocer* grocer, const Telegram& msg);

};

class ChewTobacco : public State<Grocer>
{
private:

	ChewTobacco() {}

	//copy ctor and assignment should be private
	ChewTobacco(const ChewTobacco&);
	ChewTobacco& operator=(const ChewTobacco&);

public:

	//this is a singleton
	static ChewTobacco* Instance();

	virtual void Enter(Grocer* grocer);

	virtual void Execute(Grocer* grocer);

	virtual void Exit(Grocer* grocer);

	virtual bool OnMessage(Grocer* grocer, const Telegram& msg);

};

#endif
