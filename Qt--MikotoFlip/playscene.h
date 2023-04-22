#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include "mycoin.h"

#include <QMainWindow>

class PlayScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit PlayScene(QWidget *parent = nullptr);

    //重载构造
    PlayScene(int index);
    //记录关卡索引
    int levelIndex;

    //重写paintEvent事件
    void paintEvent(QPaintEvent *);

    //二维数组数据
    int gameArray[4][4];

    //反转周围金币
    MyCoin * coinBtn[4][4];

    //是否胜利
    bool isWin = true;


signals:
    void chooseSceneBack();
};

#endif // PLAYSCENE_H
