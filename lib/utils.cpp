#include "utils.h"

void Utils::say_hello() {
    std::cout << "hello\n";
}

Screenshot::Screenshot() : screenshotLabel(new QLabel(this)) {
    screenshotLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    screenshotLabel->setAlignment(Qt::AlignCenter);

    const QRect screenGeometry = QApplication::desktop()->screenGeometry(this);
    screenshotLabel->setMinimumSize(screenGeometry.width() / 8, screenGeometry.height() / 8);

    QBoxLayout *mainLayout = new QBoxLayout(QBoxLayout::TopToBottom, this);
    mainLayout->addWidget(screenshotLabel);

    QGroupBox *optionsGroupBox = new QGroupBox(tr("Options"), this);
    
    hideThisWindowCheckbox = new QCheckBox(tr("Hide This Window"), optionsGroupBox);

    QGridLayout *optionsGroupBoxLayout = new QGridLayout(optionsGroupBox);
    optionsGroupBoxLayout->addWidget(new QLabel(tr("Delay:")), 0, 0);
    optionsGroupBoxLayout->addWidget(hideThisWindowCheckbox, 1, 0, 1, 2);

    mainLayout->addWidget(optionsGroupBox);

    QHBoxLayout *buttonsLayout = new QHBoxLayout;
    newScreenshotButton = new QPushButton(tr("New Screenshot"), this);

    connect(newScreenshotButton, &QPushButton::clicked, this, &Screenshot::newScreenshot);
    buttonsLayout->addWidget(newScreenshotButton);
    QPushButton *saveScreenshotButton = new QPushButton(tr("Save Screenshot"), this);
    connect(saveScreenshotButton, &QPushButton::clicked, this, &Screenshot::saveScreenshot);
    buttonsLayout->addWidget(saveScreenshotButton);
    QPushButton *quitScreenshotButton = new QPushButton(tr("Quit"), this);
    quitScreenshotButton->setShortcut(Qt::CTRL | Qt::Key_Q);
    connect(quitScreenshotButton, &QPushButton::clicked, this, &QWidget::close);
    buttonsLayout->addWidget(quitScreenshotButton);
    buttonsLayout->addStretch();
    mainLayout->addLayout(buttonsLayout);

    shootScreen();
    setWindowTitle(tr("Screenshot"));
    resize(300, 200);
}

void Screenshot::resizeEvent(QResizeEvent *) {
    QSize scaledSize = originalPixmap.size();
    scaledSize.scale(screenshotLabel->size(), Qt::KeepAspectRatio);
    if (scaledSize != screenshotLabel->pixmap(Qt::ReturnByValue).size()) {
        updateScreenshotLabel();
    }
}

void Screenshot::newScreenshot() {
    if (hideThisWindowCheckbox->isChecked()) {
        hide();
    }
    newScreenshotButton->setDisabled(true);
}

void Screenshot::saveScreenshot() {

}

void Screenshot::shootScreen() {
    QScreen *screen = QGuiApplication::primaryScreen();
    if (const QWindow *window = windowHandle()) {
        screen = window->screen();
    }
    if (!screen) {
        return;
    }
    originalPixmap = screen->grabWindow(0);
    updateScreenshotLabel();

    newScreenshotButton->setDisabled(false);
    if (hideThisWindowCheckbox->isChecked()) {
        show();
    }
}

void Screenshot::updateCheckbox() {
    hideThisWindowCheckbox->setDisabled(false);
}

void Screenshot::updateScreenshotLabel() {
    screenshotLabel->setPixmap(originalPixmap.scaled(screenshotLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
}