﻿#ifndef UIPAGEWIDGET_H
#define UIPAGEWIDGET_H

#include <QWidget>

namespace Ui {
class UiPageWidget;
}

class UiPageWidget : public QWidget
{
    Q_OBJECT

public:
    explicit UiPageWidget(QWidget *parent = nullptr);
    ~UiPageWidget();

    // 获取属性值，相关方法
    int totalRow() const;
    int maxRow() const;
    int currentPage() const;
    int pageCount() const;
    int isFirstPage() const;
    int isLastPage() const;

    // 设置属性值，相关方法，如下两个方法会触发reset信号
    void setTotalRow(int newTotalRow);
    // 设置当前单页最大显示行数
    void setMaxRow(int rows);
    // 设置单页显示行数选择列表，它是属于初始化部分
    void setMaxRowList(const QList<int> rowList);

signals:
    // 页码发生变化，start-起始索引，len每页最大条数
    void pageNumChanged(int start, int maxLen);

public slots:
    void next();
    void pre();
    void jumpTo(int page);

private slots:
    void onCurrentPageSelected(const QString& text);
    void onMaxRowsItemSelected(const QString &text);

private:
    // 设置页号选择列表，它是属于初始化部分，不会触发信号
    void setPageCount();
    // 重置为首页
    void reset();
    // 切换页码
    void switchPage(int newCurrentPage);

private:
    Ui::UiPageWidget *ui;
    int m_totalRow = 0; // 总共有多少行
    int m_currentPage = 1;  // 当前是第几页
    int m_maxRow = 10;  //每一页有多少行
};

#endif // UIPAGEWIDGET_H
