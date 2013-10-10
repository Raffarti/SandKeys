#ifndef CONFIG_H
#define CONFIG_H

#include <QString>

class Config
{
public:
    static Config *getCurrentConfig();
    Config();
private:
    void load(QString filePath = "");
    static Config *config;


};

#endif // CONFIG_H
