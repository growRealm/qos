#include "uilogindialog.h"
#include "src/bend/man/mandb.h"
#include "src/config/common.h"
#include "ui_uilogindialog.h"

#include <QMessageBox>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QCompleter>
#include <QJsonObject>

UiLoginDialog::UiLoginDialog(QWidget *parent)
    : UiQosDialog(parent)
    , ui(new Ui::UiLoginDialog)
{
    ui->setupUi(body());

    setTitle(STR("登录"));
    ui->btnLogin->setDefault(true);

    ui->labelLoginName->setProperty("style_font", "h5");
    ui->labelSecretId->setProperty("style_font", "h5");
    ui->labelSecretKey->setProperty("style_font", "h5");
    ui->labelRemark->setProperty("style_font", "h5");

    ui->btnLogin->setProperty("style_font", "h5");
    ui->btnLogin->setProperty("style_button", "main");


    connect(ui->btnLogin, &QPushButton::clicked, this, &UiLoginDialog::onBtnLoginClicked);

    connect(MG->mSignal, &ManSignals::loginSuccess, this, &UiLoginDialog::onLoginSucceed);
    connect(MG->mSignal, &ManSignals::unLogin, this, &UiLoginDialog::show);
    connect(MG->mSignal, &ManSignals::error, this, &UiLoginDialog::onLoginError);
    updateLoginInfo();

    resize(400,  450);
}

UiLoginDialog::~UiLoginDialog()
{
    delete ui;
}

void UiLoginDialog::updateLoginInfo()
{
    QStringList words = MG->mDb->loginNameList();
    ui->lineLoginName->setWords(words);

    connect(ui->lineLoginName, &UiComboLine::itemSelected,
            [=](const QString& name){
                LoginInfo info = MG->mDb->loginInfoByName(name);
                ui->lineSecretId->setText(info.secret_id);
                ui->lineSecretKey->setText(info.secret_key);
                ui->lineRemark->setText(info.remark);
                ui->checkSaveSection->setChecked(true);
            });
}

bool UiLoginDialog::eventFilter(QObject *watched, QEvent *event)
{
    // watched 表示需要关注的控件对象
    // event 表示传递给事件对象的事件
    if (watched == ui->lineSecretKey)
    {
        if (event->type() == QEvent::KeyPress)
        {
            QKeyEvent * keyEvent = static_cast<QKeyEvent*>(event);
            if (keyEvent->modifiers() == Qt::ControlModifier)
            {
                if (keyEvent->key() == Qt::Key_C || keyEvent->key() == Qt::Key_V)
                {
                    return true;  // true-事件已经被处理，不再往下传递；false-继续执行传递
                }
            }
        }
    }

    return QDialog::eventFilter(watched, event);
}

void UiLoginDialog::onBtnLoginClicked()
{
    QJsonObject params;
    params["secretId"] = ui->lineSecretId->text().trimmed();
    params["secretKey"] = ui->lineSecretKey->text().trimmed();
    MG->mGate->send(API::LOGIN::NORMAL, params);
}

void UiLoginDialog::onLoginSucceed()
{
    if (ui->checkSaveSection->isChecked())
    {
        //保存登录信息
        MG->mDb->saveLoginInfo(
            ui->lineLoginName->text(),
            ui->lineSecretId->text(),
            ui->lineSecretKey->text(),
            ui->lineRemark->text()
            );
        updateLoginInfo();
    }
    else
    {
        //删除登录信息
        MG->mDb->removeLoginInfo(ui->lineSecretId->text());
    }
    accept();
}

void UiLoginDialog::onLoginError(int api, const QString &msg, const QJsonValue &req)
{
    Q_UNUSED(req)
    if (api != API::LOGIN::NORMAL)
        return;
    QMessageBox::warning(
        this, STR("登录失败"),
        STR("登录失败：%1").arg(msg));
}
