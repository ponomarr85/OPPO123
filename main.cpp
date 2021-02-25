#include "auth_dialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AuthDialog authDialog;
    authDialog.show();
    a.exec();
    return 0;
}
