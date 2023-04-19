#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void copyFormat();
    void applyFormat();
    void setFont();
    void setLeftAlignment();
    void setCenterAlignment();
    void setRightAlignment();

private:
    QTextEdit *textEdit;
    QTextCharFormat format;
};
#endif // MAINWINDOW_H
