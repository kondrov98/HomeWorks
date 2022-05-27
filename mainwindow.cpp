#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    if(ui->lineEdit_a->text().toInt()==0)
    {
     float X;
     X=-(ui->lineEdit_c->text().toInt())/(ui->lineEdit_b->text().toInt());
     ui->label_x1->setText("X=");
     ui->label_x2->setText("");
     ui->label_X1->setText(QString::number(X));
     ui->label_X2->setText("");
    }
    else
    {
        float D = qPow(ui->lineEdit_b->text().toInt(),2)- 4*(ui->lineEdit_a->text().toInt())*(ui->lineEdit_c->text().toInt());
         if(D>0)
            {
            float X1,X2;
            X1=-((ui->lineEdit_b->text().toInt())+qSqrt(D))/2*(ui->lineEdit_a->text().toInt());
            X2=-((ui->lineEdit_b->text().toInt())-qSqrt(D))/2*(ui->lineEdit_a->text().toInt());
            ui->label_x1->setText("X1=");
            ui->label_x2->setText("X2=");
            ui->label_X1->setText(QString::number(X1));
            ui->label_X2->setText(QString::number(X2));
            }
          else
              {
              if(D==0)
                {
                 float X;
                 X=-(ui->lineEdit_b->text().toInt())/2*(ui->lineEdit_a->text().toInt());
                 ui->label_x1->setText("X=");
                 ui->label_x2->setText("");
                 ui->label_X1->setText(QString::number(X));
                 ui->label_X2->setText("");
                }
              else
                {
                 ui->label_x1->setText("");
                 ui->label_X1->setText("Нет корней");
                 ui->label_x2->setText("");
                 ui->label_X2->setText("");
                }
              }

    }
}






void MainWindow::on_pushButton_2_clicked()
{
 float pi = 3.1415926535;
 float Side_A = (ui->Side_A->text().toInt());
 float Side_B = (ui->Side_B->text().toInt());
 float Corner = (ui->Corner->text().toDouble());
 float Radian=Corner/180*pi;

 if(ui->Rad_Button->isChecked())
 {
     Radian=Corner;
     //ui->Side_C->setText(QString::number(qSqrt(qPow(Side_B,2)+qPow(Side_A,2)-2*Side_B*Side_A*qCos(Corner))));
 }

 ui->Side_C->setText(QString::number(qSqrt(qPow(Side_B,2)+qPow(Side_A,2)-2*Side_B*Side_A*qCos(Radian))));
}


void MainWindow::on_add_text_clicked()
{
 text=ui->Text_1->toPlainText()+ " ";
 ui->Text_2->insertPlainText(text);
 ui->Text_1->clear();
}


void MainWindow::on_replace_text_clicked()
{
 ui->Text_2->clear();
 text=ui->Text_1->toPlainText();
 ui->Text_2->insertPlainText(text);
 ui->Text_1->clear();
}


void MainWindow::on_HTML_text_clicked()
{

}

