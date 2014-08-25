#--------------------------------------------------------
# The CMakeLists.txt for:                       pYrfirst
# Author(s):                              RUI
#--------------------------------------------------------

# FILE(GLOB SRC *.cpp)

SET(SRC
  Yrfirst.cpp
  Yrfirst_Info.cpp
  main.cpp
)



ADD_EXECUTABLE(pYrfirst ${SRC})

TARGET_LINK_LIBRARIES(pYrfirst
   ${MOOS_LIBRARIES}
   mbutil
   m
   pthread)

