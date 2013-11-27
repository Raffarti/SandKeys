#include <QApplication>
#include <QDeclarativeContext>
#include "qmlapplicationviewer.h"

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QScopedPointer<QApplication> app(createApplication(argc, argv));

    QmlApplicationViewer viewer;
    viewer.addImportPath(QLatin1String("modules"));
    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    viewer.setMainQmlFile(QLatin1String("/usr/share/SandKeys/Qt4Loader/Wrapper.qml"));
    viewer.setAttribute(Qt::WA_X11DoNotAcceptFocus);
    viewer.setWindowFlags(Qt::WindowStaysOnTopHint|Qt::X11BypassWindowManagerHint);
    QDeclarativeContext *context = viewer.rootContext();
    context->setContextProperty("viewerWidget", &viewer);
    viewer.showExpanded();
    return app->exec();
}
