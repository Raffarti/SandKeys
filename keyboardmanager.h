#ifndef KEYBOARDMANAGER_H
#define KEYBOARDMANAGER_H

#include <QObject>
#include <QWidget>
#include <QHash>
#include <QString>
#include <QAbstractButton>

class KeyboardManager : public QObject
{
    Q_OBJECT
public:
    KeyboardManager(QWidget *keyboard);
private:
    QHash<int,QAbstractButton*> map;
    int modifier = 0;
    bool keepPress;
    QAbstractButton *keepDownBtn;

private slots:
    void keyPressed();
    void keepDown(bool pressed);
public slots:
    void rewriteKeys();

};

#endif // KEYBOARDMANAGER_H
