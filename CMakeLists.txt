PROJECT(QBotNetworkPkg)

cmake_minimum_required(VERSION 2.8.8)

#add_subdirectory(testSuite "${CMAKE_CURRENT_BINARY_DIR}/bin/")
add_subdirectory(qBotNetwork "${CMAKE_CURRENT_BINARY_DIR}/plugins/")

#ExternalProject_Add(testSuite PREFIX testSuite)
#ExternalProject_Add(qBotNetwork PREFIX qBotNetwork)

