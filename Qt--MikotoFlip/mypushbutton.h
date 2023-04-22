#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>
#include<QMouseEvent>
class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MyPushButton(QWidget *parent = nullptr);

    //normalImg 正常显示的图片
    //pressImag 按下的图片 默认为空
    MyPushButton(QString normalImg, QString pressImg = "");

    QString normalImgPath;
    QString pressImgPath;

    //扩展特效 也就是按下的效果
    void zoom1();
    void zoom2();

    //重写返回按钮的Event监听
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

signals:

};

#endif // MYPUSHBUTTON_H
