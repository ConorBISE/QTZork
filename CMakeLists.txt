cmake_minimum_required(VERSION 3.5)

project(QTZork VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets OpenGLWidgets)

set(PROJECT_SOURCES
        main.cpp
        qtzork.cpp
        qtzork.h

        widgets/lockedcheckbox.h
        widgets/lockedcheckbox.cpp
        widgets/lockedcheckboxgrid.h
        widgets/lockedcheckboxgrid.cpp
        widgets/freezablegraphicswidget.h
        widgets/freezablegraphicswidget.cpp

        game/level.h
        game/level.cpp
        game/camera.h
        game/camera.cpp
        game/world.h
        game/world.cpp

        game/entity/base/entity.h
        game/entity/base/entity.cpp
        game/entity/base/physicsobject.h
        game/entity/base/physicsobject.cpp
        game/entity/base/sprite.h
        game/entity/base/sprite.cpp

        game/entity/player.h
        game/entity/player.cpp
        game/entity/background.h
        game/entity/background.cpp

        io/jsonobject.h
        io/jsonobject.cpp
        io/jsonparseexception.h
        io/jsonparseexception.cpp

        util/hashmap.h
        util/hashmap.cpp
        util/logging.h
        util/logging.cpp
        game/direction.h
        game/direction.cpp
    )

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(QTZork
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET QTZork APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(QTZork SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(QTZork
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(QTZork PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::OpenGLWidgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.QTZork)
endif()
set_target_properties(QTZork PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS QTZork
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(QTZork)
endif()
