#include <QtWidgets/QApplication>
#include <QtWidgets/QInputDialog>
#include <QtWidgets/QMessageBox>

#include "lib/utils.h"

/*
    COMMANDS TO CREATE PROJECT AND BUILD
    qmake -project
    cd build
    qmake ..
    make
*/

int main(int argc, char *argv[]) {

    auto utils = new Utils();
    utils->say_hello();

    QApplication app(argc, argv);
    Screenshot window1;
    window1.resize(320, 240);
    window1.setWindowTitle(
        QApplication::translate("toplevel", "Top-level widget")
    );
    window1.show();
    QApplication::beep();
    return app.exec();
}