cmake_minimum_required(VERSION 3.20)
project(OMLAS) # oh my lord and saviour
add_executable(OMLAS main.cpp) #OMLAS is the name of the executable, main.cpp is the source file
install(TARGETS OMLAS DESTINATION ~/psu/bin) #install the executable to the bin directory
