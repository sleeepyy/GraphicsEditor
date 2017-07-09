#include "view.h"
#include "ui_view.h"
#include "common.h"
#include "Commands/open_file_command.h"

View::View(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::view)
{
    ui->setupUi(this);
}

View::~View()
{
    delete ui;
}

void View::on_button_open_clicked()
{
    auto path = QDir::homePath();
    auto file_name = QFileDialog::getOpenFileName(this, tr("打开文件"), path,
                                                        tr("image(*.png *.jpg *.bmp *.tiff);;AllFile(*)"));
    if(file_name.isEmpty()){
        QMessageBox::information(this, tr("Failed to Open this!"), tr("OK"));
        return;
    }
    qInfo() << file_name;

    auto comm = new OpenFileCommand();

}
