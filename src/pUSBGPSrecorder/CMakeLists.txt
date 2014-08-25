#--------------------------------------------------------
# The CMakeLists.txt for:                       pUSBGPSrecorder
# Author(s):                              RUI YANG
#--------------------------------------------------------

# FILE(GLOB SRC *.cpp)

SET(SRC
  USBGPSrecorder.cpp
  USBGPSrecorder_Info.cpp
  main.cpp
)



ADD_EXECUTABLE(pUSBGPSrecorder ${SRC})

TARGET_LINK_LIBRARIES(pUSBGPSrecorder
   ${MOOS_LIBRARIES}
   mbutil
   m
   pthread)

