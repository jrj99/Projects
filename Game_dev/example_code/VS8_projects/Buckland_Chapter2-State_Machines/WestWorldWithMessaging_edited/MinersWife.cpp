#include "MinersWife.h"

bool MinersWife::HandleMessage(const Telegram& msg)
{
  return m_pStateMachine->HandleMessage(msg);
}


void MinersWife::Update()
{
  //set text color to green
  SetTextColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
 
  m_pStateMachine->Update();
}

bool MinersWife::PantryEmpty()const
{
	if (m_iPantryLevel == 0) { return true; }

	return false;

}