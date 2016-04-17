SET(CIMG_LINK_LIBRARIES)
SET(CIMG_INCLUDE_DIRS)

IF(WIN32)
    LIST(APPEND CIMG_LINK_LIBRARIES gdi32)
ENDIF(WIN32)

IF(UNIX)
    IF(APPLE)
        OPTION(USE_CARBON "Use Carbon framework" ON)
    ENDIF(APPLE)
    IF(USE_CARBON)
        # Carbon framework support
        ADD_DEFINITIONS(-Dcimg_display=3)
    ELSE(USE_CARBON)
        # X11 support
        FIND_PACKAGE(X11 REQUIRED QUIET)
        LIST(APPEND CIMG_LINK_LIBRARIES pthread ${X11_LIBRARIES})
        IF(X11_Xrandr_LIB)
            ADD_DEFINITIONS(-Dcimg_use_xrandr)
            LIST(APPEND CIMG_LINK_LIBRARIES ${X11_Xrandr_LIB})
        ENDIF(X11_Xrandr_LIB)
        IF(X11_XShm_INCLUDE_PATH)
            ADD_DEFINITIONS(-Dcimg_use_xshm)
        ENDIF(X11_XShm_INCLUDE_PATH)
    ENDIF(USE_CARBON)
ENDIF(UNIX)

# PNG support
FIND_PACKAGE(PNG QUIET)
IF(PNG_FOUND)
    OPTION(USE_PNG "Use png libraries" ON)
    IF(USE_PNG)
        ADD_DEFINITIONS(-Dcimg_use_png)
        LIST(APPEND CIMG_LINK_LIBRARIES ${PNG_LIBRARIES})
        LIST(APPEND CIMG_INCLUDE_DIRS ${PNG_INCLUDE_DIR})
    ENDIF(USE_PNG)
ENDIF(PNG_FOUND)

# JPEG support
FIND_PACKAGE(JPEG QUIET)
IF(JPEG_FOUND)
    OPTION(USE_JPEG "Use jpeg libraries" ON)
    IF(USE_JPEG)
        ADD_DEFINITIONS(-Dcimg_use_jpeg)
        LIST(APPEND CIMG_LINK_LIBRARIES ${JPEG_LIBRARIES})
        LIST(APPEND CIMG_INCLUDE_DIRS ${JPEG_INCLUDE_DIR})
    ENDIF(USE_JPEG)
ENDIF(JPEG_FOUND)

# TIFF support
FIND_PACKAGE(TIFF QUIET)
IF(TIFF_FOUND)
    OPTION(USE_TIFF "Use tiff libraries" ON)
    IF(USE_TIFF)
        ADD_DEFINITIONS(-Dcimg_use_tiff)
        LIST(APPEND CIMG_LINK_LIBRARIES ${TIFF_LIBRARIES})
        LIST(APPEND CIMG_INCLUDE_DIRS ${TIFF_INCLUDE_DIR})
    ENDIF(USE_TIFF)
ENDIF(TIFF_FOUND)

# don't let exception windows pop up
ADD_DEFINITIONS(-Dcimg_verbosity=0)