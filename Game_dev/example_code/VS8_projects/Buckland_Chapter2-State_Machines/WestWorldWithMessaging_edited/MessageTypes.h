#ifndef MESSAGE_TYPES
#define MESSAGE_TYPES

#include <string>

enum message_type
{
  Msg_HiHoneyImHome,
  Msg_StewReady,
  Msg_GroceryShopping,
  Msg_GroceriesRecieved,
  Msg_CigarShopping,
  Msg_CigarsRecieved
};


inline std::string MsgToStr(int msg)
{
  switch (msg)
  {
  case Msg_HiHoneyImHome:
    
    return "HiHoneyImHome"; 

  case Msg_StewReady:
    
    return "StewReady";

//-------------------------- Grocer messages (added by Jared Jones) ------------------------


  case Msg_GroceryShopping:
	  
	  return "GroceryShopping";

  case Msg_GroceriesRecieved:

	  return "GroceriesRecieved";

  case Msg_CigarShopping:

	  return "CigarShopping";

  case Msg_CigarsRecieved:

	  return "CigarsRecieved";

// ------------------------------End of Grocer messages   -----------------------------------

  default:

    return "Not recognized!";
  }
}

#endif