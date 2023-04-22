#include "mypushbutton.h"
#include<QDebug>
#include<QPropertyAnimation>
MyPushButton::MyPushButton(QWidget *parent)
    : QPushButton{parent}
{

}

MyPushButton::MyPushButton(QString normalImg, QString pressImg)
{
    //成员变量normalImgPath保存正常显示图片路径
    normalImgPath = normalImg;
    //保存按下图片的路径
    pressImgPath = pressImg;

    //创建QPixmap对象
    QPixmap pixmap;
    //判断是否能正常加载正常显示的图片，若不能提示加载失败
    bool ret = pixmap.load(normalImgPath);
    if(!ret)
    {
        qDebug() << normalImg << "加载图片失败!";
    }

    //设置图片的固定尺寸
    this->setFixedSize(pixmap.width(), pixmap.height());

    //设置不规则图片的样式表
    this->setStyleSheet("QPushButton{border:0px;}");
    //设置图标
    this->setIcon(pixmap);
    //设置图标大小
    this->setIconSize(QSize(pixmap.width(), pixmap.height()));
}

//实现按下效果特效
void MyPushButton::zoom1()
{
    //创建动画对象
    QPropertyAnimation * animation1 = new QPropertyAnimation(this, "geometry");

    //设置时间间隔 单位毫秒
    animation1->setDuration(200);

    //创建起始位置
    animation1->setStartValue(QRect(this->x(), this->y(), this->width(), this->height()));

    //创建结束位置
    animation1->setEndValue(QRect(this->x(), this->y()+10, this->width(), this->height()));

    //设置缓和曲线，QEasingCurve::OutBounce 为弹跳效果
    animation1->setEasingCurve(QEasingCurve::OutBounce);

    //开始执行动画
    animation1->start();


    //弹跳完再回去
    QPropertyAnimation * animation2 = new QPropertyAnimation(this, "geomerty");
    animation2->setDuration(200);

    //开始
    animation2->setStartValue(QRect(this->x(), this->y()+10, this->width(), this->height()));
    //结束
    animation2->setEndValue(QRect(this->x(), this->y(), this->width(), this->height()));

    animation2->setEasingCurve(QEasingCurve::OutBounce);

    //执行
    animation2->start();
}

void MyPushButton::zoom2()
{
    //弹跳完再回去
    QPropertyAnimation * animation1 = new QPropertyAnimation(this, "geomerty");
    animation1->setDuration(200);

    //开始
    animation1->setStartValue(QRect(this->x(), this->y()+10, this->width(), this->height()+10));
    //结束
    animation1->setEndValue(QRect(this->x(), this->y(), this->width(), this->height()));

    animation1->setEasingCurve(QEasingCurve::OutBounce);

    //执行
    animation1->start();
}

//重写返回按钮的两种状态的监听 按下和释放
void MyPushButton::mousePressEvent(QMouseEvent *e)
{
    if(pressImgPath != "") //选中路径不为空 显示选中图片
    {
        QPixmap pixmap;
        bool ret = pixmap.load(pressImgPath);

        if(!ret)
        {
            qDebug() << "加载图片失败";
        }

        //加载成功
        this->setFixedSize(pixmap.width(), pixmap.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pixmap);
        this->setIconSize(QSize(pixmap.width(), pixmap.height()));
    }
    //交给父类执行按下事件
    return QPushButton::mousePressEvent(e);
}


void MyPushButton::mouseReleaseEvent(QMouseEvent *e)
{
    if(pressImgPath != "") //选中路径不为空 显示选中图片
    {
        QPixmap pixmap;
        bool ret = pixmap.load(normalImgPath);

        if(!ret)
        {
            qDebug() << normalImgPath << "加载图片失败";
        }

        //加载成功
        this->setFixedSize(pixmap.width(), pixmap.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pixmap);
        this->setIconSize(QSize(pixmap.width(), pixmap.height()));
    }
    //交给父类执行按下事件
    return QPushButton::mouseReleaseEvent(e);
}







//
//
//
//
//
//
















