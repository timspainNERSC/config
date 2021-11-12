INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})
add_executable(configurator
    "main.cpp"
#    "Configured.cpp" # Configured is currently header only
    "Configurator.cpp"
    "Config.cpp"
    "Derived.cpp"
    "CommandoLion.cpp"
    )

target_link_libraries(configurator LINK_PUBLIC ${Boost_LIBRARIES})