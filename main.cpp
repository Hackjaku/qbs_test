#include <cstdio>
#include <iostream>
#include <QCoreApplication>
#include <QTextStream>

int main() {
    QTextStream ts(stdout);
    ts << QCoreApplication::translate("hello", "Hello world\n");
    ts.flush();
    return 0;
}