#ifndef SETTINGCONTENT_H
#define SETTINGCONTENT_H

#include <QFrame>
#include <QListWidget>
#include <QStackedWidget>

namespace Ui {
class SettingContent;
}

class SettingContent : public QFrame
{
    Q_OBJECT

public:
    explicit SettingContent(QFrame *parent = 0);
    ~SettingContent();

private:
    QListWidget *styleSelect;
 QStackedWidget *styleContent;

private:
    Ui::SettingContent *ui;
};

#endif // SETTINGCONTENT_H
