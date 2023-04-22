#ifndef CHOOSELEVELSCENE_H
#define CHOOSELEVELSCENE_H

#include "playscene.h"

#include <QMainWindow>

class ChooseLevelScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit ChooseLevelScene(QWidget *parent = nullptr);

    //背景设置
    void paintEvent(QPaintEvent *);

    //声明关卡
    PlayScene *pScene = NULL;

signals:
    //写一个自定义信号，告诉主场景点击了返回
    void chooseSceneBack();
};

#endif // CHOOSELEVELSCENE_H
