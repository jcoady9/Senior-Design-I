#ifndef PROJECTGUIWINDOW_H
#define PROJECTGUIWINDOW_H

#include <QMainWindow>

class QLabel;

namespace Ui {
class projectGuiWindow;
}

class projectGuiWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit projectGuiWindow(QWidget *parent = 0);
    ~projectGuiWindow();

    void selectFile();

private:
    Ui::projectGuiWindow *ui;
    QLabel *imgLabel;
};

#endif // PROJECTGUIWINDOW_H
