#ifndef GROCER_H
#define GROCER_H

//------------------------------------------------------------------------
//
//  Name:   Grocer.h
//
//  Desc:   Contains variables and accessors that enables
//			"rocerOwnedStates" to function properly.
//
//  Author: Jared Jones  2017 (jared.randall.jones@gmail.com)
//
//------------------------------------------------------------------------


#include <string>

#include "fsm/State.h"
#include "BaseGameEntity.h"
#include "Locations.h"
#include "GrocerOwnedStates.h"
#include "misc/ConsoleUtils.h"
#include "Miner.h"
#include "fsm/StateMachine.h"
#include "misc/Utils.h"

//if stress rises above this value, the grocer must chew tobacco
const int StressLimit = 6;
//if nubmer of goods in the store fall below this level, the store 
//must be restocked
const int StockLimit = 1;


class Grocer : public BaseGameEntity
{
private:
	//an instance of the state machine class
	StateMachine<Grocer>*  m_pStateMachine;

	location_type         m_Location;

	//how many goods are in stock

	int				m_iGoodsInStock;

	//the higher the value, the more stressed the grocer

	int				m_iStressLevel;

public:

	Grocer(int id) :m_Location(storeporch),
								m_iGoodsInStock(5),
								m_iStressLevel(0),
								BaseGameEntity(id)

	{
		//set up state machine
		m_pStateMachine = new StateMachine<Grocer>(this);

		m_pStateMachine->SetCurrentState(ChewTobacco::Instance());

		m_pStateMachine->SetGlobalState(GrocersGlobalState::Instance());

		/* NOTE, A GLOBAL STATE HAS NOT BEEN IMPLEMENTED FOR THE MINER */
	}

	~Grocer() { delete m_pStateMachine; }

	//this must be implemented
	void Update();

	//so must this
	virtual bool  HandleMessage(const Telegram& msg);

	StateMachine<Grocer>* GetFSM()const { return m_pStateMachine; }

	//-------------------------------------------------------------accessors
	location_type Location()const { return m_Location; }
	void          ChangeLocation(location_type loc) { m_Location = loc; }

	bool		Stressed()const;
	void		DecreaseStress() { m_iStressLevel -= 2; }
	void		IncreaseStress() { m_iStressLevel += 1; }

	bool		ShelveStocked()const;
	void		DecreaseShelfStock() { m_iGoodsInStock -= 1; }
	void		RestockShelves() { m_iGoodsInStock = 5; }

};

#endif