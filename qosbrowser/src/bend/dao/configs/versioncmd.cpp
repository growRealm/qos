#include "versioncmd.h"

VersionCmd::VersionCmd(int argc, char *argv[])
{
    if (argc == 2)
    {
        QString args = argv[1];
        m_argv = args.split(".");
    }
}

void VersionCmd::setVersion()
{
    if (!isValid())
    {
        throw QString("命令行格式错误 %1").arg(m_argv.join("."));
    }

    m_major = m_argv[0];
    m_env = m_argv[1];
    m_v1 = m_argv[2].toInt();
    m_v2 = m_argv[3].toInt();
    m_v3 = m_argv[4].toInt();
}

bool VersionCmd::isValid()
{
    return m_argv.size() == 5;
}
