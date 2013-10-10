#include "keyboard.h"
#include <QApplication>
#include "config.h"
#include <QWidget>
#include "ui_DefaultKeyboard.h"
#include "keyboardmanager.h"
//#include "XKBGeometryLoader/layoutbuilder.h" incomplete

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Keyboard w;
    
    //LayoutBuilder(new QFile("/usr/share/X11/xkb/geometry/pc")); for tests
    QWidget *keyboard = new QWidget;
    Ui::Form ui;
    ui.setupUi(keyboard);


    KeyboardManager km(keyboard);

    w.setCentralWidget(keyboard);

  /*  foreach(QWidget *widget, a.allWidgets())
        widget->setFocusPolicy(Qt::NoFocus);
    foreach(QWindow *window, a.allWindows())
        window->set;*/
    w.setWindowFlags(Qt::WindowStaysOnTopHint);
    w.setAttribute(Qt::WA_X11DoNotAcceptFocus); //Bugged in Qt5.1.1

    w.show();
    return a.exec();
}
