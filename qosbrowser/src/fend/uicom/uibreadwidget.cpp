﻿#include "uibreadwidget.h"
#include "ui_uibreadwidget.h"

#include <QLabel>
#include <QDebug>

UiBreadWidget::UiBreadWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UiBreadWidget)
{
    ui->setupUi(this);
    ui->listView->setModel(m_model);
    ui->listView->setFlow(QListView::LeftToRight);
    setPath("");
    connect(ui->listView, &QListView::clicked, this, &UiBreadWidget::onItemClicked);
    setFixedHeight(30);

    ui->listView->setCursor(Qt::PointingHandCursor);
}

UiBreadWidget::~UiBreadWidget()
{
    delete ui;
}

void UiBreadWidget::setPath(const QString &path)
{
    setPath(path.split("/", Qt::SkipEmptyParts));
}

void UiBreadWidget::setPath(const QStringList &names)
{
    // 传入的目录名称不能为空
    if (names.size() == 0) {
        return;
    }
    clear();
    m_rootName = names[0];
    for (const QString& name: names) {
        addNameButton(name.trimmed());
    }
}

void UiBreadWidget::clear()
{
    m_model->clear();
}

QString UiBreadWidget::currentPath() const
{
    return getPath();
}

QString UiBreadWidget::rootName() const
{
    return m_rootName;
}

bool UiBreadWidget::isEmpty() const
{
    return ui->listView->model()->rowCount() == 0;
}

bool UiBreadWidget::isRoot() const
{
    return getPath() == m_rootName;
}

void UiBreadWidget::addNameButton(const QString &name)
{
    if (name == "")
        return;

    QStandardItem *item = new QStandardItem;
    item->setText(name);
    if (!isEmpty()) {
        item->setIcon(QIcon(":/static/imgs/right.png")); // 向右箭头
    }

    m_model->appendRow(item);
}

void UiBreadWidget::onItemClicked(const QModelIndex &index)
{
    QStandardItem* newItem = m_model->itemFromIndex(index);
    QStandardItem* oldItem = currentItem();

    if (newItem == oldItem) {
        QString oldPath = getPath(oldItem);
        emit refresh(oldPath);
        qDebug() << "refresh" << oldPath;
    }
    else {
        QString newPath = getPath(newItem);
//        int idx = newItem->row();
//        m_model->removeRows(idx+1, m_model->rowCount()-(idx+1));
        emit pathChanged(newPath);
        qDebug() << "pathChange" << newPath;
    }
}

QStandardItem* UiBreadWidget::currentItem() const
{
    return m_model->item(m_model->rowCount()-1);
}

QString UiBreadWidget::getPath(QStandardItem *item) const
{
    if (!item) {
        item = currentItem();
    }

    int idx = item->row();
    QStringList pathList;
    for (int i = 0; i <= idx; i++) {
        QStandardItem* b = m_model->item(i);
        if (b) {
            pathList << b->text();
        }
    }
    return pathList.join("/");
}
