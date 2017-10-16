/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_2;
    QAction *actionv1_0;
    QWidget *centralWidget;
    QGridLayout *gridLayout_12;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *openFile;
    QLabel *label;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pathSave;
    QLabel *pathSave_2;
    QLabel *label_12;
    QLineEdit *lineEdit;
    QGridLayout *gridLayout_10;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout_4;
    QLabel *label_2;
    QLineEdit *razrab;
    QGridLayout *gridLayout_3;
    QLabel *label_3;
    QLineEdit *prov;
    QGridLayout *gridLayout_2;
    QLabel *label_5;
    QLineEdit *kontr;
    QGridLayout *gridLayout;
    QLineEdit *ytb;
    QLabel *label_6;
    QGridLayout *gridLayout_5;
    QLabel *label_10;
    QLineEdit *Firma;
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *gridLayout_9;
    QLabel *label_7;
    QLineEdit *nymerIzd;
    QGridLayout *gridLayout_8;
    QLabel *label_8;
    QLineEdit *naim1;
    QGridLayout *gridLayout_7;
    QLabel *label_4;
    QLineEdit *naim2;
    QGridLayout *gridLayout_6;
    QLabel *label_11;
    QLineEdit *maxSymbol;
    QHBoxLayout *horizontalLayout_6;
    QGridLayout *gridLayout_11;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *docGen;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QLabel *label_9;
    QProgressBar *progressBar_2;
    QTextEdit *textEdit;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 417);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(800, 417));
        MainWindow->setMaximumSize(QSize(800, 417));
        QFont font;
        font.setStyleStrategy(QFont::PreferAntialias);
        MainWindow->setFont(font);
        MainWindow->setCursor(QCursor(Qt::ArrowCursor));
        MainWindow->setContextMenuPolicy(Qt::CustomContextMenu);
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QStringLiteral("action_2"));
        action_2->setEnabled(true);
        action_2->setVisible(true);
        actionv1_0 = new QAction(MainWindow);
        actionv1_0->setObjectName(QStringLiteral("actionv1_0"));
        actionv1_0->setEnabled(false);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_12 = new QGridLayout(centralWidget);
        gridLayout_12->setSpacing(6);
        gridLayout_12->setContentsMargins(11, 11, 11, 11);
        gridLayout_12->setObjectName(QStringLiteral("gridLayout_12"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        openFile = new QPushButton(centralWidget);
        openFile->setObjectName(QStringLiteral("openFile"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(openFile->sizePolicy().hasHeightForWidth());
        openFile->setSizePolicy(sizePolicy1);
        openFile->setMinimumSize(QSize(173, 28));
        openFile->setMaximumSize(QSize(173, 28));

        horizontalLayout_5->addWidget(openFile);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setFrameShape(QFrame::NoFrame);

        horizontalLayout_5->addWidget(label);


        gridLayout_12->addLayout(horizontalLayout_5, 0, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        pathSave = new QPushButton(centralWidget);
        pathSave->setObjectName(QStringLiteral("pathSave"));

        horizontalLayout_4->addWidget(pathSave);

        pathSave_2 = new QLabel(centralWidget);
        pathSave_2->setObjectName(QStringLiteral("pathSave_2"));
        pathSave_2->setMinimumSize(QSize(300, 0));
        pathSave_2->setFrameShape(QFrame::NoFrame);

        horizontalLayout_4->addWidget(pathSave_2);

        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setFrameShape(QFrame::NoFrame);
        label_12->setTextFormat(Qt::AutoText);

        horizontalLayout_4->addWidget(label_12);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout_4->addWidget(lineEdit);


        gridLayout_12->addLayout(horizontalLayout_4, 1, 0, 1, 1);

        gridLayout_10 = new QGridLayout();
        gridLayout_10->setSpacing(6);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_2, 0, 0, 1, 1);

        razrab = new QLineEdit(centralWidget);
        razrab->setObjectName(QStringLiteral("razrab"));

        gridLayout_4->addWidget(razrab, 1, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout_4);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_3, 0, 0, 1, 1);

        prov = new QLineEdit(centralWidget);
        prov->setObjectName(QStringLiteral("prov"));

        gridLayout_3->addWidget(prov, 1, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout_3);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_5, 0, 0, 1, 1);

        kontr = new QLineEdit(centralWidget);
        kontr->setObjectName(QStringLiteral("kontr"));

        gridLayout_2->addWidget(kontr, 1, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout_2);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        ytb = new QLineEdit(centralWidget);
        ytb->setObjectName(QStringLiteral("ytb"));

        gridLayout->addWidget(ytb, 2, 0, 1, 1);

        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_6, 1, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_10, 0, 0, 1, 1);

        Firma = new QLineEdit(centralWidget);
        Firma->setObjectName(QStringLiteral("Firma"));

        gridLayout_5->addWidget(Firma, 1, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout_5);


        gridLayout_10->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        gridLayout_9 = new QGridLayout();
        gridLayout_9->setSpacing(6);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout_9->addWidget(label_7, 0, 0, 1, 1);

        nymerIzd = new QLineEdit(centralWidget);
        nymerIzd->setObjectName(QStringLiteral("nymerIzd"));

        gridLayout_9->addWidget(nymerIzd, 1, 0, 1, 1);


        horizontalLayout_2->addLayout(gridLayout_9);

        gridLayout_8 = new QGridLayout();
        gridLayout_8->setSpacing(6);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout_8->addWidget(label_8, 0, 0, 1, 1);

        naim1 = new QLineEdit(centralWidget);
        naim1->setObjectName(QStringLiteral("naim1"));

        gridLayout_8->addWidget(naim1, 1, 0, 1, 1);


        horizontalLayout_2->addLayout(gridLayout_8);

        gridLayout_7 = new QGridLayout();
        gridLayout_7->setSpacing(6);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(label_4, 0, 0, 1, 1);

        naim2 = new QLineEdit(centralWidget);
        naim2->setObjectName(QStringLiteral("naim2"));

        gridLayout_7->addWidget(naim2, 1, 0, 1, 1);


        horizontalLayout_2->addLayout(gridLayout_7);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setSpacing(6);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy2);
        label_11->setMaximumSize(QSize(60, 16777215));
        label_11->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(label_11, 0, 0, 1, 1);

        maxSymbol = new QLineEdit(centralWidget);
        maxSymbol->setObjectName(QStringLiteral("maxSymbol"));
        sizePolicy.setHeightForWidth(maxSymbol->sizePolicy().hasHeightForWidth());
        maxSymbol->setSizePolicy(sizePolicy);
        maxSymbol->setMaximumSize(QSize(60, 16777215));
        maxSymbol->setMaxLength(2);
        maxSymbol->setCursorPosition(0);

        gridLayout_6->addWidget(maxSymbol, 1, 0, 1, 1);


        horizontalLayout_2->addLayout(gridLayout_6);


        gridLayout_10->addLayout(horizontalLayout_2, 1, 0, 1, 1);


        gridLayout_12->addLayout(gridLayout_10, 2, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        gridLayout_11 = new QGridLayout();
        gridLayout_11->setSpacing(6);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        docGen = new QPushButton(centralWidget);
        docGen->setObjectName(QStringLiteral("docGen"));
        docGen->setEnabled(true);
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(173);
        sizePolicy3.setVerticalStretch(28);
        sizePolicy3.setHeightForWidth(docGen->sizePolicy().hasHeightForWidth());
        docGen->setSizePolicy(sizePolicy3);
        docGen->setMinimumSize(QSize(173, 28));
        docGen->setMaximumSize(QSize(173, 28));

        horizontalLayout_3->addWidget(docGen);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        gridLayout_11->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_9);

        progressBar_2 = new QProgressBar(centralWidget);
        progressBar_2->setObjectName(QStringLiteral("progressBar_2"));
        progressBar_2->setValue(0);

        verticalLayout->addWidget(progressBar_2);


        gridLayout_11->addLayout(verticalLayout, 1, 0, 1, 1);


        horizontalLayout_6->addLayout(gridLayout_11);

        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setEnabled(true);
        textEdit->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));

        horizontalLayout_6->addWidget(textEdit);


        gridLayout_12->addLayout(horizontalLayout_6, 3, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        pathSave_2->raise();
        nymerIzd->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 26));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menu->addSeparator();
        menu->addAction(action_2);
        menu->addAction(actionv1_0);
        mainToolBar->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\237\321\200\320\265\320\276\320\261\321\200\320\260\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\214 \320\277\320\265\321\200\320\265\321\207\320\275\320\265\320\271", Q_NULLPTR));
        action_2->setText(QApplication::translate("MainWindow", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265", Q_NULLPTR));
        actionv1_0->setText(QApplication::translate("MainWindow", "v1.0", Q_NULLPTR));
        openFile->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \321\204\320\260\320\271\320\273", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "123", Q_NULLPTR));
        pathSave->setText(QApplication::translate("MainWindow", "\320\237\321\203\321\202\321\214 \320\272 \321\201\320\276\321\205\321\200\320\260\320\275\320\265\320\275\320\275\320\276\320\274\321\203 \321\204\320\260\320\271\320\273\321\203", Q_NULLPTR));
        pathSave_2->setText(QApplication::translate("MainWindow", "123", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "\320\230\320\274\321\217 \320\263\320\265\320\275\320\265\321\200\320\270\321\200\321\203\320\265\320\274\320\276\320\263\320\276 \321\204\320\260\320\271\320\273\320\260:", Q_NULLPTR));
        lineEdit->setText(QApplication::translate("MainWindow", "\320\221\320\256\320\233\320\230.48435.006", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\320\240\320\260\320\267\321\200\320\260\320\261\320\276\321\202\320\260\320\273:", Q_NULLPTR));
        razrab->setText(QApplication::translate("MainWindow", "\320\230\320\262\320\260\320\275\320\276\320\262 \320\230.\320\220.", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\276\320\262\320\265\321\200\320\270\320\273:", Q_NULLPTR));
        prov->setText(QApplication::translate("MainWindow", "\320\225\320\274\321\206\320\265\320\262 \320\230.\320\233.", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "\320\235.\320\272\320\276\320\275\321\202\321\200.:", Q_NULLPTR));
        kontr->setText(QApplication::translate("MainWindow", "\320\237\320\260\321\201\320\272\320\260\320\273\321\214 \320\222.\320\230.", Q_NULLPTR));
        ytb->setText(QApplication::translate("MainWindow", "\320\220\320\273\320\260\320\264\320\270\320\275 \320\222.\320\241.", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "\320\243\321\202\320\262.:", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "\320\244\320\270\321\200\320\274\320\260-\320\270\320\267\320\263\320\276\321\202\320\276\320\262\320\270\321\202\320\265\320\273\321\214:", Q_NULLPTR));
        Firma->setText(QApplication::translate("MainWindow", "\320\244\320\223\320\243\320\237 \320\235\320\237\320\237 \302\253\320\223\320\260\320\274\320\274\320\260\302\273", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "\320\224\320\265\321\206\320\270\320\274\320\260\320\273\321\214\320\275\321\213\320\271 \320\275\320\276\320\274\320\265\321\200 \320\270\320\267\320\264\320\265\320\273\320\270\321\217:", Q_NULLPTR));
        nymerIzd->setText(QApplication::translate("MainWindow", "\320\221\320\256\320\233\320\230.468714.005 \320\237\320\2553", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\270\320\274\320\265\320\275\320\276\320\262\320\260\320\275\320\270\320\265 1 :", Q_NULLPTR));
        naim1->setText(QApplication::translate("MainWindow", "\320\237\320\273\320\260\321\202\320\260 \321\202\321\200\320\260\320\272\321\202\320\276\320\262\320\276\320\263\320\276 \321\203\321\201\320\270\320\273\320\270\321\202\320\265\320\273\321\217", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\270\320\274\320\265\320\275\320\276\320\262\320\260\320\275\320\270\320\265 2:", Q_NULLPTR));
        naim2->setText(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\321\207\320\265\320\275\321\214 \321\215\320\273\320\265\320\274\320\265\320\275\321\202\320\276\320\262", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\273-\320\262\320\276\n"
"\321\201\320\270\320\274\320\262\320\276\320\273\320\276\320\262", Q_NULLPTR));
        maxSymbol->setText(QApplication::translate("MainWindow", "35", Q_NULLPTR));
        docGen->setText(QApplication::translate("MainWindow", "\320\241\321\202\320\260\321\200\321\202", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\276\321\206\320\265\321\201\321\201 \320\262\321\213\320\277\320\276\320\273\320\275\320\265\320\275\320\270\321\217", Q_NULLPTR));
        menu->setTitle(QApplication::translate("MainWindow", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
