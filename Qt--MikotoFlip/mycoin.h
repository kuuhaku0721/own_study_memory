#ifndef MYCOIN_H
#define MYCOIN_H
#include<QPushButton>
#include<QMouseEvent>
class MyCoin : public QPushButton
{
    Q_OBJECT
public:
    explicit MyCoin(QWidget *parent = nullptr);
    MyCoin(QString butImg); //代表图片路径

    int poxX; //x坐标
    int poxY; //y坐标
    bool flag; //正反标志

    void changeFlag(); //改变标志，执行反转效果
    QTimer *timer1; //正面翻反面
    QTimer *timer2; //反面翻正面
    int min = 1; //最小图片
    int max = 8; //最大图片

    //禁止中途点击
    bool isAnimation = false;

    void mousePressEvent(QMouseEvent *e);

    //是否胜利
    bool isWin = false;


signals:

};

#endif // MYCOIN_H
