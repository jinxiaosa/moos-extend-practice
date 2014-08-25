/************************************************************/
/*    NAME: RUI                                              */
/*    ORGN: MIT                                             */
/*    FILE: Yrfirst.cpp                                        */
/*    DATE:                                                 */
/************************************************************/

#include <iterator>
#include "MBUtils.h"
#include "Yrfirst.h"
#include "math.h"
using namespace std;

//---------------------------------------------------------
// Constructor

Yrfirst::Yrfirst()
{
  m_iterations = 0;
  m_timewarp   = 1;
  //Rui add the initial variable for the program
  m_first_reading=true;;
  m_current_x  = 0;
  m_current_y  = 0;
  m_previous_x = 0;
  m_previous_y = 0;
  m_total_distance = 0;
  //x_pos=0;
  // y_pos=0;
  cout<< "YR done the initialization"<<endl;
}

//---------------------------------------------------------
// Destructor

Yrfirst::~Yrfirst()
{
}

//---------------------------------------------------------
// Procedure: OnNewMail

bool Yrfirst::OnNewMail(MOOSMSG_LIST &NewMail)
{
  MOOSMSG_LIST::iterator p;
   
  for(p=NewMail.begin(); p!=NewMail.end(); p++) {
    CMOOSMsg &msg = *p;
    string key = msg.GetKey();
        if (key == "NAV_X")
	  {
	    m_previous_x = m_current_x;
	    m_current_x =msg.GetDouble();
	  }
	else if (key == "NAV_Y")
	  {
	    m_previous_y = m_current_y;
	    m_current_y =msg.GetDouble();
	  }
    //  cout<<'X position is'<<msg.GetDouble()<<endl;
#if 0 // Keep these around just for template
    string key   = msg.GetKey();
    string comm  = msg.GetCommunity();
    double dval  = msg.GetDouble();
    string sval  = msg.GetString(); 
    string msrc  = msg.GetSource();
    double mtime = msg.GetTime();
    bool   mdbl  = msg.IsDouble();
    bool   mstr  = msg.IsString();
#endif
   }
	
   return(true);
}

//---------------------------------------------------------
// Procedure: OnConnectToServer

bool Yrfirst::OnConnectToServer()
{
   // register for variables here
   // possibly look at the mission file?
   // m_MissionReader.GetConfigurationParam("Name", <string>);
   // m_Comms.Register("VARNAME", 0);
	
   RegisterVariables();
   return(true);
}

//---------------------------------------------------------
// Procedure: Iterate()
//            happens AppTick times per second

bool Yrfirst::Iterate()
{
  m_iterations++;
  double tempx,tempy,inc_dist;
  tempx=(m_current_x-m_previous_x);
  tempy=(m_current_y-m_previous_y);
  inc_dist= sqrt(tempx*tempx)+tempy*tempy); //tempx+tempy;//
  m_total_distance += inc_dist;//sqrt(pow(m_current_x-m_previous_x,m_current_x-m_previous_x)+pow(m_current_y-m_previous_y,m_current_y-m_previous_y));

  m_Comms.Notify("Yrfirst_DIST", m_total_distance);
  return(true);
}

//---------------------------------------------------------
// Procedure: OnStartUp()
//            happens before connection is open

bool Yrfirst::OnStartUp()
{
  list<string> sParams;
  m_MissionReader.EnableVerbatimQuoting(false);
  if(m_MissionReader.GetConfiguration(GetAppName(), sParams)) {
    list<string>::iterator p;
    for(p=sParams.begin(); p!=sParams.end(); p++) {
      string original_line = *p;
      string param = stripBlankEnds(toupper(biteString(*p, '=')));
      string value = stripBlankEnds(*p);
      
      if(param == "FOO") {
        //handled
      }
      else if(param == "BAR") {
        //handled
      }
    }
  }
  
  m_timewarp = GetMOOSTimeWarp();

  RegisterVariables();	
  return(true);
}

//---------------------------------------------------------
// Procedure: RegisterVariables

void Yrfirst::RegisterVariables()
{//YR find that we need to lisen to two variable
   m_Comms.Register("NAV_X", 0);
   //SO I FIND THIS 0 PARAMETER REALLY MATTERS FOR THE DISTANCE MEASUREMENT
   m_Comms.Register("NAV_Y", 0);

}

