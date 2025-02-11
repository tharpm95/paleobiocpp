#include <QApplication>
#include <QWidget>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Simple Qt App");
    window.resize(300, 200);
    window.show();

    return app.exec();
}