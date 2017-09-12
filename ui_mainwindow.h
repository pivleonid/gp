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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_18;
    QGridLayout *gridLayout_16;
    QPushButton *openFile;
    QSpacerItem *verticalSpacer;
    QPushButton *docGen;
    QGridLayout *gridLayout_17;
    QGridLayout *gridLayout_13;
    QGridLayout *gridLayout_7;
    QGridLayout *gridLayout_6;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QGridLayout *gridLayout_5;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QGridLayout *gridLayout_4;
    QLabel *label_4;
    QLineEdit *lineEdit_3;
    QGridLayout *gridLayout_3;
    QLabel *label_5;
    QLineEdit *lineEdit_4;
    QGridLayout *gridLayout;
    QLabel *label_6;
    QLineEdit *lineEdit_5;
    QGridLayout *gridLayout_12;
    QGridLayout *gridLayout_8;
    QLabel *label_7;
    QLineEdit *lineEdit_6;
    QGridLayout *gridLayout_9;
    QLabel *label_8;
    QLineEdit *lineEdit_7;
    QGridLayout *gridLayout_10;
    QGridLayout *gridLayout_11;
    QLabel *label_10;
    QLineEdit *lineEdit_9;
    QGridLayout *gridLayout_15;
    QGridLayout *gridLayout_2;
    QComboBox *comboBox;
    QLabel *label;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer;
    QGridLayout *gridLayout_14;
    QSpacerItem *verticalSpacer_2;
    QPushButton *saveButn;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(746, 277);
        MainWindow->setCursor(QCursor(Qt::ArrowCursor));
        MainWindow->setContextMenuPolicy(Qt::CustomContextMenu);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_18 = new QGridLayout(centralWidget);
        gridLayout_18->setSpacing(6);
        gridLayout_18->setContentsMargins(11, 11, 11, 11);
        gridLayout_18->setObjectName(QStringLiteral("gridLayout_18"));
        gridLayout_16 = new QGridLayout();
        gridLayout_16->setSpacing(6);
        gridLayout_16->setObjectName(QStringLiteral("gridLayout_16"));
        openFile = new QPushButton(centralWidget);
        openFile->setObjectName(QStringLiteral("openFile"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(openFile->sizePolicy().hasHeightForWidth());
        openFile->setSizePolicy(sizePolicy);

        gridLayout_16->addWidget(openFile, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_16->addItem(verticalSpacer, 1, 0, 1, 1);

        docGen = new QPushButton(centralWidget);
        docGen->setObjectName(QStringLiteral("docGen"));
        docGen->setEnabled(true);
        sizePolicy.setHeightForWidth(docGen->sizePolicy().hasHeightForWidth());
        docGen->setSizePolicy(sizePolicy);

        gridLayout_16->addWidget(docGen, 2, 0, 1, 1);


        gridLayout_18->addLayout(gridLayout_16, 0, 0, 1, 1);

        gridLayout_17 = new QGridLayout();
        gridLayout_17->setSpacing(6);
        gridLayout_17->setObjectName(QStringLiteral("gridLayout_17"));
        gridLayout_13 = new QGridLayout();
        gridLayout_13->setSpacing(6);
        gridLayout_13->setObjectName(QStringLiteral("gridLayout_13"));
        gridLayout_7 = new QGridLayout();
        gridLayout_7->setSpacing(6);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        gridLayout_6 = new QGridLayout();
        gridLayout_6->setSpacing(6);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(label_2, 0, 0, 1, 1);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout_6->addWidget(lineEdit, 1, 0, 1, 1);


        gridLayout_7->addLayout(gridLayout_6, 0, 0, 1, 1);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_3, 0, 0, 1, 1);

        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        gridLayout_5->addWidget(lineEdit_2, 1, 0, 1, 1);


        gridLayout_7->addLayout(gridLayout_5, 0, 1, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_4, 0, 0, 1, 1);

        lineEdit_3 = new QLineEdit(centralWidget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        gridLayout_4->addWidget(lineEdit_3, 1, 0, 1, 1);


        gridLayout_7->addLayout(gridLayout_4, 0, 2, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_5, 0, 0, 1, 1);

        lineEdit_4 = new QLineEdit(centralWidget);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));

        gridLayout_3->addWidget(lineEdit_4, 1, 0, 1, 1);


        gridLayout_7->addLayout(gridLayout_3, 0, 3, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_6, 0, 0, 1, 1);

        lineEdit_5 = new QLineEdit(centralWidget);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));

        gridLayout->addWidget(lineEdit_5, 1, 0, 1, 1);


        gridLayout_7->addLayout(gridLayout, 0, 4, 1, 1);


        gridLayout_13->addLayout(gridLayout_7, 0, 0, 1, 1);

        gridLayout_12 = new QGridLayout();
        gridLayout_12->setSpacing(6);
        gridLayout_12->setObjectName(QStringLiteral("gridLayout_12"));
        gridLayout_8 = new QGridLayout();
        gridLayout_8->setSpacing(6);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout_8->addWidget(label_7, 0, 0, 1, 1);

        lineEdit_6 = new QLineEdit(centralWidget);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));

        gridLayout_8->addWidget(lineEdit_6, 1, 0, 1, 1);


        gridLayout_12->addLayout(gridLayout_8, 0, 0, 1, 1);

        gridLayout_9 = new QGridLayout();
        gridLayout_9->setSpacing(6);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout_9->addWidget(label_8, 0, 0, 1, 1);

        lineEdit_7 = new QLineEdit(centralWidget);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));

        gridLayout_9->addWidget(lineEdit_7, 1, 0, 1, 1);


        gridLayout_12->addLayout(gridLayout_9, 0, 1, 1, 1);

        gridLayout_10 = new QGridLayout();
        gridLayout_10->setSpacing(6);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));

        gridLayout_12->addLayout(gridLayout_10, 0, 2, 1, 1);

        gridLayout_11 = new QGridLayout();
        gridLayout_11->setSpacing(6);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setAlignment(Qt::AlignCenter);

        gridLayout_11->addWidget(label_10, 0, 0, 1, 1);

        lineEdit_9 = new QLineEdit(centralWidget);
        lineEdit_9->setObjectName(QStringLiteral("lineEdit_9"));

        gridLayout_11->addWidget(lineEdit_9, 1, 0, 1, 1);


        gridLayout_12->addLayout(gridLayout_11, 0, 3, 1, 1);


        gridLayout_13->addLayout(gridLayout_12, 1, 0, 1, 1);


        gridLayout_17->addLayout(gridLayout_13, 0, 0, 1, 1);

        gridLayout_15 = new QGridLayout();
        gridLayout_15->setSpacing(6);
        gridLayout_15->setObjectName(QStringLiteral("gridLayout_15"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        gridLayout_2->addWidget(comboBox, 2, 0, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label, 1, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_3, 0, 0, 1, 1);


        gridLayout_15->addLayout(gridLayout_2, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_15->addItem(horizontalSpacer, 0, 1, 1, 1);

        gridLayout_14 = new QGridLayout();
        gridLayout_14->setSpacing(6);
        gridLayout_14->setObjectName(QStringLiteral("gridLayout_14"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        gridLayout_14->addItem(verticalSpacer_2, 0, 0, 1, 1);

        saveButn = new QPushButton(centralWidget);
        saveButn->setObjectName(QStringLiteral("saveButn"));

        gridLayout_14->addWidget(saveButn, 1, 0, 1, 1);


        gridLayout_15->addLayout(gridLayout_14, 0, 2, 1, 1);


        gridLayout_17->addLayout(gridLayout_15, 1, 0, 1, 1);


        gridLayout_18->addLayout(gridLayout_17, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 746, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        openFile->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \321\204\320\260\320\271\320\273", Q_NULLPTR));
        docGen->setText(QApplication::translate("MainWindow", "\320\223\320\265\320\275\320\265\321\200\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265\n"
" \320\264\320\276\320\272\321\203\320\274\320\265\320\275\321\202\320\260\321\206\320\270\320\270", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\320\240\320\260\320\267\321\200\320\260\320\261\320\276\321\202\320\260\320\273", Q_NULLPTR));
        lineEdit->setText(QApplication::translate("MainWindow", "\320\230\320\262\320\260\320\275\320\276\320\262 \320\230.\320\220.", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\276\320\262\320\265\321\200\320\270\320\273", Q_NULLPTR));
        lineEdit_2->setText(QApplication::translate("MainWindow", "\320\225\320\274\321\206\320\265\320\262 \320\230.\320\233.", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "\320\242.\320\272\320\276\320\275\321\202\321\200", Q_NULLPTR));
        lineEdit_3->setText(QApplication::translate("MainWindow", "\320\237\320\265\321\202\321\200\320\276\320\262 \320\227.\320\241.", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "\320\235.\320\272\320\276\320\275\321\202\321\200.", Q_NULLPTR));
        lineEdit_4->setText(QApplication::translate("MainWindow", "\320\237\320\260\321\201\320\272\320\260\320\273\321\214 \320\222.\320\230.", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "\320\243\321\202\320\262.", Q_NULLPTR));
        lineEdit_5->setText(QApplication::translate("MainWindow", "\320\220\320\273\320\260\320\264\320\270\320\275 \320\222.\320\241.", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "\320\224\320\265\321\206\320\270\320\274\320\260\320\273\321\214\320\275\321\213\320\271 \320\275\320\276\320\274\320\265\321\200 \320\270\320\267\320\264\320\265\320\273\320\270\321\217", Q_NULLPTR));
        lineEdit_6->setText(QApplication::translate("MainWindow", "\320\221\320\256\320\233\320\230.468714.005 \320\237\320\2553", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\270\320\274\320\265\320\275\320\276\320\262\320\260\320\275\320\270\320\265 ", Q_NULLPTR));
        lineEdit_7->setText(QApplication::translate("MainWindow", "\320\237\320\273\320\260\321\202\320\260 \321\202\321\200\320\260\320\272\321\202\320\276\320\262\320\276\320\263\320\276 \321\203\321\201\320\270\320\273\320\270\321\202\320\265\320\273\321\217", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "\320\244\320\270\321\200\320\274\320\260-\320\270\320\267\320\263\320\276\321\202\320\276\320\262\320\270\321\202\320\265\320\273\321\214", Q_NULLPTR));
        lineEdit_9->setText(QApplication::translate("MainWindow", "\320\244\320\223\320\243\320\237 \320\235\320\237\320\237 \302\253\320\223\320\260\320\274\320\274\320\260\302\273", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "word", Q_NULLPTR)
         << QApplication::translate("MainWindow", "excel", Q_NULLPTR)
        );
        label->setText(QApplication::translate("MainWindow", "\320\250\320\260\320\261\320\273\320\276\320\275 \320\262\321\213\321\205\320\276\320\264\320\275\320\276\320\263\320\276\n"
" \321\204\320\260\320\271\320\273\320\260", Q_NULLPTR));
        saveButn->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
