/************************************************************/
/*    NAME: RUI YANG                                              */
/*    ORGN: MIT                                             */
/*    FILE: USBGPSrecorder.h                                          */
/*    DATE:                                                 */
/************************************************************/

#ifndef USBGPSrecorder_HEADER
#define USBGPSrecorder_HEADER

#include "MOOS/libMOOS/MOOSLib.h"

class USBGPSrecorder : public CMOOSApp
{
 public:
   USBGPSrecorder();
   ~USBGPSrecorder();

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
