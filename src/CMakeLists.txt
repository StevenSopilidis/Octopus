# Build octopus library
add_library(octopus ./src/TaskParser.cpp)
set_target_properties(octopus PROPERTIES OUTPUT_NAME octopus)
target_compile_features(octopus PUBLIC cxx_std_20)

# Include directories for your library
target_include_directories(octopus
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

# Link nlohmann_json
target_link_libraries(octopus
    PUBLIC
        nlohmann_json::nlohmann_json
)

# Build demo executable
add_executable(octopus_demo ./main.cpp)
target_link_libraries(octopus_demo
    PRIVATE octopus
)

# -------------------------------
# Installation
# -------------------------------
include(GNUInstallDirs)

install(TARGETS octopus
    EXPORT octopus-targets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(EXPORT octopus-targets
    FILE octopus-config.cmake
    NAMESPACE octopus::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/octopus
)

install(TARGETS octopus_demo
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)