set(state_source_files
  State.h
  State.cpp
  InitialState.h
  InitialState.cpp
  EmergencyState.cpp
  EmergencyState.h
  IdleState.h
  IdleState.cpp
  MaintenanceState.h
  MaintenanceState.cpp
  MovingState.h
  MovingState.cpp
  AllStates.h
  FSM.h
  FSM.cpp

)

add_library(States ${state_source_files})
target_include_directories(States PUBLIC ${CMAKE_CURRENT_LIST_DIR}/..)
target_link_libraries(States PUBLIC Elevator)
