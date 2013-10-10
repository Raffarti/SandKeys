#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <QMainWindow>

namespace Ui {
class Keyboard;
}

class Keyboard : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Keyboard(QWidget *parent = 0);
    ~Keyboard();
    
private:
    Ui::Keyboard *ui;
};

#endif // KEYBOARD_H
