TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    utils/settings.cpp \
    utils/file.cpp \
    utils/exception.cpp \
    utils/timer.cpp \
    utils/graphics.cpp \
    image_list.cpp \
    utils/directory.cpp \
    renderers/texture_renderer.cpp \
    animations/fading_animation.cpp \
    screen_saver.cpp \
    renderers/clock_renderernderer.cpp \
    renderers/basic_fade_renderer.cpp \
    renderers/rectangles_renderer.cpp \
    utils/math.cpp \
    renderers/curtains_renderer.cpp \
    text.cpp \
    utils/text_utils.cpp

HEADERS += \
    utils/settings.hpp \
    utils/json.hpp \
    utils/file.hpp \
    utils/exception.hpp \
    utils/timer.hpp \
    utils/graphics.hpp \
    image_list.hpp \
    utils/directory.hpp \
    renderers/basic_fade_renderer.hpp \
    renderers/texture_renderer.hpp \
    animations/fading_animation.hpp \
    animations/animation.hpp \
    screen_saver.hpp \
    renderers/clock_renderer.hpp \
    renderers/rectangles_renderer.hpp \
    utils/math.hpp \
    renderers/curtains_renderer.hpp \
    text.hpp \
    utils/text_utils.hpp

LIBS += -lsfml-graphics -lsfml-window -lsfml-system \
        -lboost_regex -lboost_filesystem -lboost_system
