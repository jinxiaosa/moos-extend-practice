/************************************************************/
/*    NAME: RUI                                              */
/*    ORGN: MIT                                             */
/*    FILE: Yrfirst.h                                          */
/*    DATE:                                                 */
/************************************************************/

#ifndef Yrfirst_HEADER
#define Yrfirst_HEADER

#include "MOOS/libMOOS/MOOSLib.h"

class Yrfirst : public CMOOSApp
{
 public:
   Yrfirst();
   ~Yrfirst();
   bool   m_first_reading;
   double m_current_x;
   double m_current_y;
   double m_previous_x;
   double m_previous_y;
   double m_total_distance;
 protected:
   bool OnNewMail(MOOSMSG_LIST &NewMail);
   bool Iterate();
   bool OnConnectToServer();
   bool OnStartUp();
   void RegisterVariables();

 private: // Configuration variables

 private: // State variables
   unsigned int m_iterations;
   double       m_timewarp;
};

#endif 
