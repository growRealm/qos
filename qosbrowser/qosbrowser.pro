# SDK（third目录）所在路径为当前.pro文件所在路径的上级目录
THIRD_DIR = $$PWD/..

include(qosbrowser.pri)


SOURCES += \
    main.cpp


RESOURCES += \
    $$PWD/resource.qrc

FORMS +=

HEADERS +=

RC_ICONS += $$PWD/static/imgs/logo.ico
