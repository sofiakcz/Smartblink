#ifndef GUI_H
#define GUI_H

#include <QWidget>

#include "ui_gui.h"

// andere dateien inkludieren
#include "gpio.h"
#include <QTimer>

const int TIMEOUT = 1000;

class Gui : public QWidget, private Ui::Gui
{
    Q_OBJECT

public:
    explicit Gui(QWidget *parent = nullptr);

private slots:
    void on_speedSlider_valueChanged(int wert);
    void on_blinkButton_clicked();
    void on_lauflichtButton_clicked();
    void toggle();

private:
    QTimer* zeit;
    bool state = 0;
    bool blinkrun = 1;
    unsigned int zaehler = 1;
    Gpio* LEDs;
};

#endif // GUI_H
