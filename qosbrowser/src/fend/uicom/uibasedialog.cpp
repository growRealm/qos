﻿#include "uibasedialog.h"
#include "ui_uibasedialog.h"

#include <QMouseEvent>
#include <QKeyEvent>
#include <QPushButton>
#include <QKeyEvent>


UiBaseDialog::UiBaseDialog(QWidget *parent)
    : QDialog(parent)
    , m_ui(new Ui::UiBaseDialog)
{
    m_ui->setupUi(this);
    setWindowFlags(Qt::CustomizeWindowHint|Qt::Window);

    setLogo(":/static/imgs/qtlogo.png");
    addCloseButton(":/static/imgs/Close-1.png", ":/static/imgs/Close-2.png");
    setAllButtonSize();
    m_ui->labelLogo->setFixedSize(28, 28);
}

UiBaseDialog::~UiBaseDialog()
{
    delete m_ui;
}

void UiBaseDialog::setTitle(const QString &title)
{
    m_ui->labelTitle->setText(title);
}

void UiBaseDialog::setLogo(const QString &path)
{
    m_ui->labelLogo->setStyleSheet(QString("border-image: url(\"%1\");").arg(path));
}

void UiBaseDialog::addMinButton(const QString &path, const QString &hoverPath)
{
    QPushButton* btn = addButton(path, hoverPath);
    connect(btn, &QPushButton::clicked, this, &UiBaseDialog::showMinimized);
}

void UiBaseDialog::addMaxButton(const QString &maxPath, const QString &maxPathHover,
                              const QString &normalPath, const QString &normalPathHover)
{
    QPushButton* btn = addButton(maxPath, maxPathHover);

    auto funcImg = [=]() {
        isMaximized() ? setButtonImage(btn, normalPath, normalPathHover)
                      : setButtonImage(btn, maxPath, maxPathHover);
    };
    auto funcShow  = [=]() {
        isMaximized() ? showNormal() : showMaximized();
        funcImg();
    };

    connect(btn, &QPushButton::clicked, this, funcShow);
    funcImg();
}

QPushButton *UiBaseDialog::addButton(const QString &path, const QString &hoverPath)
{
    UiPushButton* btn = new UiPushButton;
    btn->setFixedSize(m_sz, m_sz);
    setButtonImage(btn, path, hoverPath);
    addWidget(btn);
    return btn;
}

void UiBaseDialog::setButtonImage(QPushButton *btn, const QString &path, const QString &hoverPath)
{
    btn->setStyleSheet(QString(
        "QPushButton{border-image: url(\"%1\");}"
        "QPushButton:hover{border-image: url(\"%2\");}"
        ).arg(path, hoverPath));
}

void UiBaseDialog::setAllButtonSize(int w)
{
    QList<QPushButton *> btnList = m_ui->frameTitle->findChildren<QPushButton*>();
    for (auto* btn: btnList) {
        btn->setFixedSize(w, w);
    }
    m_sz = w;
}

void UiBaseDialog::setKeyDisabled()
{
    installEventFilter(this);
}

void UiBaseDialog::addTitleLine(int w)
{
    QLabel* label = new QLabel;
    label->setFixedSize(w, 15);
    addWidget(label);
}

void UiBaseDialog::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton){
        m_start = event->pos(); // 相对于父控件坐标原点的位置
    }
    QDialog::mousePressEvent(event);
}

void UiBaseDialog::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton){
        QPoint targetPos = event->pos()-m_start+pos();
        this->move(targetPos);
    }
    QDialog::mouseMoveEvent(event);
}

bool UiBaseDialog::eventFilter(QObject *obj, QEvent *event)
{
    UiBaseDialog *pDialog = qobject_cast<UiBaseDialog *>(obj);
    if (pDialog && event->type() == QEvent::KeyPress) {
        QKeyEvent *pKeyEvent = static_cast<QKeyEvent*>(event);
        if (pKeyEvent->key() == Qt::Key_Return
            || pKeyEvent->key() == Qt::Key_Escape
            || pKeyEvent->key() == Qt::Key_Enter) {
            return true;
        }
    }
    return QObject::eventFilter(obj, event);
}

QWidget *UiBaseDialog::body()
{
    return m_ui->widgetBody;
}

void UiBaseDialog::addCloseButton(const QString &path, const QString &hoverPath)
{
    setButtonImage(m_ui->btnClose, path, hoverPath);
    m_ui->horizontalLayout->addWidget(m_ui->btnClose);
    connect(m_ui->btnClose, &QPushButton::clicked, this, &UiBaseDialog::reject);
}

void UiBaseDialog::addWidget(QWidget *w)
{
    int i = m_ui->horizontalLayout->indexOf(m_ui->btnClose);
    m_ui->horizontalLayout->insertWidget(i, w);
}

