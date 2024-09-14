#ifndef GLOBALS_H
#define GLOBALS_H
#include <QString>
#include <QDir>
#include "src/helper/filehelper.h"


namespace GLOBAL {
    namespace PATH {
        static const QString WORK = QDir::currentPath();
        static const QString TMP = FileHelper::joinPath(WORK, "temp");
        static const QString LOG_DIR = FileHelper::joinPath(QDir::tempPath(), "qos/logs");
        static const QString ERROR_CODE_PATH = ":/static/docs/errorcode.csv";

        static const QString LOGO_PATH = ":/static/imgs/logo.png";
        static const QString MAX_PATH= ":/static/imgs/Maximize-1.png";
        static const QString MAX_HOVER_PATH = ":/static/imgs/Maximize-2.png";
        static const QString NORMAL_PATH = ":/static/imgs/Maximize-3.png";
        static const QString NORMAL_HOVER_PATH = ":/static/imgs/Maximize-4.png";
        static const QString MIN_PATH = ":/static/imgs/Minimize-1.png";
        static const QString MIN_HOVER_PATH = ":/static/imgs/Minimize-2.png";

        static const QString QUIT = ":/static/imgs/Quit-1.png";
        static const QString QUIT_HOVER = ":/static/imgs/Quit-2.png";
        static const QString TRANS = ":/static/imgs/Trans-1.png";
        static const QString TRANS_HOVER = ":/static/imgs/Trans-2.png";

        static const QString BUCKET = ":/static/imgs/bucket.png";
        static const QString FILE = ":/static/imgs/file.png";
        static const QString DIR = ":/static/imgs/dir.png";
    };

    namespace SQLITE {
        static const QString NAME = FileHelper::joinPath(PATH::TMP, "cos.db");
    };

    namespace SQL {
        static const QString LOGIN_INFO_TABLE = ":/static/sql/login_info.sql";
    };

    namespace TABLES {
        static const QString LOGIN_INFO = "login_info";
    };

    namespace VERSION {
        static const QString MAJOR_CUSTOM = "custom";
        static const QString MAJOR_BUSINESS = "business";
        static const QString JSON_PATH = ":/static/versions/config_default.json";
    };

    namespace ENV {
        static const QString ENV_DEV= "dev";
        static const QString ENV_ALPHA = "alpha";
        static const QString ENV_BETA = "beta";
        static const QString ENV_PRE = "pre";
        static const QString ENV_PROD = "prod";
    }

    enum LOG_LEVEL {
        TOTAL = 0,
        DEBUG = 1,
        INFO = 2,
        WARNING = 3,
        ERROR = 4,
        FATAL = 5
    };
    static const QStringList LOG_NAMES
        = QStringList() << "TOTAL" << "DEBUG" << "INFO"
                        << "WARNING" << "ERROR" << "FATAL";
}

#endif // GLOBALS_H
