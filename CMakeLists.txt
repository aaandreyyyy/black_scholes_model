cmake_minimum_required(VERSION 3.25)
project(black_scholes)

set(CMAKE_CXX_STANDARD 17)

add_executable(black_scholes main.cpp black_scholes.cpp black_scholes.h Cdf.h options_pricing_model.h options_pricing_model.cpp)
