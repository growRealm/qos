#include "manplugin.h"
#include "src/bend/dao/clouds/daocloudsmock.h"
#include "src/bend/dao/configs/versioncmd.h"
#include "src/bend/dao/configs/versionjson.h"
#include "src/config/globals.h"
#include "src/middle/manglobal.h"
#include "src/bend/dao/logs/loggerqdebug.h"

#include <src/bend/dao/clouds/daocloudscos.h>
using namespace GLOBAL;


ManPlugin::ManPlugin(QObject *parent)
    : QObject{parent}
{

}

ManPlugin::~ManPlugin()
{
    delete m_clouds;
    delete m_version;
    qDebug("delete ManPlugins ");
}

void ManPlugin::installPlugins(int argc, char *argv[])
{
    // 如果输入命令行，则命令行参数优先级最高，否则直接加载配置文件中的配置信息
    VersionCmd version(argc, argv);
    if (version.isValid()){
        m_version = new VersionCmd(argc, argv);
    }
    else {
        m_version = new VersionJson(VERSION::JSON_PATH);
    }
    m_version->setVersion();

    // 安装日志插件
    mLogIns->setLogger(new LoggerQDebug());
//    mlog->setLevel(GLOBAL::LOG_LEVEL::INFO);

    // 安装云存储插件
    if (m_version->major() == VERSION::MAJOR_BUSINESS){
        m_clouds = new DaoCloudsCos();
    }
    else {
        m_clouds = new DaoCloudsMock(":/static/testing/custom.json");
    }
}

DaoClouds *ManPlugin::clouds() const
{
    return m_clouds;
}
