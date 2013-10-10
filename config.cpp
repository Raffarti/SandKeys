#include "config.h"
#include <QProcessEnvironment>
#include <QCoreApplication>
#include <QFile>
#include <QFileInfo>
#include <QDir>
#include <QDebug>

Config *Config::config = 0;

Config *Config::getCurrentConfig()
{
    if (config == 0){
        config = new Config();
        config->load();
    }
    return config;
}

Config::Config()
{

}

void Config::load(QString filePath)
{
    QFile *file = new QFile(filePath);
    if (filePath == "" || !file->exists()){
        QStringList fList;
        fList.append(QProcessEnvironment::systemEnvironment().value("SANDKEYS_CONFIG_FILE"));
        fList.append("sandkeys.conf");
        fList.append(QCoreApplication::instance()->applicationDirPath() + "/sendkeys.conf");
        fList.append(QDir::home().path() + "/.config/SendKeys/sendkeys.conf");
        fList.append(QDir::home().path() + "/.local/share/SendKeys/sendkeys.conf");
        for (QStringList::Iterator s = fList.begin(); s != fList.end() && !(file->exists() || file->isReadable()); s++){
            qDebug() << "Check on " << QFileInfo(*file).absoluteFilePath() << "failed.";
            file = new QFile(*s);
            qDebug() << "Attempting to check" << QFileInfo(*file).absoluteFilePath();
        }
    }
    if (!(file->exists() || file->isReadable())){
        qDebug() << "No readable config file found, fall back to defaults.";
        return;
    }


}
