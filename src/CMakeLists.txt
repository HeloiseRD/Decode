cmake_minimum_required (VERSION 2.8) 

set(YI_PROJECT_NAME DecodeApp)
project (${YI_PROJECT_NAME}) 

set(YI_REL_SRC_DIR .)
set (YI_SRC_FILES
    ${YI_REL_SRC_DIR}/DecodeApp.cpp
    ${YI_REL_SRC_DIR}/DecodeAppFactory.cpp
    ${YI_REL_SRC_DIR}/ScreenViewController1.cpp
    ${YI_REL_SRC_DIR}/ScreenViewController2.cpp
)

set(YI_REL_PATH_TO_ROOT ../youi_engine_decode_master)
include(${YI_REL_PATH_TO_ROOT}/AppCommon/build/AppCommon.cmake)

YiAddAllUswishLibraries("INCLUDE_HEADERS_AND_LINK")
YiAddAllThirdpartyLibraries("LINK_ONLY")
# AppCommon/mainDefault.cpp needs the following:
YiAddLibrary("YI_LIB_DEP_GLFW" "INCLUDE_HEADERS_ONLY")
