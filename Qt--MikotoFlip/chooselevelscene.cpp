#include "chooselevelscene.h"
#include "mypushbutton.h"
#include<QMenuBar>
#include<QPainter>
#include<QPixmap>
#include<QTimer>
#include<QLabel>
ChooseLevelScene::ChooseLevelScene(QWidget *parent)
    : QMainWindow{parent}
{
    //设置窗口固定大小
    this->setFixedSize(320,588);

    //设置图标
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));

    //设置标题
    this->setWindowTitle("选择关卡");


    //创建菜单栏
    QMenuBar * bar = this->menuBar();
    this->setMenuBar(bar);

    //创建开始菜单
    QMenu * startMenu = bar->addMenu("开始");
    QMenu * privateMenu1 = bar->addMenu("Only");
    QMenu * privateMenu2 = bar->addMenu("My");
    QMenu * privateMenu3 = bar->addMenu("Railgun");

    //创建按钮菜单项
    QAction * quitAction = startMenu->addAction("退出");
    QAction * pM1 = privateMenu1->addAction("唯我");
    QAction * pM2 = privateMenu2->addAction("超电磁炮");
    QAction * pM3 = privateMenu3->addAction("永世长存");

    //点击退出，退出游戏
    connect(quitAction, &QAction::triggered, [=](){
        this->close();
    });

    //返回按钮
    MyPushButton * closeBtn = new MyPushButton(":/res/BackButton.png", ":/res/BackButtonSelected.png");
    closeBtn->setParent(this);

    closeBtn->move(this->width() - closeBtn->width(), this->height() - closeBtn->height());

    connect(closeBtn, &MyPushButton::clicked, [=](){
        QTimer::singleShot(300, this, [=](){
            this->hide();
            //触发自定义信号 关闭自身， 该信号写到signals下做声明
            emit this->chooseSceneBack();
        });
    });

    //创建选择关卡的按钮
    for (int i = 0; i < 20; i++) {
        MyPushButton * menuBtn = new MyPushButton(":/res/LevelIcon.png");
        menuBtn->setParent(this);
        menuBtn->move(25+(i%4)*70, 130+(i/4)*70);

        //监听选择关卡按钮的信号槽
        connect(menuBtn, &MyPushButton::clicked, [=](){
            if(pScene == NULL) //游戏场景不复用，直接移除掉创建新的场景
            {
                this->hide();
                pScene = new PlayScene(i+1); //将选择的关卡号 传入PlayScene
                pScene->setGeometry(this->geometry());
                pScene->show();

                //PlayScene的返回按钮监听，删除该scene并且指针指向空
                connect(pScene, &PlayScene::chooseSceneBack, [=](){
                    pScene->setGeometry(this->geometry());
                    this->show();
                    delete pScene;
                    pScene = NULL;
                });
            }
        });

        //按钮上显示的文字
        QLabel * label = new QLabel;
        label->setParent(this);
        label->setFixedSize(menuBtn->width(), menuBtn->height());
        label->setText(QString::number(i+1));
        label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter); //设置居中
        label->move(25+(i%4)*70, 130+(i/4)*70);
        label->setAttribute(Qt::WA_TransparentForMouseEvents, true); //鼠标事件穿透
    }
}

//背景设置
void ChooseLevelScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/OtherSceneBg.png");
    painter.drawPixmap(0,0,this->width(), this->height(), pix);

    //加载标题
    pix.load(":/res/Title.png");
    painter.drawPixmap((this->width() - pix.width())*0.5, 30, pix.width(), pix.height(), pix);
}








