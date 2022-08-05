INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_DECISION decision)

FIND_PATH(
    DECISION_INCLUDE_DIRS
    NAMES decision/api.h
    HINTS $ENV{DECISION_DIR}/include
        ${PC_DECISION_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    DECISION_LIBRARIES
    NAMES gnuradio-decision
    HINTS $ENV{DECISION_DIR}/lib
        ${PC_DECISION_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
          )

include("${CMAKE_CURRENT_LIST_DIR}/decisionTarget.cmake")

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(DECISION DEFAULT_MSG DECISION_LIBRARIES DECISION_INCLUDE_DIRS)
MARK_AS_ADVANCED(DECISION_LIBRARIES DECISION_INCLUDE_DIRS)
