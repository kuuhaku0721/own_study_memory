# 					    **Qt翻翻乐----说明文档**

-------------------

​	功能描述：翻翻乐小游戏一共设置20个关卡，每个关卡内有4 * 4 的硬币矩阵，通过点击硬币使硬币翻转，并且连带该硬币四周的硬币一块翻转，当整个矩阵内所有硬币均已翻转为游戏胜利。

----------------

​													整个项目的实现思路概括为以下几个大致的章节：

​																		**一：**开始按钮的设计

​																		**二：**动画效果和动作监听的设计

​																		**三：**选择关卡场景设计

​																		**四：**游戏场景设计

​																		**五：**硬币的封装

-----------

**---->**所有的文件包括：

```c++
//头文件
chooselevelscene.h
dataconfig.h
mainscene.h
mycoin.h
mypushbutton.h
playscene.h
```

```c++
//cpp文件
chooselevelscene.cpp
dataconfig.cpp
main.cpp
mainscene.cpp
mycoin.cpp
mypushbutton.cpp
playscene.cpp
```

-------------

​																		**一：开始按钮的设计**

​		根据项目描述我们知道，对于整个项目的整体架构，首先，第一个映入眼帘的就是开始按钮，所以在初始界面（系由自动生成）当中首先要设置就的就是开始按钮。

```c++
/*以下为文件mypushbutton.h*/
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
```

```c++
/*以下为文件mypushbutton.cpp*/
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
```

----------------------------------

**---->在 ”mypushbutton.h“ 的头文件中**

```c++
#ifndef 头文件名_H
#define 头文件名_H

#endif // 头文件名_H
```

​		该部分为创建文件时系统自动生成，作用是为了防止头文件被重复引用，因为在接下来的构建过程中会反复用到一些文件如按钮类，硬币类等，有ifdef控制可以防止头文件因为文件嵌套而被重复引用。

​		开始按钮头文件作为控制中枢，需要定义（不写实现，实现在.cpp中）开始按钮所需要的全部函数（封装在类内），并且包含头文件

​		#include <QPushButton>   //Qt的按钮类，当中包含按钮的所有操作

​		#include<QMouseEvent>   //Qt的鼠标事件监听类，其中包含有关鼠标事件监听的功能，包括且不限于**mousePressEvent**，**mouseReleaseEvent**等（注意调用是指针*调用）。

```c++
//在头文件中用类来统一管理
class MyPushButton : public QPushButton  //以public的形式继承QPushButton类，is-a代表自己的按钮
{										 //类“是一个”Q按钮
    Q_OBJECT   //这个不知道是啥，之后回来补充
public:  //public作用域，函数都写在该作用域下，方便后面调用，至于封装性和设计模式，这里暂不考虑使用（想改一改的话后续再修改）
    
    
    QString normalImgPath; //两个public作用域下的参数
    QString pressImgPath;  //参数类型是QString，为Qt风格的string

signals:  //Qt风格的类，内含一个signals作用域，用来发出一些提示信息，这里用不上

};
```

​		explicit MyPushButton(QWidget *parent = nullptr);  //缺省的构造函数，即默认的构造函数，当声明了自己的构造函数的时候需要说明默认构造。当只有一个参数的时候可以使用explicit，确保被explicit修饰的构造函数中不会发生隐式类型转换。

​		MyPushButton(QString normalImg, QString pressImg = "");   //自己的构造函数，其中normalImg 为正常显示的图片，保证在不按下按钮的初始状态下显示图片，pressImag 为按下的图片，默认为空，后续可有鼠标事件监听来更改。

​		void zoom1();
​		void zoom2();    //两个按下显示特效的函数，用来达成按下按钮时显示的效果。

​		void mousePressEvent(QMouseEvent *e);
​		void mouseReleaseEvent(QMouseEvent *e);    //重现“Back”返回按钮的事件监听

**---->在mypushbutton.cpp文件中**

```c++
#include "mypushbutton.h"  //必须包含.h头文件，这是必要项
#include<QDebug>  //QDebug类是用于在控制台输出信息时使用，如qDebug() << normalImg << "加载图片失败!";  其作用有点类似 cout，只不过是在程序运行过程中在控制台打印信息
#include<QPropertyAnimation>  //特效类，用来设置一些动画效果
```

```c++
MyPushButton::MyPushButton(QWidget *parent)
    : QPushButton{parent}
{ }
```

​		默认构造函数，在.h头文件内，我们将构造函数的默认参数设置为了QWidget *parent = nullptr的空指针形式，为了保证成员已初始化在，在.cpp文件中，用成员初值列的形式将祖宗类QWidget设置为自己的父类，让QWidget的指针指向QPushButton。

```c++
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
```

​		成员变量是normalImgPath和pressImgPath，也就是两个Path路径名称，保存的是传入的路径名称，normalImgPath = normalImg;的作用是将成员变量的路径名赋值为传入的路径名。下面的pressImgPath = pressImg;亦是如此。

​		QPixmap pixmap; 创建了一个QPixmap图片对象.

​		bool ret = pixmap.load(); 用一个QPixmap内置的load函数返回一个bool变量来判断图片是否成功加载，避免图片丢失等加载失败的情况。

​		接下来的四个函数为PushButton的内置函数，因为用到了继承，所以现在的MyPushButton“is-a”是一个QPushButton类，因此此处的this->指向的自己，也就是QPushButton，能够使用QPushButton的内嵌函数来进行一系列的设置。

​		QPushButton::setFixedSize()；设置按钮的尺寸，接受两个参数，宽和高，可以藉由Pixmap::width()和Pixmap::height()的返回值来获取当前图片的宽和高进行设置。

​		QPushButton::setStyleSheet()；设置不规则图形的样式表，接受的参数为string类型的enum类型参数，这个参数是QPushButton内置的，记是肯定记不住的，需要的时候可以去查询说明文档来选择合适的样式使用。

​		QPushButton::setIcon()；设置按钮的图标，也就是在按钮上贴一张图片，接受一个Pixmap的参数，也就是上面定义的QPixmap pixmap对象，其中路径指向的图片就是我们所使用的开始按钮的图片。

​		QPushButton::setIconSize()；设置图标的大小。设置的是贴在按钮上面的图片的大小，最好是跟按钮的大小一致（也就是全贴合），可以接受一个QSize类型的参数，QSize类型就是将图片的宽和高两个类型打包成一个size类型，这里用的匿名对象的方式传入。

​	**然后再梳理一次对于开始按钮的设计思路：**我们需要的是一个开始按钮，所以首先我们需要设置一个按钮，然后设置这个按钮的大小，这个按钮的样式，是方的还是圆的？设置完大小和样式之后，这只是一个空空的按钮（或许你也可以在按钮中间写上“开始”两个字，但很显然，我们并不想这么做），我们需要给这个按钮穿一层衣服，也就是在按钮上贴上图片，那么首先就是传入这个图片，然后用一个对象来保存这个图片文件，在按钮上设置了图标（图片，图标是因为setIcon）之后，还要对图片的大小进行调整，让它能够贴合在按钮上，这样一个开始按钮的设置好了。（当然，只是外观设置好了，功能还没有）

**---->**在设置完开始按钮之后记得设置一下主要场景一共测试

```c++
/*以下为mainscene.h*/
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
```

```c++
/*以下为mainscene.cpp*/
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
```

-------------

​																		**二：动画效果和动作监听的设计**

​	在这一部分，主要完成为按钮设置按下去的动画效果，以及为开始按钮设置动作监听，这将是我们第一次设置场景切换，当触发开始按钮的动作之后，画面将会切换到下一个场景:选择关卡场景。

```c++
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
```

​		设置按钮按下的动画效果，按下去弹一下bo~yong的弹一下，当然，设置两个函数就是为了，弹一下还得再弹回来，不然就会按一下往下移动一段，直到消失不见...

​		QPropertyAnimation * animation1 创建一个动画的对象，用指针的方式创建，后面设置初始参数，接受两个参数(this, "geometry")，第一个参数是设置动画的目标对象，此处就是this，也就是现在要设置动效的按钮，第二个参数也是内置的enum类型参数，是特效的种类。

​		QPropertyAnimation::setDuration();   duration持续时间，即为设置动画效果的持续时间，单位是毫秒

​		QPropertyAnimation::setStartValue()；设置动画的起始位置，动画效果添加到当前的按钮上，而动画效果就是从一个地方移动到另一个地方，以此达成一种“动起来”的效果，所以需要设置动效的起止位置，开始位置接受一个QRect形式的参数。

​		QPropertyAnimation::setEndValue()；设置动画的结束位置，让按钮（控件）在起始位置和终止位置之间进行“geometry”（动画形式）形式的移动效果，接受一个QRect形式的参数。

​		QRect()；是一个四边矩阵类型，Rect，可以联想Rectangle矩形，就是确定这个按钮（控件）的碰撞箱（相对位置）的量，它需要四个参数，分别是x坐标，y坐标（控件的左上角）和按钮的宽和长，有了这四个参数就可以确定这个按钮（控件）的相对位置，结束位置也在QRect的参数里修改即可。

​		QPropertyAnimation::setEasingCurve()；设置动画效果的缓和曲线，是一个数学函数，能够让动效看起来更加自然，啵~地弹一下，不必要深究，记住就行，需要了就去帮助文档查一查。接受一个效果参数，当然，也是帮助文档查，此处接受的参数为QEasingCurve::OutBounce ，为弹跳效果。

​		QPropertyAnimation::start()；开始执行动画

**关于动画效果的设计思路：**设计按钮或者说控件的动画效果就像是流水线作业，熟能生巧，因为每一个步骤都是必要的也是最基础的，按照流水线一样的方式去执行、书写每一个步骤就能实现一个动画效果。其大致步骤可以分为：首先要创建一个动画对象，接受的参数就是当前要设置动画的控件，注意不要忘记设置格式参数，有了动画对象之后就要分别设置动画的开始位置，结束位置，持续时间，动画的执行三大部分完毕之后需要对动画本体进行完善，需要设置它的缓和曲线，这个用到的时候就需要到帮助文档去查看，最后设置开始执行动画就可以了，只不过不要忘记，以上书写的只是动画执行的一半，就像这里写的弹跳动画，弹了下去肯定还要回来，所以后面还要书写设置位置和缓和曲线，让控件执行完动作之后还能够再次回到原位置，当然，返回去的动作还需要看具体实施。

```c++
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
```

​		设置鼠标的监听事件，也就是为我们安装的按钮添加功能，鼠标监听事件包括两部分，按下和释放，但是，其实两部分实现的是一样的功能，最终的效果就是鼠标点击一下，启动下一个场景.........你问为什么要写两遍一样的？鼠标按下去不松开怎么启动啊。

​		if(pressImgPath != "") {} 判断条件保证当前选中路径中有正确的图片，这样往下的步骤才能正常实现，确保运行安全，如果选中的路径没有图片或者加载异常就不启动下一个场景，这样场景之间的切换不会混乱。

​		QPixmap pixmap; 设置图片对象用以加载下一个场景（这里设置的场景是选择关卡场景的背景图片），同样再做一次判断以防止图片加载失败（原路径里的图片丢失等）的情况。

​		qDebug() << 其作用类似于cout，在控制台打印信息。

​		接下来的四步：设置大小，设置风格，设置图标，设置图标大小均与构造函数内作用（包括写法）相同，其实不写也可以正常运行，但是只是为了程序运行安全起见需要再度书写。

​		return QPushButton::mouseReleaseEvent(e);  将动作监听交给父类，也就是按钮类去执行，让按钮实际达成这一项功能。

**动作监听的设计：**最重要的地方在于，让监听事件，也就是参数(QMouseEvent *e) return给父类执行，这样能为按钮（控件）添加鼠标事件功能，而这一部分的实现需要用到后面所有的按钮上，所以交给父类执行可以让当前执行动作的是哪个按钮就监听哪个按钮的动作。

-------------------------

​																			**三：选择关卡场景设计**

在上面的过程中我们已经创建了开始场景和开始按钮，以及开始按钮按下去之后的动作，也就是切换到下一场景的选择关卡场景之中，而在开始关卡选择之前，首先需要进行的就是整体窗口的创建。

```c++
/*以下为chooselevelscene.h */
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
```

```c++
/*以下为 chooselevelscene.cpp */
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
    QMenu * privateMenu1 = bar->addMenu("Only"); //摆设
    QMenu * privateMenu2 = bar->addMenu("My"); //摆设
    QMenu * privateMenu3 = bar->addMenu("Railgun"); //摆设

    //创建按钮菜单项
    QAction * quitAction = startMenu->addAction("退出");
    QAction * pM1 = privateMenu1->addAction("唯我"); //摆设
    QAction * pM2 = privateMenu2->addAction("超电磁炮"); //摆设
    QAction * pM3 = privateMenu3->addAction("永世长存"); //摆设

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
```

**---->**  .h头文件和.cpp文件分开设置，不再过多赘述

​		#include <QMainWindow> 包含window的头文件，让类public继承window类，“is-a”是一个窗口，作用体现在.cpp文件内其他头文件的实现时需要指定父类参数，此时如果参数为this的话就代表父类是一个窗口，而且是当前QMainWindow窗口。

​		#include "playscene.h" 游玩场景的头文件，意在设置每一个关卡的场景，待后面设置关卡场景的时候叙述，这个也是在设置关卡场景的时候才回来这里添加的。

​		explicit ChooseLevelScene(QWidget *parent = nullptr);   当构造函数只有一个参数的时候可以使用explicit。参数设置父类指针default参数为null，添加explicit前缀之后能够避免参数内发生隐式类型转换。

​		void paintEvent(QPaintEvent *);  设置背景的函数，用到了绘画事件QPaintEvent。

​		PlayScene *pScene   声明关卡是在构建关卡场景时回来添加的，这里不作展开叙述。

```c++
signals:
    void chooseSceneBack();
```

​		这里的signals作用域类似于public、private作用域，主要用处是在需要时向控制台输出信息。这里的设置是自定义一个信号，告诉主场景点击了返回，这是场景要返回到上一个场景去。举例来比喻就是两个人轮流值夜班的时候到换班的时候了告诉上一个人额滴任务结束了该上一个人回来值班了。

**---->**在chooselevelscene.cppz中

```c++
#include "chooselevelscene.h"  //包含自己的头文件，为每一个声明书写函数的定义
#include "mypushbutton.h" //包含按钮的头文件，因为需要用到按钮类，比如返回按钮，关卡按钮
#include<QMenuBar> //菜单栏，用来设置最上面的一行菜单
#include<QPainter> //画笔类，用来给当前的场景画上图片
#include<QPixmap> //图片类
#include<QTimer> //计时器类，设置触发响应时间
#include<QLabel> //标签类，用以显示文字信息
```

​		接下来的是一个函数内的内容，分成几段来叙述

```c++
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

    //创建按钮菜单项
    QAction * quitAction = startMenu->addAction("退出");

    //点击退出，退出游戏
    connect(quitAction, &QAction::triggered, [=](){
        this->close();
    });
```

​		：QMainWindow{parent} 成员初值列将初始参数设置为了父类，以实现is-a是一个的关系，其作用紧随其后

this->setFixedSize()； 这里的this->也就是QMainWindow:: 窗口类作用域下的函数，用以设置当前窗口的宽高规格，接受两个参数，weight和height，尽量保持前后一致，即开始场景，选择关卡场景，游玩场景的大小一致。

​		QMainWindow:: setWindowIcon()；设置窗口的图标，就是左上角那个，接受一个QPixmap图片类型的参数，此处使用的是匿名对象传入图片。：/代表的是本目录下的res文件夹，如果这么用需要在资源文件夹下手动设置。

​		QMainWindow:: setWindowTitle()；设置窗口标题，就是左上角图标右边的文字说明，接受一个string的文字类型作为参数。

```c++
QMenuBar * bar = this->menuBar();
this->setMenuBar(bar);
```

​		QMainWindow窗口具有一个menuBar菜单对象，我们需要定义一个QMenuBar对象指向当前窗口的菜单，并且将当前窗口的菜单设置为该对象，这个过程可以类比插入链表当中的某一个节点，我们首先定义出这个节点，让这个节点指向链表中的某个位置，然后告诉链表有个节点，让链表把那个位置设置为那个节点。

```c++
QMenu * startMenu = bar->addMenu("开始");
```

​		菜单栏设置完毕之后就需要往菜单栏添加菜单，QMenu类实例化菜单对象，并且调用菜单栏的addMenu添加菜单函数添加菜单项，菜单项接受一个string字符串类型的参数当作菜单的名字。

​		菜单项创建完毕之后就该设置这个菜单项的具体功能了，这里用到的是QAction 动作类，代表这个菜单项具有哪些动作。

​		QAction * quitAction = startMenu->addAction("退出");  用QAction实例化一个对象并且调用菜单项的addAction 添加动作的函数设置当前菜单动作，addAction函数接受一个string字符串类型的参数，用以显示当前动作的名称。

```c#
//重点是connect
    connect(quitAction, &QAction::triggered, [=](){
        this->close();
    });
```

​		connect 连接，将某一个控件与某一个功能建立连接，以使该控件能够启用某一个功能（类比动作事件监听)，接受三个参数，第一个参数是想要执行动作地执行体，也就是当前的QAction对象，第二个参数是执行动作的对象的执行方式，这里的参数是触发式启动，第三个参数接受一个lambda表达式，用以定义详细的执行的动作主体，这里设置的是"退出"动作的执行体，所以调用QMainWindow::close()关闭当前窗口。

```c++
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
```

​		在头文件定义时我们提到了signals: 作用域下的chooseSceneBack()；函数，也就是当我们点击了返回的时候要告诉主界面我们点击了返回，让当前页面退居幕后，这里要定义的就是现在的页面上的back返回按钮。

​		MyPushButton * closeBtn 声明一个自己的按钮类，传入的参数是定义自己的按钮时的normalImg，也就是正常显示的图片的路径。将这个图片贴在当前的按钮上。

​		QPushButton::setParent()；设置当前的按钮的父类，其实就是设置现在的按钮是哪个地方的按钮，哪个界面上的按钮，这里的this指代的是当前窗口当前的QMainWindow，告诉按钮它的父类是现在的窗口。

​		QPushButton::move()；按钮类的移动标志，移动按钮到某一位置，也就是设置按钮的相对位置，参照点是按钮的左上角（大部分的控件参照点都是左上角，包括QRect也是左上角坐标），需要一个点的坐标（决定宽和高），这里为了能让按钮完全显示出来所以用当前窗口的宽和高（也就是右下角坐标）减去图片（或者说按钮）的宽和高，得到的坐标点就是按钮的左上角所在的位置。

​		connect  将当前按钮与某个功能建立连接，即为为当前按钮connect（链接）一个功能。这里传入的三个参数，第一个是按钮本身，表明了想要设定功能的控件本体，第二个参数是启动方式，这里的启动方式是按钮被点击，即QPushButton::clicked，第三个参数为lambda表达式，其内定义了具体的点击按钮后所实现的功能。

​		在connect的lambda表达式内的设计是让系统（窗口）经过一个反应时间之后执行，可以不设置Timer即让其立即执行，但是设置Timer之后会更符合直觉，而且在视觉上会有一个更好的效果。

​		QTimer::singleShot()；计时器类，一般用于需要计时或者需要延迟一段时间后执行的程序中，特用于时间控制。

​		singleShot()；Timer作用于下函数，代表当前计时器的响应方式，singleShot代表响应一次，接受三个参数，第一个参数是响应时间，即当我们点击了back返回按钮（因为当前connect的对象就是back按钮）后等待多长时间系统作出应答，300ms是一个比较理想的数值，可以是3000ms，也就是3s，那么当点击back之后将会经过一个漫长的等待过程。第二个参数是计时器作用对象，这里的this指代的Timer所在的外围作用域，也就是当前的窗口本身（在chooselevelscene.cpp文件内，几乎所有this都指的是窗口本身），第三个参数是lambda表达式，其内部定义了经过规定时间之后执行什么样的动作。

​		QMainWindow::hide()； 无参函数，隐藏当前窗口，

​		emit 发送信息到控制台，后面跟着要发送的东西，可以是函数调用，形式上有点像throw？

​		chooselevelscene::chooseSceneBack();  这里没有用QMainWindow是因为它压根不是MainWindow内的函数而是chooselevelscene自己的函数，前面之所以用QMainWindow是因为chooselevelscene公有继承了QMainWindow，达成了一种“is-a”的关系。 chooseSceneBack()；函数定义在signals作用于下就是为了在这里能够告诉它这是一个信号信息，需要传送到控制台的信号，告诉控制台chooselevelscene关闭了自身，。

```c++
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
    } //这个是for循环自己的 }
} //这个是最外层函数的 }
```

**---->**创建选择关卡的按钮

​		在这一段我们要做的是在chooselevelscene选择关卡场景中创建我们要选择的关卡（的按钮）。一共设计20关，也就是要创建20个一模一样（只有标号数字不一样，这不是问题）的按钮出来，所以首先要在最外层套一层循环，一次性创建完全部20个按钮，然后为每一个按钮connect链接一个功能令其启动对应的每一关的游戏场景。（前面定义头文件时我们提到了包含“playscene.h”的作用就在于此，虽然我们现在还没有到创建游戏场景的时候）

​		MyPushButton * menuBtn； 实例化一个按钮对象，后面的参数是自己定义按钮类时声明的构造函数内的参数

​		normalImg，因为20个按钮背景都一样（只有上面的数字标号不一样，这个到后面设置）所以在循环体内每次实例化按钮时都使用一样的图片即可。

​		QPushButton::setParent()；设置当前按钮的父类，也就是设置按钮所在域，这里的this指代当前窗口。

​		QPushButton::move()；移动按钮位置，即设置按钮的坐标，接受两个参数x和y，就是按钮左上角的坐标点，这里的计算是根据按钮的大小来确定，在窗口内一共设置20个按钮，分为 5 行 4 列放置，相邻按钮之间间隔一样的距离，利用循环次数的i来确定当前是第几个按钮，25是按钮与按钮之间的左右间隔，（i%4）代表每一行是四个按钮，第五个就要换行然后从最左边开始放，它只控制左右移动所以直接从头开始放，70是按钮的宽。130是按钮与按钮之间的上下间隔，（i/4）来代表换行，当i为0->3时这个值为0，i为4->7时这个值为1，以此来达成换行的目的，它只负责按钮的上下移动，所以每次乘的（i/4）的值不同就能控制按钮所处的水平线不同，70是按钮的高。

​		QLabel * label； 实例化一个标签对象，用以给按钮设置标号数字来代表关卡号，之所以先叙述label而不是在它上面的connect是因为在选择关卡场景中首先创建的按钮和按钮上的标号，而connect的按钮的功能是在创建playscene游玩场景的时候回过头来添加的功能。

​		QLable::setParent()；设置作用域父类，此处的this指代的当前窗口，代表这个标签的显示的地方在当前窗口上。

​		QLabel::setFixedSize()；设置标签的大小，接受两个参数宽和高，因为是给按钮添加标签，所以标签的宽和高可以直接将按钮的宽和高传入当作参数设置。

​		QLabel::setText()；设置标签要显示的内容，也就是想让这个标签显示的关卡号的文本内容，接受一个string的字符串类型为参数。

​		QString::number()；Qt的string库中包含的一个函数，能够将参数的数字转换成string字符串类型，也就是string(int)，循环是从0开始（最好不要从1开始，从0开始计算按钮的相对位置比较方便）所以这里的关卡号为i+1.

​		QLabel::setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);  设置label标签内的文本内容居中，不需要强行记忆，需要的时候可以查询帮助文档。

​		QLabel::move()；移动标签，也就是设置标签的位置，计算的位置与设置按钮位置相同，一个标签对应一个按钮。

​		QLabel::setAttribute(Qt::WA_TransparentForMouseEvents, true); 设置标签的事件穿透，让像鼠标点击之类的事件能够透过标签直接作用在标签后的控件（按钮），可以理解为标签就是在物体上面盖上了一层布，然后在这层布上书写内容让外界看到，但是这样一来对物体来说它的上面被完全遮盖，对外界来说物体就被隐藏了，所以如果想要操纵背后的物体就要让标签，也就是这块布能对外界穿透，让外界的动作直接穿透标签作用于标签后面的物体。

​		connect 为当前按钮添加功能，实现点击对应关卡的按钮场景跳转到对应的关卡，三个参数分别是当前设置功能的按钮，启动方式为点击启动，定义具体功能的lambda表达式。

​		if(pScene == NULL)	首先要判断当前的这个按钮下的关卡场景是否为NULL，为NULL继续。因为每一次的哟咻场景不复用，每启动一次就重新创建一个场景出来，每点击一次返回就删除当前的场景，让场景复位。

​		this->hide();  当点击了某个按钮之后就要跳转到下一个场景中去，当前的场景就可以隐藏退居幕后。

​		pScene = new PlayScene(i+1);  实例化一个游戏场景对象，后面的参数为playscene的构造函数的参数，代表场景号，而场景号对应着相应的矩阵数组，数组决定着游戏场景中硬币的配置。

​		QMainWindow::setGeometry(); 设置窗口的几何环绕，一般 (this->geometry()) 的 geometry较为常用，其他的需要时可以查阅帮助文档。

​		QMainWindow::show()；显示窗口。当前的窗口（chooselevelscene）已经隐藏，需要唤醒下一个场景，让下一个场景（playscene）显示。

​		在playscene中也需要有返回按钮，当想要从游戏场景返回选择关卡场景时需要通过点击back返回按钮删除当前游戏场景，并让选择关卡场景显示。

​		connect 链接了当前场景QMainWindow的功能，第一个参数为当前的playscene游戏场景，第二个参数为当前场景的触发方式，也就是选择了返回按钮（注意这里的触发方式是PlayScene::作用于下，也就是针对于它自己的），第三个参数lambda表达式定义具体的功能。

​		pScene->setGeometry(this->geometry());  仍然设置游戏场景的几何环绕。

​		this->show()；这里的this指的是当前的chooselevelscene选择关卡场景，这也是为什么这一步的connect操作要特地在写playscene的时候回来chooselevelscene的文件中定义的原因，因为每一次从游戏场景中退出来都需要再次显示选择关卡场景，并且删除方才的场景。

​		delete pScene;	pScene = NULL; 删除场景，令场景为空，使这一关的配置复位，下一次再启动这一关的时候重新创建。

```c++
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
```

**---->**设置选择关卡场景的背景板

​		QPainter painter(this); 画笔类，声明一个画笔对象（上面的参数也有绘画事件，已经说明了在这一步中不单单是设置以下背景板那么简单），这里的this指的还是当前的MainWindow窗口，代表当前的画笔作用的范围是当前的chooselevelscene的窗口。

​		QPixmap pix; 声明的图片类，用以装载背景版的图片和画笔要操作的图片。

​		QPixmap::load()；装载图片，参数为图片路径的字符串对象。

​		QPainter::drawPixmap()；画笔类的绘画图片函数，参考点坐标还是左上角，代表画笔要从哪个点开始画什么进去，接受五个参数，前两个代表绘画开始点（也就是左上角，因为这是背景版，铺满整个窗口），第三个和第四个代表要画的大小，一般设置为窗口大小，让图片能够铺满窗口（因为是背景），最后一个参数就是要画的图片。

​		QPixmap::load()；装载另一张图片，这也是为什么不是直接设置窗口背景而是要用画笔类去画的原因，因为我们除了背景板以外还需要在窗口上添加（画）别的图片进去。

​		QPainter::drawPixmap()； 接受的仍然是五个参数，但是因为只是标题而不是背景板，所以在绘画开始点和画的大小上需要做出调整，具体的大小可以视实现效果而定。

**关于选择关卡场景设计**在我们开始创建选择关卡的场景的时候，首先需要确定的肯定是整个窗口的布局配置，布局就需要从头到尾设置窗口的图标，窗口的标题，然后是菜单栏，当然菜单栏并不是必需品，可以视需要设置也可以像上述一样设置了菜单栏但是仅添加了”退出“一个功能选项。如果要设置菜单栏就需要由外到内，从大体到局部去设置，先设置整个长条的菜单栏，然后设置菜单栏的第一个菜单，菜单确定之后设置这个菜单内部具体的菜单项，最后为每一个菜单项添加功能就可以完成对菜单栏的创建。菜单栏创建完毕之后就要开始对整个场景开始创建，从实现的简繁性以及控件的复用性考虑可以先创建返回按钮，用以隐藏当前返回上一个场景，当然，这一步也可以放到后面去设置。既然是选择关卡场景的布局设置，肯定最重要的是选择的关卡，最终的实现是一共20个不同的关卡，所以这里可以嵌套一个循环来创建20个按钮来当作每一个关卡的入口。首先声明出按钮对象，设置按钮的位置，这里要注意每个按钮之间相对位置的确定，设置按钮的标签号也就是关卡号，为按钮链接启动场景的功能。在设置按钮上标签的场景号时需要注意除了标签的大小和位置需要与按钮保持一致以外还要为标签设置事件穿透以保证后面的控件能够正常使用。在设置按钮功能的时候需要注意每一次进入游戏场景都是一个新的场景，所以要判断当前关卡场景是否为空，在游戏场景选择了返回之后要及时删除当前场景并置空，因为游戏场景也有返回按钮，所以可以先设置返回按钮然后再去循环创建关卡按钮。

--------------------------------------------

​																				**四：游戏场景设计**	

​	在上一步创建完选择关卡场景之后，选择了关卡，下一步肯定就是进入每一个关卡对应的游戏场景，因为接下来需要设置游戏场景playscene。

```c++
/*以下为playscene.h*/
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
```

```c++
/*以下为playscene.cpp*/
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
    QMenu * privateMenu1 = bar->addMenu("Only"); //摆设
    QMenu * privateMenu2 = bar->addMenu("My"); //摆设
    QMenu * privateMenu3 = bar->addMenu("Railgun"); //摆设
    //创建按钮菜单项
    QAction * quitAction = startMenu->addAction("退出");
    QAction * pM1 = privateMenu1->addAction("唯我"); //摆设
    QAction * pM2 = privateMenu2->addAction("超电磁炮"); //摆设
    QAction * pM3 = privateMenu3->addAction("永世长存"); //摆设
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
```

**---->**在playscene.h中	

​		#include "mycoin.h" 这一个模块设置的是游戏场景，游戏场景除了背景搭建以外还需要有游戏的主体，也就是翻硬币的硬币部分，所以在做游戏主体的时候需要在这里包含coin的头文件，这一步属于后续添加，并不是当前模块设置时需要的所以此处仅作说明。

​		class PlayScene : public QMainWindow  public公有继承，形成“is-a”的关系，当前的窗口”是一个“QMainWindow窗口。

​		explicit PlayScene(QWidget *parent = nullptr);  当构造函数的参数只有一个时可以使用explicit，参数中设置父类的default参数，添加explicit防止发生隐式类型转换。

​		PlayScene(int index); 重载构造函数，传入一个索引来代表当前关卡，index来自于选择关卡窗口的关卡按钮传入。

​		int levelIndex; 记录关卡的索引，主要用以确定应该调用dataconfig文件中的哪个二维数组来决定硬币的初始状态。

​		void paintEvent(QPaintEvent *); 重写paintEvent事件，用以在窗口上进行后续的绘制操作，比如当游戏胜利的时候胜利提示标志的显示等。

​		int gameArray[4] [4];  一个二维数组数据，在dataconfig文件内，系事先定义，建议直接拿来用，内部定义的二维数组代表了每一关硬币的初始状态。

​		MyCoin * coinBtn[4] [4];  声明一个coin硬币类对象，当点击一个硬币令其翻转的时候需要联动让其周围的硬币也随之翻转，这时需要同步修改数组数据，所以需要定义一个硬币数组用以表示周圈硬币。

​		bool isWin; 判断是否胜利的标志，胜利的时候需要显示胜利的提示标志并且停止当前窗口的操作。

​		signals作用域下的chooseSceneBack()；表示在当前窗口选择了back返回按钮，此时就需要隐藏当前窗口，显示上一个窗口。

**---->**在playscene.cpp中

```c++
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
```

​		#include "dataconfig.h" 包含一个事先定义好的dataconfig文件，其中定义了所需要用来设置硬币初始状态的二维数组。

​		#include "mycoin.h" 包含硬币类的头文件，这一步是为了设置窗口内的硬币对象（或许我应该先叙述硬币类的封装再来叙述游戏场景的搭建？）

​		#include "mypushbutton.h"  包含按钮类，用以创建当前窗口的一系列的按钮。

​		#include "playscene.h"  包含自己的头文件，其内声明了接下来将要详细定义的一系列函数。

​		#include<QMenuBar>  为了与前一个窗口保持一致，当前的游戏窗口也需要设置菜单栏。

​		#include<QPixmap>  图片类，用来装载背景图片，硬币图片，游戏胜利的提示图片等。

​		#include<QAction> 设置按钮或者菜单项点击后的动作

​		#include<QPainter> 画笔类，用来对窗口进行后期（或运行中）进行图片的绘制。

​		#include<QTimer> 计时器类，用来为某些功能设定计时功能。

​		#include<QLabel> 标签类，用以在窗口的某些控件上添加文字显示

​		#include<QFont> 字体类

​		#include<QPropertyAnimation> 动画效果类，用来给控件设置一些显示效果如胜利标志弹出的效果，硬币翻转的效果等。

```c++
PlayScene::PlayScene(QWidget *parent)
    : QMainWindow{parent}
{}
```

​		缺省的default构造函数，因为写了自定义重载构造，所以需要显式声明默认构造函数，其内空实现。

```c++
//重载构造函数
PlayScene::PlayScene(int index)
{
    this->levelIndex = index;

    //设置窗口固定大小
    this->setFixedSize(320,588);
    //设置图标
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));
    //设置标题
    this->setWindowTitle("翻金币");

    //创建菜单栏
    QMenuBar * bar = this->menuBar();
    this->setMenuBar(bar);

    //创建开始菜单
    QMenu * startMenu = bar->addMenu("开始");
    //创建按钮菜单项
    QAction * quitAction = startMenu->addAction("退出");
    //点击退出 退出游戏
    connect(quitAction, &QAction::triggered, [=](){
        this->close();
    });
```

​		PlayScene::levelIndex  从选择关卡页面传入的index关卡号交给levelIndex保管，负责确定调用哪一个二维数组来初始化硬币阵列。

​		为了与前一个窗口保持一致，下面的设置菜单栏的动作与chooselevelscene选择关卡场景中设置菜单栏的步骤一模一样，或许也可以cv。

```c++
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
```

**---->**在页面的右下角设置返回按钮

​		MyPushButton * closeBtn  声明一个按钮对象，调用的构造函数是自己定义的构造函数MyPushButton(QString normalImg, QString pressImg = "");  接受的是两个参数，而前面的按钮类都只用了一个参数是因为第二个参数用默认值就行，不需要特别设置，第二个参数代表的是按钮按下去之后要显示的图片（前面的按钮都只需要设置一次图片就可以，没必要设置按下去的图片，当然如果想设置也可以）。

​		QPushButton::setParent()；设置当前按钮的父类，也就是作用范围为当前的窗口，这里的this指代的是当前的playscene的QMainWindow。

​		QPushButton::move()；移动按钮，也就是设置按钮的位置，参考点是按钮的左上角。

​		connect链接按钮的功能，返回按钮，功能是隐藏当前窗口，传回信息后显示上一个窗口。第一个参数是按钮对象，第二个参数是触发方式为点击触发，第三个参数是lambda表达式，定义了按钮的功能主体（前面忘记提的一点，lambda表达式的[=]代表表达式内部都是值传递[&]代表都是引用传递）

​		QTimer计时器设置触发时间，当点击按钮之后启动lambda表达式内功能，功能限定经过Timer的第一个参数的时间后启动程序，Timer的lambda表达式内定义经历一段时间后启动的具体的功能。

​		QMainWindow::hide()；表示隐藏当前窗口，emit为向控制台发送信息，告诉控制台选择了返回按钮并且已隐藏了当前窗口需要显示上一个窗口。

```c++
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
```

​		QLabel * label；声明一个标签类对象，用以在其上添加文字用以显示信息。

​		QLabel::setParent();  设置标签类的作用范围是当前窗口。

​		QFont font； 声明一个字体类对象，用以修饰用以显示的字体。

​		QFont::setFamily()；设置字体的格式，后面可以用字符串形式传入一个在word的字体选项可以选择的任一字体格式。

​		QFont::setPointSize();  设置字体大小。

​		QLabel::setFont();  调用标签类的设置字体的函数用以设置当前标签的字体格式，接受一个QFont字体格式类对象。

​		QString 初始化一个字符串对象，用以显示当前关卡号，后面的levelIndex来自于本类内的索引号。（由上一个选择关卡页面传入）

​		QLabel::setText()；调用标签类的设置文本函数，将当前标签要设置的文本内容设置为刚才定义的字符串对象。

​		QLabel::setGeometry()；设置标签的大小和位置，接受一个矩形Rect参数，用以表示标签的大小和相对位置。

```c++
    //准备胜利图片  胜利时弹下来
    QLabel * winLabel = new QLabel;
    QPixmap tmpPix;
    tmpPix.load(":/res/LevelCompletedDialogBg.png");
    winLabel->setGeometry(0,0, tmpPix.width(), tmpPix.height());
    winLabel->setPixmap(tmpPix);
    winLabel->setParent(this);
    winLabel->move( (this->width() - tmpPix.width())*0.5 , -tmpPix.height());
```

​		准备胜利图片，在游戏胜利的时候弹下来显示，也就是说，胜利的图片其实是早已加载好准备好了的，只不过在窗口的上面看不到，在需要的时候从上面滑到窗口内能看到以达到胜利时弹下胜利标志的效果。

​		QLabel * winLabel；声明一个标签对象，胜利的图片也是装载在了标签上，用一个label标签来显示。

​	 	QPixmap tmpPix;声明一个图片类对象用以装载胜利标志的图片。

​		Qpixmap::load()；调用图片类的装载图片函数，参数传入胜利图片的路径地址字符串。

​		QLabel::setGeometry()；设置标签的位置和大小。

​		QLabel::setPixmap(); label标签类内置有装载图片的函数，接受一个Pixmap图片类对象，将图片显示在标签上。

​		QLabel::setParent()；设置当前标签的父类，也就是作于区域为当前窗口。

​		QLabel::move()；移动标签的位置，将标签移动到当前窗口之外让其不可见，需要的时候再让它弹下来。

```c++
    //初始化二维数组
    dataConfig config;
    for(int i = 0; i< 4; i++)
    {
        for(int j = 0; j<4; j++)
        {
            gameArray[i][j] = config.mData[this->levelIndex][i][j];
        }
    }
```

**--->**二维数组内容来自于事先准备的dataconfig文件，关于文件内容不再详细赘述。**<---**

​		dataConfig config; 声明一个dataconfig对象，用以或许其内部信息

​		gameArray[i][j] = config.mData[this->levelIndex] [i] [j]; 使用一个双循环来向dataconfig文件拿到二维数组的内容，  其中levelindex决定要取得哪一个二维数组，后面的i和j决定当前二维数组内的数据内容。

以上游戏场景的外框就准备完毕。

​	接下来该准备游戏的主体：硬币了，在实例化硬币对象的时候还要准备硬币的背景，也就是镶入硬币的凹槽，因为凹槽为4 * 4一摸一样的图片，硬币也是4 * 4，具体正反面由二维数组决定的一摸一样的对象，所以这里使用一个双层循环来完成。下面为循环内部内容。

```c++
            //绘制背景图片
            QLabel * label = new QLabel;
            label->setGeometry(0,0,50,50);
            label->setPixmap(QPixmap(":/res/BoardNode.png"));
            label->setParent(this);
            label->move(57 + i*50, 200 + j*50);
```

​		QLabel * label；声明标签对象，利用将图片装载到标签上使图片显示在窗口。

​		QLabel::setGeometry()；确定标签的位置和大小，前两个参数为默认位置（默认位置，后面需要通过公式进行修改，因为循环进行一共设置4 * 4 = 16个硬币背景对象），后两个参数为标签的大小，尽量与背景图片的规格保持一致。

​		QLabel::setPixmap();设置标签要显示的图片，接受一个Pixmap类型的图片对象，此处使用的是匿名函数对象。

​		QLabel::setParent()；设置当前控件（标签）的父类为当前窗口，即当前标签的作用控件是当前的窗口。

​		QLabel::move()；移动标签的位置，接受的参数为控件在窗口内的x和y轴坐标，以循环次数的i和j为基准进行公式计算，循环设置一共16个标签对象，x坐标的57是第一个图片的起始位置，i为当前行的第i个图片，50是图片的宽，y坐标的200是第一张图片的初始高度，j是当前第几列的图片，50是图片的高。

```c++
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
```

​		循环设置金币对象，金币一共两种形式，正面和反面，由二维数组的内容决定当前的硬币是正面还是反面。

```c++
            MyCoin * coin = new MyCoin(img);
            coin->setParent(this);
            coin->move(59 + i*50, 204 + j*50);
            coin->poxX = i;
            coin->poxY = j;
            coin->flag = gameArray[i][j];
```

​		MyCoin * coin；实例化硬币对象，放置在背景标签上面，由mycoin的定义可以知道硬币起始也是一个个的按钮，通过重载的构造函数将图片路径传入以确定当前实例化的硬币是正面还是反面。

​		QPushButton::setParent()；设置父类作用域为当前窗口。

​		QPushButton::move()；移动按钮的位置，这里的位置计算公式与背景图片几乎相同，只是硬币要与背景的四周有一定的偏差，达成一种硬币内嵌于背景图片内的视觉效果，这里设置水平偏差值为2，竖直偏差值为4。

​		MyCoin::poxX； MyCoin::poxY；当前硬币的x和y计算，也就是它在矩阵当中的位置（它是矩阵中第i行第j列的硬币对象）这一步的最重要的作用记录当前的硬币的位置用以计算其周围的硬币的位置，当翻动一个硬币的时候能够令其联动周围硬币一起翻动。

​		MyCoin::flag；用以表示当前硬币的正反的bool标志，即从dataconfig文件的二维数组拿到的值，决定这一关的硬币初始态。

下面这一段比较长

```c++
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
                }); //而且是点击的lambda表达式内的Timer的lambda表达式，因为用到了延时启动
            }); //需要额外注意的是，以上所有动作发生在一次点击的一个lambda表达式内
```

​		coinBtn [i] [j] = coin;  此处的coinBtn来自于myCoin文件内定义的coinbtn，目的用于保存当前硬币（按钮）周围的硬币，并且用于下面的连续翻转。

 	connect(coin, &MyCoin::clicked, [=](){  connect为当前按钮（硬币）链接点击的功能，即添加按钮的动作监听，第一个参数就是当前的硬币按钮对象，第二个参数为启动方式为点击，第三个lambda表达式是动作的主体部分。

​		MyCoin::changeFlag();  mycoin内定义的函数，用于同步改变当前硬币对象的正反面flag标志，因为当我们点击这个按钮之后它就要翻面，这时就需要将所有有关它正反面的信息都同步修改，对，所有。

​		gameArray[i][j] = gameArray[i][j] == 0 ? 1 : 0;  这个所有就包括设置它初态的二维数组内的标志，但是二维数组内存储的是当前关卡（页面）内所有的硬币对象的正反面标志，所以它还需要用于判断胜利条件，因此不能简单的做一次修改，此处用到了一个三目运算符，当与初态不同时就修改。

​		QTimer::singleShot(300, this, [=](){  设置Timer计时器，延时启动，同步翻转点击的硬币的周围的硬币对象，第一个参数是延时的时间单位为毫秒，300毫秒是一个比较完美的数值，是一个能够体现出时间的前后顺序而且反应速度较快的数值。第三个为计时器的lambda表达式，其内定义计时结束后需要执行的具体功能，即改变周围的硬币的正反状态。

​		if(coin->poxX + 1 <= 3)   if(coin->poxX - 1 >= 0)   if(coin->poxY+1 <= 3)   if(coin->poxY-1 >= 0)   接连四个if条件判断，分别代表了当前硬币的上下左右四个区域，为反条件是超出了当前的范围限制（整个区域是4 * 4的）。

​		coinBtn[coin->poxX+1] [coin->poxY]->changeFlag();  mycoin内定义x和y的值的用处就在这里，利用其内部定义的x和y的坐标能够很轻松的找出在它四周的硬币对象，然后改变他们的正反面标志flag。

​		gameArray[coin->poxX+1] [coin->poxY] = gameArray[coin->poxX+1] [coin->poxY] == 0 ? 1 : 0;   与改变点击的硬币时的操作相同，不仅需要改变四周硬币内部的flag标志还需要同步改变二维数组内当前位置的硬币的正反面标志信息，方便用于胜利条件的判断。

```c++
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
```

​		默认先给isWin是否胜利的bool值设置为true的初值。循环遍历整个二维数组，如果其中存在至少一个0（false）就将isWin的bool值设置为false。 如果没有0说明所有硬币全都翻了过来，即游戏胜利。

```c++
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
```

​		如果游戏胜利就需要把事先准备的处于窗口以外的胜利图片拿到窗口里面来。

​		qDebug  功能类似于cout，只不过是在控制台打印信息，需要包含头文件#include<QDebug> 包含一次就行，前面包含的文件内已经有文件声明过了。

​		QPropertyAnimation * animation1；创建一个动画对象，因为我们想要实现的是游戏胜利时将胜利图片弹下来到窗口内，而不是瞬移到窗口内突然出现，所以需要一个动画对象来实现这一功能，后面接受的两个参数分别是执行动画效果的控件和默认格式。

​		QPropertyAnimation::setDuration()；设置动画的持续时间，单位为ms

​		QPropertyAnimation::setStartValue()；设置动画的起始位置，接受一个矩阵Rect对象，四个值分别是左上角的坐标和宽高，这里使用的就是之前设置胜利标志的图片的参数。

​		QPropertyAnimation::setEndValue()；设置动画的结束位置，x轴不需要动，y轴移动一个合适的位置即可。

​		QPropertyAnimation::setEasingCurve()；设置动画的缓和曲线，让动画看起来更顺滑一点，请查看帮助文档。

​		QPropertyAnimation::start()；最后最后，千万别忘了让动画启动起来。

```c++
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
```

​		paintEvent(QPaintEvent *)  设置背景板图片，用到画笔事件是因为除了背景板以外还需要设置标题图片。

​		QPainter painter(this);  声明一个画笔对象，参数传入的是父类作用域，即画笔要作用在当前窗口上。

​		QPixmap pix;  声明一个图片图像，用以装载图片。

​		QPainter::drawPixmap()；画图片到窗口上，五个参数分别是左上角坐标和图片的宽高，因为是背景板，所以坐标从整个窗口的左上角开始，大小尽量和图片规格保持一致，最后一个参数是图片本体。

​		QPixmap::scaled(); 一个使用上的小技巧，如果当前的图片规格不是很合适，图片太大了，可以用scaled函数重设图片的规模，可以想象为以图片为基准的resieze。

​		QPainter::drawPixmap()；  画标题图片到窗口内，选择一个合适的位置即可。

**关于游戏场景设计**在上面的过程中我们设置了游戏场景，其中还用到了硬币对象上面没有叙述，但是没问题，马上就要叙述了。在构建整个游戏场景的时候，我们首先设置了整个窗口的框架，因为需要有返回上一个场景的功能，所以游戏场景的框架布局要与选择关卡场景的框架布局一致（连代码都是一样的），在设置完框架之后也需要设置返回按钮的功能，使其能够正常返回上一个场景。而在游戏开始创建之前，首先我们要准备胜利图片，因为胜利图片是在游戏胜利时就要弹下来，所以需要先将其加载出来并且放置在窗口之外。一切工作准备完全之后，就可以正式来到游戏的创建，游戏主体是硬币，包括硬币的正面和反面，以及放置硬币的背景，因为背景无论硬币状态如何都是一样的所以可以先设置背景图片，利用label标签来装载图片显示在窗口内，这里要注意标签的位置摆放。之后开始创建硬币对象放置于背景上，硬币的初始状态由dataconfig文件内的数组决定，dataconfig文件决定了游戏的逻辑。设置完硬币对象之后就需要为每一个硬币connect链接一个动作，当点击它时它会翻转，而且会带动它四周的硬币一块翻转，这里要注意当修改硬币的正反面标志的时候同步要修改二维数组内它的标志状态，以方便后面胜利条件的判断，因为我们也不知道要点几次才会胜利，所以在每一次点击硬币的时候都要进行一次胜利条件的判断，循环遍历整个二维数组，当胜利时将我们早已准备好的胜利图片通过一个动画效果弹下来。这样一个完整的游戏场景就搭建完成了。

----------------------------

​																				**五：硬币的封装**

在上一步搭建游戏场景时我们已经用到了mycoin硬币对象，那么接下来就要详述MyCoin文件内容。

```c++
/*以下为MyCoin.h文件内容*/
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
```

```c++
/*以下为MyCoin.cpp文件内容*/
#include "mycoin.h"
#include<QPixmap>
#include<QDebug>
#include<QTimer>
MyCoin::MyCoin(QWidget *parent)
    : QPushButton{parent}
{

}


MyCoin::MyCoin(QString butImg)
{
    QPixmap pixmap;
    bool ret = pixmap.load(butImg);
    if(!ret)
    {
        qDebug() << "加载图片失败";
    }

    this->setFixedSize(pixmap.width(), pixmap.height());
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(pixmap);
    this->setIconSize(QSize(pixmap.width(), pixmap.height()));

    //初始化定时器
    timer1 = new QTimer(this);
    timer2 = new QTimer(this);

    //监听正面反转的信号槽
    connect(timer1, &QTimer::timeout, [=](){
        QPixmap pixmap;
        QString str = QString(":/res/Coin000%1").arg(this->min++);
        pixmap.load(str);
        this->setFixedSize(pixmap.width(), pixmap.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pixmap);
        this->setIconSize(QSize(pixmap.width(), pixmap.height()));
        if(this->min > this->max)
        {
            //如果大于最大值，重置最小值并停止定时器
            this->min = 1;
            this->isAnimation = false;
            timer1->stop();
        }
    });

    connect(timer2, &QTimer::timeout, [=](){
        QPixmap pixmap;
        QString str = QString(":/res/Coin000%1").arg(this->max--);
        pixmap.load(str);
        this->setFixedSize(pixmap.width(), pixmap.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pixmap);
        this->setIconSize(QSize(pixmap.width(), pixmap.height()));
        if(this->max < this->min)
        {
            //如果小于最小值，重置最大值并停止定时器
            this->max = 8;
            this->isAnimation = false;
            timer2->stop();
        }
    });



}
void MyCoin::changeFlag()
{
    if(this->flag)
    {
        //如果是正面
        timer1->start(30);
        this->isAnimation = true;
        this->flag = false;
    }
    else
    {
        //如果是反面
        timer2->start(30);
        this->isAnimation = true;
        this->flag = true;
    }
}

void MyCoin::mousePressEvent(QMouseEvent *e)
{
    if(this->isAnimation || isWin == true)
    {
        return;
    }
    else
    {
        return QPushButton::mousePressEvent(e);
    }
}
```

**---->**在MyCoin.h文件中

​		class MyCoin : public QPushButton  首先记得继承按钮头文件，因为每一个硬币本质都is-a是一个按钮。

​		explicit MyCoin(QWidget *parent = nullptr);  缺省的构造函数

​		MyCoin(QString butImg);  重载的构造函数，接受一个string对象来加载图片路径，因为硬币有正面和反面两种状态，可以通过传入不同的路径来显示硬币不同的状态。

​		int poxX; //x坐标  int poxY; //y坐标   这里的x和y坐标是硬币在关卡内的4 * 4 矩阵内的相对位置，主要用于决定当前硬币的周围硬币的位置以此来实现同步翻转。

​		bool flag; 当前硬币的正反标志，每一次点击都要修改硬币的正反面状态。

​		void changeFlag();  改变硬币的正反面标志，执行反转效果

​		QTimer *timer1;    执行正面翻反面的动作    QTimer *timer2;  执行反面翻正面的动作。

​		int min = 1;   int max = 8;  最小图片和最大图片，之间为翻转动作的拆分，即以一帧一帧的图片叠加实现动画效果。

​		bool isAnimation = false;  当硬币在执行翻转动作的时候要禁止鼠标点击，只有当当前的翻转动作执行完毕之后方可继续点击。

​		void mousePressEvent(QMouseEvent *e);  鼠标事件监听，用以毙掉鼠标操作。

​		bool isWin = false;  是否胜利的标志，负责管理胜利标志图片的状态。

**---->**在MyCoin.cpp文件中

```c++
MyCoin::MyCoin(QWidget *parent)
    : QPushButton{parent}
{}
```

​		缺省构造，实现is-a效果，让硬币对象”是一个“按钮。

```c++
    //以下动作都发生在构造函数内，即创建对象时这些动作均已执行完毕
    QPixmap pixmap;
    bool ret = pixmap.load(butImg);
    if(!ret)
    {
        qDebug() << "加载图片失败";
    }
```

​		QPixmap pixmap;  声明一个图片对象用于装载硬币图片。

​		QPixmap::load()； 通过构造函数传入的路径参数装载图片，这个函数有一个bool型的返回值，用于判断图片是否装载成功，因为可能会存在图片被删除了的情况。

​		QPixmap::setFixedSize()；设置图片的尺寸规格，尽量与原图片大小相同。

​		QPixmap::setStyleSheet()；设置样式，接受的是一个enum类型的参数，不需要记忆，用的时候，请查阅帮助文档。

​		QPixmap::setIcon() 和 QPixmap::setIconSize()；设置图标和图标的大小。

```c++
    timer1 = new QTimer(this);
    timer2 = new QTimer(this);
```

​		初始化两个定时器，两个定时器在类内已经声明过，一个负责执行正面翻反面的动作，一个负责反面翻正面的动作。分别交给两个动作监听完成。

```c++
    //监听正面反转的信号槽
    connect(timer1, &QTimer::timeout, [=](){
        QPixmap pixmap;
        QString str = QString(":/res/Coin000%1").arg(this->min++);
        pixmap.load(str);
        this->setFixedSize(pixmap.width(), pixmap.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pixmap);
        this->setIconSize(QSize(pixmap.width(), pixmap.height()));
        if(this->min > this->max)
        {
            //如果大于最大值，重置最小值并停止定时器
            this->min = 1;
            this->isAnimation = false;
            timer1->stop();
        }
    });
```

//吐槽：connect链接可以连万事万物

​		connect 链接计时器，执行动作是在计时结束之前连续执行。总所周知，动画就是一帧帧画面的叠加。第一个参数为计时器，第二个参数代表条件为计时结束停止，第三个为计时停止之前循环执行的动作体。

​		QPixmap pixmap; 声明一个图片对象用以装载翻转过程中的每一张图片。

​		QString str = QString(":/res/Coin000%1").arg(this->min++); 传入每一张图片的路径信息，类内定义的最小最大的用处就在此处，以方便于递增，因为connect的Timer体内是在计时结束前循环执行。

​		QPixmap::setFixedSize、setStyleSheet、setIcon、setIconSize 设置图片大小，风格，图标，图标大小，与前面任何一个图片的设置并无区别。

​		if(this->min > this->max)  判断条件，如果递增到了最大值图片，说明翻转的过程执行完毕了。

​		this->min = 1;  记得将最小值重置，以用于下一次翻转。

​		MyCoin::isAnimation = false;  动作执行完毕了，动画播完了，鼠标就可以动了。

​		timer1->stop();  翻转过程结束，停止当前计时器，结束循环。

```c++
    connect(timer2, &QTimer::timeout, [=](){
        QPixmap pixmap;
        QString str = QString(":/res/Coin000%1").arg(this->max--);
        pixmap.load(str);
        this->setFixedSize(pixmap.width(), pixmap.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pixmap);
        this->setIconSize(QSize(pixmap.width(), pixmap.height()));
        if(this->max < this->min)
        {
            //如果小于最小值，重置最大值并停止定时器
            this->max = 8;
            this->isAnimation = false;
            timer2->stop();
        }
    });
```

​		正面翻反面，反面翻正面，两个过程除了图片不一样（反着来），退出条件不一样（倒着来），其他没有区别。

```c++
void MyCoin::changeFlag()
{
    if(this->flag)
    {
        //如果是正面
        timer1->start(30);
        this->isAnimation = true;
        this->flag = false;
    }
    else
    {
        //如果是反面
        timer2->start(30);
        this->isAnimation = true;
        this->flag = true;
    }
}
```

​		void MyCoin::changeFlag()  改变当前硬币的正反面状态标志，每点击以此，执行一次，改变一次正反面。

​		if(this->flag)  判断当前是正面还是反面，以此启动不同的动画播片过程（就是timer1和timer2的区别）

​		timer1->start(30);  启动计时器，并且赋值计时30ms，前面使用计时器都没有给它设置初值就是因为在这里传入的初值。

​		this->isAnimation = true;  设置当前正在播片（翻转动画正在执行），并以此为标志禁止鼠标动作。

​		this->flag = false; 正面翻转完毕之后就是反面，要修改正反面标志。

​		反面的也一样，只不过启动的是timer2，翻转执行完毕之后是正面。

```c++
void MyCoin::mousePressEvent(QMouseEvent *e)
{
    if(this->isAnimation || isWin == true)
    {
        return;
    }
    else
    {
        return QPushButton::mousePressEvent(e);
    }
}
```

​		鼠标事件监听，用到前面的isAnimation的标志位，使翻转动作执行过程中禁止鼠标点击，同时还有一个参数是isWin标志，代表当游戏胜利之后，胜利标志弹下来到窗口内之后同样禁止鼠标点击。

-----------------------------------------

​				最后的最后，加上启动用的main文件

```c++
/*以下为main.cpp*/
#include "mainscene.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainScene w;
    w.show();
    return a.exec();
}
```

**至此，美琴翻翻乐的说明文档，全文结束**

https://github.com/kuuhaku0721/own_study_memory

//中间有很多不够完善不够正确不够准确的内容，仅供参考交流使用
