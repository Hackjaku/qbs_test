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
#include <QtCore/QStandardPaths>
#include <QtCore/QDir>
#include <QtCore/QFile>
#include <QtWidgets/QFileDialog>
#include <QtGui/QImageWriter>
#include <QtWidgets/QSpinBox>
#include <QtCore/QTimer>

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
    QSpinBox *delaySpinBox;
};

#endif // UTILS_H