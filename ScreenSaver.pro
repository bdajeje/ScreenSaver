TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    utils/settings.cpp \
    utils/file.cpp \
    utils/exception.cpp \
    utils/timer.cpp \
    image_list.cpp \
    utils/directory.cpp \
    renderers/basic_fader_enderer.cpp \
    renderers/texture_renderer.cpp

HEADERS += \
    utils/settings.hpp \
    utils/json.hpp \
    utils/file.hpp \
    utils/exception.hpp \
    utils/timer.hpp \
    image_list.hpp \
    utils/directory.hpp \
    renderers/basic_fade_renderer.hpp \
    renderers/texture_renderer.hpp

LIBS += -lsfml-graphics -lsfml-window -lsfml-system \
        -lboost_regex -lboost_filesystem -lboost_system
