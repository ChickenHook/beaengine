set (BEA_SOURCES BeaEngine.c)

if (optBUILD_DLL)
  add_library (${BEA_TARGET} SHARED BeaEngine.c)
  set_target_properties (${BEA_TARGET} PROPERTIES COMPILE_FLAGS "-DBUILD_BEA_ENGINE_DLL") 
else ()
  add_library (${BEA_TARGET} STATIC BeaEngine.c)
  set_target_properties (${BEA_TARGET} PROPERTIES COMPILE_FLAGS "-DBEA_ENGINE_STATIC") 
endif ()

set_property(TARGET ${BEA_TARGET} PROPERTY POSITION_INDEPENDENT_CODE ON)


install(TARGETS ${BEA_TARGET}
        ARCHIVE
        DESTINATION ${CMAKE_SOURCE_DIR}/artifactsOut/${CMAKE_SYSTEM_NAME}-${CMAKE_SYSTEM_PROCESSOR}/lib/
        COMPONENT Libraries)
