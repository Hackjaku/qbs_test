#ifndef UTILS_H
#define UTILS_H

#include <iostream>

#include <QtWidgets/QApplication>
#include <QtWidgets/QInputDialog>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QDesktopWidget>
#include <QtWidgets/QBoxLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QPushButton>
#include <QtGui/QWindow>
#include <QtGui/QScreen>

class Utils {
public:
    void say_hello();
};

class Screenshot : public QWidget {
    Q_OBJECT
public:
    Screenshot();

protected:
    void resizeEvent(QResizeEvent *event) override;

private slots:
    void shootScreen();
    void saveScreenshot();
    void newScreenshot();
    void updateCheckbox();

private:
    void updateScreenshotLabel();

    QPixmap originalPixmap;

    QLabel *screenshotLabel;
    QCheckBox *hideThisWindowCheckbox;
    QPushButton *newScreenshotButton;
};

#endif // UTILS_H