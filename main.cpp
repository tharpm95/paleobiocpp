#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QTextEdit>
#include <QFile>
#include <QTextStream>

class TaxonViewer : public QWidget {
    Q_OBJECT

public:
    TaxonViewer(QWidget *parent = nullptr);

private slots:
    void loadData();

private:
    QTextEdit *dataDisplay;
};

TaxonViewer::TaxonViewer(QWidget *parent)
    : QWidget(parent), dataDisplay(new QTextEdit(this)) {
    
    QVBoxLayout *layout = new QVBoxLayout(this);
    
    QPushButton *loadButton = new QPushButton("Load Data", this);
    layout->addWidget(loadButton);
    layout->addWidget(dataDisplay);
    
    connect(loadButton, &QPushButton::clicked, this, &TaxonViewer::loadData);
    
    dataDisplay->setReadOnly(true);
    setLayout(layout);
    setWindowTitle("Taxon Data Viewer");
    resize(600, 400);
}

void TaxonViewer::loadData() {
    QFile file("taxon.tab");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        dataDisplay->setText("Failed to open the file.");
        return;
    }

    QTextStream in(&file);
    QString data = in.readAll();
    dataDisplay->setText(data);
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    
    TaxonViewer window;
    window.show();
    
    return app.exec();
}

#include "main.moc"