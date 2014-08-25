#--------------------------------------------------------
# The CMakeLists.txt for:                       ls-h
# Author(s):                              
#--------------------------------------------------------

# FILE(GLOB SRC *.cpp)

SET(SRC
  -h.cpp
  -h_Info.cpp
  main.cpp
)



ADD_EXECUTABLE(ls-h ${SRC})

TARGET_LINK_LIBRARIES(ls-h
   ${MOOS_LIBRARIES}
   mbutil
   m
   pthread)

