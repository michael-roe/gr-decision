find_package(PkgConfig)

PKG_CHECK_MODULES(PC_GR_DECISION gnuradio-decision)

FIND_PATH(
    GR_DECISION_INCLUDE_DIRS
    NAMES gnuradio/decision/api.h
    HINTS $ENV{DECISION_DIR}/include
        ${PC_DECISION_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    GR_DECISION_LIBRARIES
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

include("${CMAKE_CURRENT_LIST_DIR}/gnuradio-decisionTarget.cmake")

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(GR_DECISION DEFAULT_MSG GR_DECISION_LIBRARIES GR_DECISION_INCLUDE_DIRS)
MARK_AS_ADVANCED(GR_DECISION_LIBRARIES GR_DECISION_INCLUDE_DIRS)
