#include "MinersWifeOwnedStates.h"
#include "GrocerOwnedStates.h"
#include "Grocer.h"
#include "Locations.h"
#include "Time/CrudeTimer.h"
#include "MessageDispatcher.h"
#include "MessageTypes.h"
#include "EntityNames.h"

#include <iostream>
using std::cout;

#ifdef TEXTOUTPUT
#include <fstream>
extern std::ofstream os;
#define cout os
#endif


//-----------------------------------------------------------------------Global state

GrocersGlobalState* GrocersGlobalState::Instance()
{
	static GrocersGlobalState instance;

	return &instance;
}

void GrocersGlobalState::Execute(Grocer* grocer)
{
}


bool GrocersGlobalState::OnMessage(Grocer* grocer, const Telegram& msg)
{
	SetTextColor(BACKGROUND_RED | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

	switch (msg.Msg)
	{
	case Msg_GroceryShopping:
	{
		cout << "\nMessage handled by " << GetNameOfEntity(grocer->ID()) << " at time: "
			<< Clock->GetCurrentTime();

		SetTextColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);

		cout << "\n" << GetNameOfEntity(grocer->ID()) <<
			": Hi Elsa! Cooking another stew today!";

		cout << "\n" << GetNameOfEntity(grocer->ID()) <<
			": I'll get your groceries ready.";

		//send message to elsa to let her know that her groceries are ready. Elsa
		// then walks home.

		grocer->GetFSM()->ChangeState(StandAtCounter::Instance());

		Dispatch->DispatchMessage(SEND_MSG_IMMEDIATELY,                  //time delay
			grocer->ID(),           //sender ID
			ent_Elsa,           //receiver ID
			Msg_GroceriesRecieved,        //msg
			NO_ADDITIONAL_INFO);

		//SetTextColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);

		break;

	}

	case Msg_CigarShopping:
	{
		SetTextColor(BACKGROUND_RED | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

		cout << "\nMessage handled by " << GetNameOfEntity(grocer->ID()) << " at time: "
			<< Clock->GetCurrentTime();

		SetTextColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);

		cout << "\n" << GetNameOfEntity(grocer->ID()) <<
			": Hi Bob! Looking for some cheap cigars?";

		cout << "\n" << GetNameOfEntity(grocer->ID()) <<
			": I've got you covered.";

		//send message to bob to let him know that his cigars are ready. Bob
		// then walks home.

		grocer->GetFSM()->ChangeState(StandAtCounter::Instance());

		Dispatch->DispatchMessage(SEND_MSG_IMMEDIATELY,                  //time delay
			grocer->ID(),           //sender ID
			ent_Miner_Bob,           //receiver ID
			Msg_CigarsRecieved,        //msg
			NO_ADDITIONAL_INFO);

	}

	return true;

	}//end switch

	return false;
}

//----------------------------------------------------------methods for EnterMineAndDigForNugget
StandAtCounter* StandAtCounter::Instance()
{
	static StandAtCounter instance;

	return &instance;

}

void StandAtCounter::Enter(Grocer* grocer)
{
	//if the miner is not already located at the goldmine, he must
	//change location to the gold mine	
	if (grocer->Location() != generalstore)
	{
		cout << "\n " << GetNameOfEntity(grocer->ID()) << ":  " << "Suppose i should"
			<< " get back to tendin store";

		grocer->ChangeLocation(generalstore);
	}
}

void StandAtCounter::Execute(Grocer* grocer)
{
	//Now the grocer is running his store. He will serve customers
	// and package their groceries for them (as self serving grocery stores
	// did not exist yet), When his stress level becomes high enough, He will
	//then close his store for a while, go onto the front porch and chew
	// tobacco. He will reopen his store once he is done chewing. 
	
	//If he runs low on groceries, he will restock them.

	grocer->IncreaseStress();
	
	grocer->DecreaseShelfStock();

	cout << "\n" << GetNameOfEntity(grocer->ID()) << ": " << "Another customer served ";

	if (!grocer->ShelveStocked())
	{
		cout << "\n" << GetNameOfEntity(grocer->ID()) << ": " << "Shelves are empty. Guess I better restock.";

		grocer->RestockShelves();

		cout << "\n" << GetNameOfEntity(grocer->ID()) << ": " << "Shelves are Restocked";

		//After restocking, grocer will go for a chewing tobacco break
		// if he is stressed
		
		if (grocer->Stressed()) 
		{
			grocer->GetFSM()->ChangeState(ChewTobacco::Instance());

		}
	}
}
void StandAtCounter::Exit(Grocer* grocer)
{


	cout << "\n" << GetNameOfEntity(grocer->ID()) << ": " << "I'm feeling wear'y . Time for some chew ";


}

bool StandAtCounter::OnMessage(Grocer* grocer, const Telegram& msg)
{
	return false;
}

//---------------------------------------ChewTobacco

ChewTobacco* ChewTobacco::Instance()
{
	static ChewTobacco instance;

	return &instance;

}

void ChewTobacco::Enter(Grocer* grocer)
{

	grocer->ChangeLocation(storeporch);

}

void ChewTobacco::Execute(Grocer* grocer)
{
	//The grocer will keep chewing tobacco until his stress has decreased completley
	
	if (!grocer->Stressed())
	{
		cout << "\n " << GetNameOfEntity(grocer->ID()) << ": " << "*That there was some "
			<< "good chew";

		grocer->GetFSM()->ChangeState(StandAtCounter::Instance());
	}
	else
	{
		//keep chewing tobacco
		grocer->DecreaseStress();

		cout << "\n " << GetNameOfEntity(grocer->ID()) << ": " << "*chew chew chew....";
	}
}
void ChewTobacco::Exit(Grocer* grocer)
{
}

bool ChewTobacco::ChewTobacco::OnMessage(Grocer* grocer, const Telegram& msg)
{
	//send msg to global message handler
	return false;
}
