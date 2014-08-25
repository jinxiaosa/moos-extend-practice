/************************************************************/
/*    NAME:                                               */
/*    ORGN: MIT                                             */
/*    FILE: -h.h                                          */
/*    DATE:                                                 */
/************************************************************/

#ifndef -h_HEADER
#define -h_HEADER

#include "MOOS/libMOOS/MOOSLib.h"

class -h : public CMOOSApp
{
 public:
   -h();
   ~-h();

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
