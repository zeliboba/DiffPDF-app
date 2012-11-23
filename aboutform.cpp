/*
    Copyright (c) 2011-12 Qtrac Ltd. All rights reserved.
    This program or module is free software: you can redistribute it
    and/or modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation, either version 2 of
    the License, or (at your option) any later version. This program is
    distributed in the hope that it will be useful, but WITHOUT ANY
    WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
    for more details.
*/

#include "aboutform.hpp"
#include <poppler-version.h>
#include <QHBoxLayout>
#include <QSettings>
#include <QShortcut>
#include <QTabWidget>
#include <QTextBrowser>


static const QString Version("1.9.2");


AboutForm::AboutForm(QWidget *parent) : QDialog(parent)
{
    setAttribute(Qt::WA_DeleteOnClose);
    QTextBrowser *aboutBrowser = new QTextBrowser;
    aboutBrowser->setReadOnly(true);
    aboutBrowser->setHtml(tr(
    "<p><b>DiffPDF</a> %1</b> by Mark Summerfield "
    "<tt>&lt;mark@qtrac.eu&gt;</tt>."
    "<br>Copyright &copy; 2008-12 "
    "<a href=\"http://www.qtrac.eu\">Qtrac</a> Ltd. All rights reserved."
    "<br>Built with Qt %2 and Poppler %3.<hr>"
    "<p>This program compares the text or the visual appearance of "
    "each page in two PDF files."
    "<hr><p>If you like DiffPDF you might like my books:<ul>"
    "<li><a href=\"http://www.qtrac.eu/gobook.html\">"
    "Programming in Go</a></li>"
    "<li><a href=\"http://www.qtrac.eu/aqpbook.html\">"
    "Advanced Qt Programming</a></li>"
    "<li><a href=\"http://www.qtrac.eu/py3book.html\">"
    "Programming in Python 3</a></li>"
    "<li><a href=\"http://www.qtrac.eu/pyqtbook.html\">"
    "Rapid GUI Programming with Python and Qt</a></li>"
    "</ul>"
    "I also provide training and consultancy in C++, Go, Python&nbsp;2, "
    "Python&nbsp;3, C++/Qt, and PyQt4.").arg(Version).arg(qVersion())
            .arg(POPPLER_VERSION));
    QTextBrowser *contributorsBrowser = new QTextBrowser;
    contributorsBrowser->setReadOnly(true);
    contributorsBrowser->setHtml(tr("<ul>"
    "<li>Liviu Andronic &mdash; suggested adding drag and drop</li>"
    "<li><b>Jasmin Blanchette</b> &mdash; the original idea and "
    "subsequent suggestions</li>"
    "<li>Pavel Fric &mdash; Czech translation</li>"
    "<li>Rory Gordon &mdash; suggested adding drag and drop</li>"
    "<li>Florian Heiderich &mdash; suggested using composition modes for "
    "showing subtle differences</li>"
    "<li>Paul Howarth &mdash; suggestions resulting in Characters "
    "mode</li>"
    "<li><b>Steven Lee</b> &mdash; creating Windows binaries</li>"
    "<li><b>Dirk Loss</b> &mdash; creating Mac binaries</li>"
    "<li>David Paleino &mdash; Debian packager</li>"
    "</ul>"));
    //"<li> &mdash; </li>"
    QTextBrowser *licenceBrowser = new QTextBrowser;
    licenceBrowser->setReadOnly(true);
    licenceBrowser->setHtml(tr(
    "This program is free software: you can redistribute it "
    "and/or modify it under the terms of the GNU General Public License "
    "as published by the Free Software Foundation, either version 2 of "
    "the License, or (at your option), any "
    "later version. This program is distributed in the hope that it will "
    "be useful, but WITHOUT ANY WARRANTY; without even the implied "
    "warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. "
    "See the GNU General Public License (in file <tt>gpl-2.0.txt</tt>) "
    "for more details."));
    QTabWidget *tabWidget = new QTabWidget;
    tabWidget->addTab(aboutBrowser, tr("&About"));
    tabWidget->addTab(contributorsBrowser, tr("&Contributors"));
    tabWidget->addTab(licenceBrowser, tr("&License"));
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(tabWidget);
    setLayout(layout);
    resize(480, 400);
    setWindowTitle(tr("DiffPDF — About"));
}
