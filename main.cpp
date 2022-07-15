#include <QtWidgets/QApplication>
#include <QtWidgets/QInputDialog>
#include <QtWidgets/QMessageBox>

/*
    COMMANDS TO CREATE PROJECT AND BUILD
    qmake -project
    cd build
    qmake ..
    make
*/

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);
    QWidget window1;
    window1.resize(320, 240);
    window1.setWindowTitle(
        QApplication::translate("toplevel", "Top-level widget")
    );
    window1.show();
    return app.exec();
}