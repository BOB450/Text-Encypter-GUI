#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QMessageBox>
#include <QLineEdit>
#include <QPlainTextEdit>
#include <QWidget>
#include <QString>
#include<string>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
QString plaintextvalue = ui->textEdit->toPlainText();
QMessageBox msgBox;
msgBox.setText(plaintextvalue);
msgBox.exec();
}


void MainWindow::on_pushButton_2_clicked()
{

}


void MainWindow::on_textEdit_textChanged()
{
    QString plaintextvalue = ui->textEdit->toPlainText();
    QString Qkey = ui->lineEdit->displayText();
    int key = Qkey.toInt();
    std::string str = plaintextvalue.toStdString();
    //const  char* text1 = str.c_str();
   //char* text = (char *)text1;
    reverse(str.begin(), str.end());
    QString qstr = QString::fromStdString(str);

    ui->textEdit_2->setPlainText(qstr);

}


void MainWindow::on_textEdit_2_textChanged()
{

}

