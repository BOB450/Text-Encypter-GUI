#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QMessageBox>
#include <QLineEdit>
#include <QPlainTextEdit>
#include <QWidget>
#include <QString>
#include<string>

QString Qkey;
std::string encryptDecrypt(std::string toEncrypt) {
    //QString Qkey = ui->lineEdit->displayText();
    std::string key1 = Qkey.toStdString();
    // convert string to upper case
    std::for_each(key1.begin(), key1.end(), [](char & c){
        c = ::toupper(c);
    });
    //char keyT[10] = {'K', 'C', 'Q'}; //Any chars will work
    if(key1.length() <= 0)
    {
        key1 = "Q";
    }
    char key[key1.length()];
    strcpy(key, key1.c_str());

    std::string output = toEncrypt;

    for (int i = 0; i < toEncrypt.size(); i++)
        output[i] = toEncrypt[i] ^ key[i % (sizeof(key) / sizeof(char))];

    return output;
}


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
    QString plaintextvalue2 = ui->textEdit_2->toPlainText();
   // QString Qkey = ui->lineEdit->displayText();
    //int key = Qkey.toInt();
    std::string str2 = plaintextvalue2.toStdString();
    //const  char* text1 = str.c_str();
   //char* text = (char *)text1;
   // reverse(str2.begin(), str2.end());
    QString qstr2 = QString::fromStdString(str2);
    std::string ans2 = encryptDecrypt(qstr2.toStdString());


    ui->textEdit->setPlainText(QString::fromStdString(ans2));
}


void MainWindow::on_textEdit_textChanged()
{
    QString plaintextvalue = ui->textEdit->toPlainText();
    //QString Qkey = ui->lineEdit->displayText();
   // int key = Qkey.toInt();
    std::string str = plaintextvalue.toStdString();
    //const  char* text1 = str.c_str();
   //char* text = (char *)text1;
   // reverse(str.begin(), str.end());
    QString qstr = QString::fromStdString(str);
    std::string ans = encryptDecrypt(qstr.toStdString());


    ui->textEdit_2->setPlainText(QString::fromStdString(ans));

}


void MainWindow::on_textEdit_2_textChanged()
{

}


void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{

  Qkey = ui->lineEdit->displayText();
}

