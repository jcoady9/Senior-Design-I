#include "projectguiwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    projectGuiWindow w;
    a.setApplicationDisplayName("Hello");
    w.show();

    return a.exec();
}
