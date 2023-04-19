#include "mainwindow.h"
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    textEdit = new QTextEdit(this);
    textEdit->document()->setDefaultFont(QFont("Lucida Console", 12, QFont::Normal));
    setCentralWidget(textEdit);

    QToolBar *toolBar = addToolBar("Форматировать");
    QMenu *menu = new QMenu(this);

    QAction *copyFmtAction = menu->addAction(tr("Копировать формат"));
    connect(copyFmtAction, SIGNAL(triggered()), this, SLOT(copyFormat()));

    QAction *applyFmtAction = menu->addAction(tr("Применить формат"));
    connect(applyFmtAction, SIGNAL(triggered()), this, SLOT(applyFormat()));

    QAction *fontAction = menu->addAction(tr("Выбрать шрифт"));
    connect(fontAction, SIGNAL(triggered()), this, SLOT(setFont()));

    QMenu *alignSubMenu = menu->addMenu(tr("Выравнивание текста"));
    QAction *leftAction = alignSubMenu->addAction(tr("По левому краю"));
    connect(leftAction, SIGNAL(triggered()), this, SLOT(setLeftAlignment()));
    QAction *centerAction = alignSubMenu->addAction(tr("По цнетру"));
    connect(centerAction, SIGNAL(triggered()), this, SLOT(setCenterAlignment()));
    QAction *rightAction = alignSubMenu->addAction(tr("По правому краю"));
    connect(rightAction, SIGNAL(triggered()), this, SLOT(setRightAlignment()));


    QPushButton *button = new QPushButton(tr("Меню форматирования"), this);
    toolBar->addWidget(button);
    button->setMenu(menu);
    srand(clock());
}

MainWindow::~MainWindow()
{
}

/*
 * a. возможность копировать формат фрагмента текста и применять к другому фрагменту.
*/

void MainWindow::copyFormat()
{
    format = textEdit->textCursor().charFormat();
}

void MainWindow::applyFormat()
{
    textEdit->textCursor().setCharFormat(format);
}

/*
 * b. возможность выравнивания текста по правому и левому краю, а также по центру.
*/

void MainWindow::setLeftAlignment()
{
    QTextCursor cursor = textEdit->textCursor();
    QTextBlockFormat textBlockFormat = cursor.blockFormat();
    textBlockFormat.setAlignment(Qt::AlignLeft);
    cursor.mergeBlockFormat(textBlockFormat);
    textEdit->setTextCursor(cursor);
}

void MainWindow::setCenterAlignment()
{
    QTextCursor cursor = textEdit->textCursor();
    QTextBlockFormat textBlockFormat = cursor.blockFormat();
    textBlockFormat.setAlignment(Qt::AlignCenter);
    cursor.mergeBlockFormat(textBlockFormat);
    textEdit->setTextCursor(cursor);
}

void MainWindow::setRightAlignment()
{
    QTextCursor cursor = textEdit->textCursor();
    QTextBlockFormat textBlockFormat = cursor.blockFormat();
    textBlockFormat.setAlignment(Qt::AlignRight);
    cursor.mergeBlockFormat(textBlockFormat);
    textEdit->setTextCursor(cursor);
}

/*
 * c. возможность выбора шрифта.
*/

void MainWindow::setFont()
{
    QFont font = textEdit->textCursor().charFormat().font();

    QFontDialog fontDialog(font, this);
    bool b[] = {true};
    font = fontDialog.getFont(b);
    if (b[0]) {
        QTextCharFormat fmt;
        fmt.setFont(font);
        textEdit->textCursor().setCharFormat(fmt);
    }
}

