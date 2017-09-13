#include "Grocer.h"

bool Grocer::HandleMessage(const Telegram& msg)
{
	return m_pStateMachine->HandleMessage(msg);
}


void Grocer::Update()
{
	SetTextColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);


	m_pStateMachine->Update();
}

bool Grocer::ShelveStocked()const
{
	if (m_iGoodsInStock >= StockLimit) { return true; }

	return false;
}

bool Grocer::Stressed()const
{
	if (m_iStressLevel > StressLimit) { return true; }

	return false;
}
