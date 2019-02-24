#ifndef RECT_H
#define RECT_H

#include <QWidget>

class Rect : public QWidget
{
    Q_OBJECT
bool IsDrawing=false;
QPoint First;
QPoint Sec;
QVector<QRect> rVect;
public:
    Rect(QWidget *parent = 0);
    ~Rect();

    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
};

#endif // RECT_H
