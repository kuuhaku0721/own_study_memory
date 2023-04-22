#ifndef MAINSCENE_H
#define MAINSCENE_H

#include "chooselevelscene.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainScene; }
QT_END_NAMESPACE

class MainScene : public QMainWindow
{
    Q_OBJECT

public:
    MainScene(QWidget *parent = nullptr);
    ~MainScene();

    //绘制背景图片
    void paintEvent(QPaintEvent *);

    //选择关卡场景
    ChooseLevelScene * chooseScene = new ChooseLevelScene;

private:
    Ui::MainScene *ui;
};
#endif // MAINSCENE_H
