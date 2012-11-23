/*
    Copyright (c) 2008-11 Qtrac Ltd. All rights reserved.
    This program or module is free software: you can redistribute it
    and/or modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation, either version 2 of
    the License, or (at your option) any later version. This program is
    distributed in the hope that it will be useful, but WITHOUT ANY
    WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
    for more details.
*/

#include "mainwindow.hpp"
#include <QApplication>
#include <QIcon>
#include <QTextCodec>
#include <QTextStream>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setCursorFlashTime(0);
    app.setOrganizationName("Qtrac Ltd.");
    app.setOrganizationDomain("qtrac.eu");
    app.setApplicationName("DiffPDF");
    app.setWindowIcon(QIcon(":/icon.png"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));

    QTextStream out(stdout);
    QStringList args = app.arguments().mid(1);
    InitialComparisonMode comparisonMode = CompareWords;
    QString filename1;
    QString filename2;
    bool optionsOK = true;
    Debug debug = DebugOff;
    foreach (const QString arg, args) {
        if (optionsOK && (arg == "--appearance" || arg == "-a"))
            comparisonMode = CompareAppearance;
        else if (optionsOK && (arg == "--character" || arg == "-c"))
            comparisonMode = CompareCharacters;
        else if (optionsOK && (arg == "--word" || arg == "-w"))
            ; // comparisonMode = CompareWords; // this is the default
        else if (optionsOK && (arg == "--debug" || arg == "--debug=1" ||
                               arg == "--debug1"))
            debug = DebugShowZones;
        else if (optionsOK && (arg == "--debug=2" || arg == "--debug2"))
            debug = DebugShowZonesAndTexts;
        else if (optionsOK && (arg == "--debug=3" || arg == "--debug3"))
            debug = DebugShowZonesAndTextsAndYX;
        else if (optionsOK && arg == "--")
            optionsOK = false;
        else if (filename1.isEmpty() && arg.toLower().endsWith(".pdf"))
            filename1 = arg;
        else if (filename2.isEmpty() && arg.toLower().endsWith(".pdf"))
            filename2 = arg;
        else
            out << "unrecognized argument '" << arg << "'\n";
    }

    MainWindow window(debug, comparisonMode, filename1, filename2);
    window.show();
    return app.exec();
}

