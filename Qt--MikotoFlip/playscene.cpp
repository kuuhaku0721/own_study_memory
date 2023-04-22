#include "dataconfig.h"
#include "mycoin.h"
#include "mypushbutton.h"
#include "playscene.h"
#include<QMenuBar>
#include<QPixmap>
#include<QAction>
#include<QPainter>
#include<QTimer>
#include<QLabel>
#include<QFont>
#include<QPropertyAnimation>
PlayScene::PlayScene(QWidget *parent)
    : QMainWindow{parent}
{

}

//重载构造函数
PlayScene::PlayScene(int index)
{
    this->levelIndex = index;

    //设置窗口固定大小
    this->setFixedSize(320,588);
    //设置图标
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));
    //设置标题
    this->setWindowTitle("美琴翻翻乐");

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
    //点击退出 退出游戏
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

    //当前关卡标题
    QLabel * label = new QLabel;
    label->setParent(this);
    QFont font;
    font.setFamily("华文仿宋");
    font.setPointSize(20);
    label->setFont(font);

    QString str = QString("Leavel: %1").arg(this->levelIndex);
    label->setText(str);
    label->setGeometry(QRect(30, this->height() - 50, 120, 50));  //设置大小和位置

    //初始化二维数组
    dataConfig config;
    for(int i = 0; i< 4; i++)
    {
        for(int j = 0; j<4; j++)
        {
            gameArray[i][j] = config.mData[this->levelIndex][i][j];
        }
    }

    //准备胜利图片  胜利时弹下来
    QLabel * winLabel = new QLabel;
    QPixmap tmpPix;
    tmpPix.load(":/res/LevelCompletedDialogBg.png");
    winLabel->setGeometry(0,0, tmpPix.width(), tmpPix.height());
    winLabel->setPixmap(tmpPix);
    winLabel->setParent(this);
    winLabel->move( (this->width() - tmpPix.width())*0.5 , -tmpPix.height());

    //创建金币的背景图片
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            //绘制背景图片
            QLabel * label = new QLabel;
            label->setGeometry(0,0,50,50);
            label->setPixmap(QPixmap(":/res/BoardNode.png"));
            label->setParent(this);
            label->move(57 + i*50, 200 + j*50);

            //金币对象
            QString img;
            if(gameArray[i][j] == 1)
            {
                img = ":/res/Coin0001.png";
            }
            else
            {
                img = ":/res/Coin0008.png";
            }

            MyCoin * coin = new MyCoin(img);
            coin->setParent(this);
            coin->move(59 + i*50, 204 + j*50);
            coin->poxX = i;
            coin->poxY = j;
            coin->flag = gameArray[i][j];

            coinBtn[i][j] = coin;
            connect(coin, &MyCoin::clicked, [=](){
                coin->changeFlag();
                //数组内部记录的标志同步修改
                gameArray[i][j] = gameArray[i][j] == 0 ? 1 : 0;
                //延时翻动周围金币
                QTimer::singleShot(300, this, [=](){
                    if(coin->poxX + 1 <= 3)
                    {
                        coinBtn[coin->poxX+1][coin->poxY]->changeFlag();
                        gameArray[coin->poxX+1][coin->poxY] = gameArray[coin->poxX+1][coin->poxY] == 0 ? 1 : 0;
                    }
                    if(coin->poxX - 1 >= 0)
                    {
                        coinBtn[coin->poxX-1][coin->poxY]->changeFlag();
                        gameArray[coin->poxX-1][coin->poxY] = gameArray[coin->poxX-1][coin->poxY] == 0 ? 1 : 0;
                    }
                    if(coin->poxY+1 <= 3)
                    {
                        coinBtn[coin->poxX][coin->poxY+1]->changeFlag();
                        gameArray[coin->poxX][coin->poxY+1] = gameArray[coin->poxX][coin->poxY+1] == 0 ? 1 : 0;
                    }
                    if(coin->poxY-1 >= 0)
                    {
                        coinBtn[coin->poxX][coin->poxY-1]->changeFlag();
                        gameArray[coin->poxX][coin->poxY-1] = gameArray[coin->poxX][coin->poxY-1] == 0 ? 1 : 0;
                    }

                    this->isWin = true;
                    for(int i = 0 ; i < 4;i++)
                    {
                        for(int j = 0 ; j < 4; j++)
                        {
                            if( coinBtn[i][j]->flag == false)
                            {
                                this->isWin = false;
                                break;
                            }
                        }
                    }
                    if(this->isWin == true)
                    {
                        for(int i = 0 ; i < 4;i++)
                        {
                            for(int j = 0 ; j < 4; j++)
                            {
                                coinBtn[i][j]->isWin = true;

                            }
                        }
                        //如果胜利就把图片移动下来
                        qDebug() << "胜利";
                        QPropertyAnimation * animation1 = new QPropertyAnimation(winLabel, "geometry");
                        animation1->setDuration(1000);
                        animation1->setStartValue(QRect(winLabel->x(), winLabel->y(), winLabel->width(), winLabel->height()));
                        animation1->setEndValue(QRect(winLabel->x(), winLabel->y()+114, winLabel->width(), winLabel->height()));
                        animation1->setEasingCurve(QEasingCurve::OutBounce);
                        animation1->start();
                    }
                });
            });

        }
    }
}

//背景设置
void PlayScene::paintEvent(QPaintEvent *)
{
    //加载背景
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);

    //加载标题
    pix.load(":/res/Title.png");
    pix = pix.scaled(pix.width()*0.5, pix.height()*0.5);
    painter.drawPixmap(10, 30, pix.width(), pix.height(), pix);


}







