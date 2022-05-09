#ifndef VIEWMAINWINDOW_H
#define VIEWMAINWINDOW_H

#include <QMainWindow>
#include <QTranslator>

QT_BEGIN_NAMESPACE
namespace Ui { class ViewMainWindow; }
QT_END_NAMESPACE

class ViewMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    ViewMainWindow(QWidget *parent = nullptr);
    ~ViewMainWindow();

private slots:
    void on_actionFechar_aplicacao_triggered();

    void on_actionConsultar_novelas_triggered();

    void on_actionIngles_triggered();

    void on_actionPortugues_triggered();

private:
    Ui::ViewMainWindow *ui;
     QTranslator translator;

signals:
   void consultarNovelas();

};
#endif // VIEWMAINWINDOW_H
