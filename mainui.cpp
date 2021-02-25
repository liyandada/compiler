#include "mainui.h"
#include "qfile.h"
#include "qtextstream.h"
#include "qfiledialog.h"
#include "qfileinfo.h"
#include <QDebug>

mainui::mainui(QWidget *parent) : QWidget(parent)
{
    m_pmainlayout = new QVBoxLayout();

    m_pathWidget = new QWidget();
    m_changeWidget = new QWidget();
    m_pathlayout = new QHBoxLayout();
    m_changelayout = new QHBoxLayout();

    titleLabel = new QLabel();
    titleLabel->setText("编译助手2.0");

    pathEdit = new QLineEdit();

    fileButton = new QPushButton();
    fileButton->setText("选择要编译的文件夹");
    connect(fileButton,&QPushButton::clicked,this,&mainui::fileButtonClick);

    changeLogButton = new QPushButton();
    changeLogButton->setText("更改changelog文件");
    connect(changeLogButton,&QPushButton::clicked,this,&mainui::changeLogButtonClick);

    controlButton = new QPushButton();
    controlButton->setText("更改control文件");
    connect(controlButton,&QPushButton::clicked,this,&mainui::controlButtonClick);

    startButton = new QPushButton();
    startButton->setText("开始编译");
    connect(startButton,&QPushButton::clicked,this,&mainui::startButtonClick);

    m_pathlayout->addWidget(pathEdit);
    m_pathlayout->addWidget(fileButton);
    m_pathWidget->setLayout(m_pathlayout);

    m_changelayout->addWidget(changeLogButton);
    m_changelayout->addWidget(controlButton);
    m_changeWidget->setLayout(m_changelayout);

    m_pmainlayout->addWidget(titleLabel);
    m_pmainlayout->addWidget(m_pathWidget);
    m_pmainlayout->addWidget(m_changeWidget);
    m_pmainlayout->addWidget(startButton);
    this->setLayout(m_pmainlayout);

}

void mainui::fileButtonClick()
{
    QString path = QFileDialog::getExistingDirectory(this, "选择目录", "./",  QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if (!path.isEmpty()) {
        qDebug()<<path;
        pathEdit->setText(path);

    }
}

void mainui::controlButtonClick()
{
    QProcess *p = new QProcess(this);
    QString arg=QString("gedit %1%2").arg(pathEdit->text()).arg("/debian/control");
    p->startDetached(arg);
    p->waitForStarted();

}

void mainui::changeLogButtonClick()
{
     QProcess *p = new QProcess(this);
     QString arg=QString("gedit %1%2").arg(pathEdit->text()).arg("/debian/changelog");
     p->startDetached(arg);
     p->waitForStarted();
}

void mainui::startButtonClick()
{
    QProcess *p = new QProcess(this);
    p->setWorkingDirectory(pathEdit->text());
    connect(p,&QProcess::readChannelFinished,this,&mainui::processFinished);
    qDebug()<<pathEdit->text();
//    QString path= QString("debuild %1 %2").arg(pathEdit->text()).arg("-j12");
    QString path= QString("debuild %1 %2").arg(pathEdit->text()).arg("-j12");

    p->start("debuild",QStringList()<<"-j12");
    p->waitForStarted();
}

void mainui::processFinished()
{
    qDebug()<<"ok";
}
