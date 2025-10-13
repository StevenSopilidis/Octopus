add_library(octopus ./src/TaskParser.cpp)  

set_target_properties(
    octopus
    PROPERTIES OUTPUT_NAME octopus
)

target_compile_features(octopus PUBLIC cxx_std_20)

target_include_directories(octopus
    PUBLIC
      $<INSTALL_INTERFACE:include>
      $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_SOURCE_DIR}/src/include
)

target_link_libraries(octopus
    PRIVATE
        nlohmann_json::nlohmann_json
        nlohmann_json_schema_validator
)

include(GNUInstallDirs)
install(TARGETS octopus
    EXPORT octopus-targets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(
    DIRECTORY ${PROJECT_SOURCE_DIR}/include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(
    EXPORT octopus-targets
    FILE octopus-config.cmake
    NAMESPACE octopus::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmakes/octopus
)