#include "rect.h"
#include <QDebug>
#include <QMouseEvent>
//#include <QDesktopWidget>
#include <QPainter>

Rect::Rect(QWidget *parent)
    : QWidget(parent)
{
    //QPoint
}

Rect::~Rect()
{

}

void Rect::mousePressEvent(QMouseEvent *event)
{
    QPoint currPos=QWidget::mapFromGlobal(QCursor::pos());
    qDebug()<<"mouse press event";
    if (event->button()==Qt::LeftButton)
    {
        this->IsDrawing=true;
        this->First=currPos;
    }
}

void Rect::mouseReleaseEvent(QMouseEvent *event)
{
    QPoint currPos=QWidget::mapFromGlobal(QCursor::pos());
    this->IsDrawing=false;
    this->Sec=currPos;
    this->rVect.push_back(QRect(this->First, this->Sec));
}

void Rect::mouseMoveEvent(QMouseEvent *event)
{
    if (IsDrawing)
    {
        this->repaint();
    }
}


void Rect::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setPen(QPen(QBrush(Qt::green),5));
    for (QRect r:this->rVect)
    {
        painter.drawRect(r);
    }
    if (IsDrawing)
    {
    QPoint currPos=QWidget::mapFromGlobal(QCursor::pos());
    int currWidth=currPos.x()-this->First.x();
    int currHeight=currPos.y()-this->First.y();
    painter.drawRect(this->First.x(), this->First.y(), currWidth, currHeight);
    }
}
