#include "keyboard.h"
#include "ui_keyboard.h"

Keyboard::Keyboard(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Keyboard)
{
    ui->setupUi(this);
}

Keyboard::~Keyboard()
{
    delete ui;
}
