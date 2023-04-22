#include "mainscene.h"
#include "mypushbutton.h"
#include "ui_mainscene.h"
#include<QPainter>
#include<QPixmap>
#include<QTimer>
MainScene::MainScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainScene)
{
    ui->setupUi(this);

    //配置主场景

    //设置固定大小
    this->setFixedSize(320,588);
    //设置应用图片
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));
    //设置窗口标题
    this->setWindowTitle("美琴翻翻乐");

    //点击退出，退出游戏
    connect(ui->actionQuit, &QAction::triggered, [=](){
        this->close();
    });

    MyPushButton * startBtn = new MyPushButton(":/res/MenuSceneStartButton.png");
    startBtn->setParent(this);

    startBtn->move(this->width()*0.5 - startBtn->width()*0.5, this->height()*0.7);

    //添加按钮的监听事件，执行按下特效
    connect(startBtn, &MyPushButton::clicked, [=](){
        startBtn->zoom1(); //向下跳
        startBtn->zoom2(); //跳回来
        //延时0.1秒后进入选择场景
        QTimer::singleShot(100, this, [=](){
            this->hide();
            chooseScene->setGeometry(this->geometry());
            chooseScene->show();
        });
    });

    //监听选择场景的返回按钮
    connect(chooseScene, &ChooseLevelScene::chooseSceneBack, [=](){
        chooseScene->setGeometry(this->geometry());
        this->show();
    });

}

MainScene::~MainScene()
{
    delete ui;
}

void MainScene::paintEvent(QPaintEvent *)
{
    //创建画家，指定画图设备
    QPainter painter(this);
    //创建Pixmap对象
    QPixmap pix;
    //加载图片
    pix.load(":/res/PlayLevelSceneBg.png");
    //绘制背景图
    painter.drawPixmap(0,0,this->width(), this->height(), pix);

    //加载标题
    pix.load(":/res/Title.png");
    //缩放图片
    pix = pix.scaled(pix.width()*0.5, pix.height()*0.5);
    //绘制标题
    painter.drawPixmap(10,30,pix.width(), pix.height(), pix);
}

