#ifndef MAINUI_H
#define MAINUI_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include <QStringList>
#include <QLineEdit>
#include <QProcess>

class mainui : public QWidget
{
    Q_OBJECT
public:
    explicit mainui(QWidget *parent = nullptr);
    QLabel *titleLabel;
    QVBoxLayout *m_pmainlayout = nullptr;

    QWidget *m_pathWidget;
    QWidget *m_changeWidget;

    QHBoxLayout *m_pathlayout = nullptr;
    QHBoxLayout *m_changelayout = nullptr;
    QPushButton *fileButton;


    QPushButton * changeLogButton;
    QPushButton * controlButton;
    QPushButton * startButton;
    QLineEdit   * pathEdit;




private:
    QStringList listFile;

signals:

protected slots:
    void fileButtonClick();
    void controlButtonClick();
    void changeLogButtonClick();
    void startButtonClick();
    void processFinished();

};

#endif // MAINUI_H
