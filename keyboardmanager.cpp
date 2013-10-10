#include "keyboardmanager.h"
#include <QDebug>
#include <QKeySequence>
#include <X11/XKBlib.h>
#include <X11/keysym.h>

static XKeyEvent createKeyEvent(Display *display, bool press, int modifiers, int keycode)
{
   XKeyEvent event;

   Window winRoot = DefaultRootWindow(display);


   Window winFocus;
   int    revert;
   XGetInputFocus(display, &winFocus, &revert);

   event.display     = display;
   event.window      = winFocus;
   event.root        = winRoot;
   event.subwindow   = None;
   event.time        = CurrentTime;
   event.x           = 1;
   event.y           = 1;
   event.x_root      = 1;
   event.y_root      = 1;
   event.same_screen = True;
   event.keycode     = keycode;
   event.state       = modifiers;

   if(press)
      event.type = KeyPress;
   else
      event.type = KeyRelease;

   return event;
}


KeyboardManager::KeyboardManager(QWidget *keyboard)
{
    foreach(QObject *b, keyboard->children()){
        QAbstractButton *bb = dynamic_cast<QAbstractButton*>(b);
        if (bb && bb->objectName().startsWith('_')){
            int keycode = bb->objectName().mid(1).toInt();
            if (keycode > 8 && keycode < 255){
                map[keycode] = bb;
                connect(bb, SIGNAL(pressed()), this, SLOT(keyPressed()));
                connect(bb, SIGNAL(released()), this, SLOT(keyPressed()));
            }
        } else if (bb && bb->objectName() == "keepDown"){
            keepDownBtn = bb;
            connect(bb, SIGNAL(toggled(bool)), this, SLOT(keepDown(bool)));
        }
    }
    rewriteKeys();
}

void KeyboardManager::rewriteKeys()
{
   Display *display = XOpenDisplay(0);
   if(display == 0){
       qDebug() << "Cannot access X, if you are running this with sudo or kdesu, try to use the other one (or such).";
       return;
   }
   for (decltype(map)::Iterator s = map.begin(); s != map.end(); s++){
       KeySym keysym = XkbKeycodeToKeysym(display, s.key(), 0, modifier);
       (*s)->setText(XKeysymToString(keysym));
   }
   XCloseDisplay(display);

}

void KeyboardManager::keyPressed()
{
    if (keepPress) keepDownBtn->setChecked(false);
    QAbstractButton *bb = dynamic_cast<QAbstractButton*>(sender());
    if (!bb) return;
    KeyCode keycode = bb->objectName().mid(1).toShort();

    bool pressed = bb->isDown() || bb->isChecked();

    Display *display = XOpenDisplay(0);
    if(display == 0){
        qDebug() << "Cannot access X, if you are running this with sudo or kdesu, try to use the other one (or such).";
        return;
    }

    XKeyEvent event = createKeyEvent(display, pressed, modifier, keycode);
    XSendEvent(event.display, event.window, True, pressed?KeyPressMask:KeyReleaseMask, (XEvent *)&event);
    XFlush(display);
    char mods = XkbKeysymToModifiers(display,XkbKeycodeToKeysym(display,keycode,0,0));
    if (mods){
        modifier = pressed?(modifier | mods):(modifier  & ~mods);
        rewriteKeys();
    }
    XCloseDisplay(display);
    if (!keepPress && bb->isCheckable() && !bb->isChecked()) keepDown(false);

}

void KeyboardManager::keepDown(bool pressed)
{
    keepPress = pressed;
    foreach(QAbstractButton *bb, map.values()){
        if (bb->isChecked())continue;
        bb->setCheckable(pressed);
        if (pressed){
            disconnect(bb, SIGNAL(pressed()), this, SLOT(keyPressed()));
            disconnect(bb, SIGNAL(released()), this, SLOT(keyPressed()));
            connect(bb, SIGNAL(toggled(bool)), this, SLOT(keyPressed()));
        } else {
            disconnect(bb, SIGNAL(toggled(bool)), this, SLOT(keyPressed()));
            connect(bb, SIGNAL(pressed()), this, SLOT(keyPressed()));
            connect(bb, SIGNAL(released()), this, SLOT(keyPressed()));
        }
    }
}
