#include "uipagewidget.h"
#include "qmath.h"
#include "ui_uipagewidget.h"
#include <QDebug>

UiPageWidget::UiPageWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UiPageWidget)
{
    ui->setupUi(this);
    connect(ui->btnNext, &QPushButton::clicked, this, &UiPageWidget::next);
    connect(ui->btnPre, &QPushButton::clicked, this, &UiPageWidget::pre);

    ui->lineMaxRows->setAlignment(Qt::AlignHCenter);
    ui->lineMaxRows->setReadOnly(true);
    connect(ui->lineMaxRows, &UiComboLine::itemSelected, this, &UiPageWidget::onMaxRowsItemSelected);

    ui->lineCurrentPage->setAlignment(Qt::AlignHCenter);
    ui->lineCurrentPage->setReadOnly(true);
    connect(ui->lineCurrentPage, &UiComboLine::itemSelected, this, &UiPageWidget::onCurrentPageSelected);
    ui->btnNext->setDisabled(true);
    ui->btnPre->setDisabled(true);

    ui->lineCurrentPage->setProperty("style_frame", "bottomframe");
    ui->lineMaxRows->setProperty("style_frame", "bottomframe");
}

UiPageWidget::~UiPageWidget()
{
    delete ui;
}

int UiPageWidget::totalRow() const
{
    return m_totalRow;
}

int UiPageWidget::maxRow() const
{
    return m_maxRow;
}

int UiPageWidget::currentPage() const
{
    return m_currentPage;
}

int UiPageWidget::pageCount() const
{
    if (m_totalRow == 0) {
        return 1;
    }
    // qCeil 获取不小于v的最小整数。
    // total=20, max=10, pages=2；
    // total=19, max=10, pages=2;
    // total=21, max=10, pages=3;
    return qCeil(m_totalRow/float(m_maxRow));
}

int UiPageWidget::isFirstPage() const
{
    return currentPage() == 1;
}

int UiPageWidget::isLastPage() const
{
    return currentPage() == pageCount();
}

void UiPageWidget::setTotalRow(int newTotalRow)
{
    m_totalRow = newTotalRow;
    ui->label->setText(QString("共%1条， 每页").arg(newTotalRow));
    reset();
}

void UiPageWidget::setMaxRow(int rows)
{
    QStringList words = ui->lineMaxRows->getWords();
    for(const auto& num: qAsConst(words)) {
        if (num.toInt() == rows) {
            m_maxRow = rows;
            reset();
            break;
        }
    }
}

void UiPageWidget::setMaxRowList(const QList<int> rowList)
{
    ui->lineMaxRows->setWords(rowList);
    if (rowList.size() > 0) {
        ui->lineMaxRows->setText(QString::number(rowList[0]));
        setMaxRow(rowList[0]);
    }
}

void UiPageWidget::next()
{
    jumpTo(currentPage()+1);
}

void UiPageWidget::pre()
{
    jumpTo(currentPage()-1);
}

void UiPageWidget::jumpTo(int page)
{
    if (page != currentPage()) {
        switchPage(page);
    }
}

void UiPageWidget::onCurrentPageSelected(const QString &text)
{
    if (m_currentPage != text.toInt())
        jumpTo(text.toInt());
}

void UiPageWidget::onMaxRowsItemSelected(const QString &text)
{
    setMaxRow(text.toInt());
}

void UiPageWidget::reset()
{
    setPageCount();
    switchPage(1); // 重置为首页
}

void UiPageWidget::switchPage(int newCurrentPage)
{
    m_currentPage = newCurrentPage;
    ui->lineCurrentPage->setText(QString::number(newCurrentPage));
    ui->btnPre->setDisabled(isFirstPage());
    ui->btnNext->setDisabled(isLastPage());

    int start = (newCurrentPage-1)*maxRow();
    int left = (totalRow())-start;
    int len = left<maxRow()? left :maxRow();
    qDebug() << QString("switchPage %1,%2").arg(start).arg(len);
    emit pageNumChanged(start, len);
}

void UiPageWidget::setPageCount()
{
    int count = pageCount();
    ui->labelPageCount->setText("/" + QString::number(count));
    ui->lineCurrentPage->setWords(1, count);
    ui->lineCurrentPage->setText("1");
}









