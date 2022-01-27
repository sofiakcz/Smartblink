#include "gui.h"

Gui::Gui(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    LEDs = new Gpio(this);
    state = 0;
    zeit = new QTimer();
    connect(zeit, &QTimer::timeout, this, &Gui::toggle);
    zeit->start(TIMEOUT);
}

void Gui::on_speedSlider_valueChanged(int wert)
{
    zeit->start(1000 /wert);
}

void Gui::on_blinkButton_clicked()
{
    blinkrun = 1;
}

void Gui::on_lauflichtButton_clicked()
{
    blinkrun = 0;
    zaehler = 1;
}

void Gui::toggle()
{
    state = !state;

    if(blinkrun == 1)
    {
        if(state == 1)
            zaehler = 15;

        else
            zaehler = 0;

        LEDs->set(zaehler);
    }

    if(blinkrun == 0)
    {
        LEDs->set(zaehler);
            if(zaehler < 8)
                zaehler = zaehler * 2;
            else
                zaehler = 1;
    }
}
