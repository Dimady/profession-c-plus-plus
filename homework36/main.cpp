#include <iostream>
#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QSlider>
#include <QObject>
#include <QPaintEvent>
#include <QPushButton>
#include <QPixmap>
#include <QPainter>

class PushButton: public QPushButton {
public:
    PushButton() = default;
    PushButton(QWidget *parent);
    void paintEvent(QPaintEvent *e) override;
    QSize minimumSizeHint() const override;
    void setRed();
    void setYellow();
    void setGreen();
    QPixmap mPushButtonRed;
    QPixmap mPushButtonGreen;
    QPixmap mPushButtonYellow;
    QPixmap mPushButtonColorCurrent;
};

PushButton::PushButton::PushButton(QWidget *parent) {
    setParent(parent);
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    mPushButtonRed = QPixmap("opt/red.png");
    mPushButtonGreen = QPixmap("opt/green.png");
    mPushButtonYellow = QPixmap("opt/yellow.png");
    mPushButtonColorCurrent = mPushButtonGreen;
    setGeometry(mPushButtonColorCurrent.rect());
}

void PushButton::paintEvent(QPaintEvent *e) {
    QPainter p(this);
    p.drawPixmap(e->rect(), mPushButtonColorCurrent);
}

QSize PushButton::minimumSizeHint() const {
    return QSize(2500, 2500);
}

void PushButton::setRed() {
    mPushButtonColorCurrent = mPushButtonRed;
    update();
}

void PushButton::setGreen() {
    mPushButtonColorCurrent = mPushButtonGreen;
    update();
}

void PushButton::setYellow() {
    mPushButtonColorCurrent = mPushButtonYellow;
    update();
}

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QWidget *window = new QWidget;
    QWidget *pushbutton = new PushButton(window);
    pushbutton->setToolTip("SkillBox");
    QSlider *slider = new QSlider(Qt::Horizontal, window);
    slider->setMinimum(0);
    slider->setMaximum(100);
    QVBoxLayout *layout = new QVBoxLayout(window);
    layout->addWidget(pushbutton);
    layout->addWidget(slider);
    QObject::connect(slider, &QSlider::valueChanged, [pushbutton, slider](int newValue) {
        PushButton *c = dynamic_cast<PushButton*>(pushbutton);
        if (c) {
            if (newValue >= 0 && newValue < 33)
                c->setGreen();
            else if (newValue >= 33 && newValue < 66)
                c->setYellow();
            else if (newValue >= 66 && newValue <= 100)
                c->setRed();
        }
    });
    window->setFixedSize(500, 500);
    window->show();
    return a.exec();
}