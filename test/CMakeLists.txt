# Copyright (C) 2022 Fondazione Istituto Italiano di Tecnologia (IIT). All Rights Reserved.

include(IDJLTestHelpers)

idjl_add_catch_tests(
    TEST_SOURCES  ${CMAKE_CURRENT_SOURCE_DIR}/yavl-cpp-test.cpp
    TEST_LINK_LIBRARIES yavl-cpp yaml-cpp
    )
