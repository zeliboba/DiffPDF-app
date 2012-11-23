# CHANGES
# help.html
# diffpdf.1
HEADERS	    += mainwindow.hpp
SOURCES     += mainwindow.cpp
HEADERS	    += textitem.hpp
SOURCES	    += textitem.cpp
HEADERS	    += optionsform.hpp
SOURCES     += optionsform.cpp
HEADERS	    += saveform.hpp
SOURCES     += saveform.cpp
HEADERS	    += helpform.hpp
SOURCES     += helpform.cpp
HEADERS	    += generic.hpp
SOURCES	    += generic.cpp
HEADERS	    += sequence_matcher.hpp
SOURCES     += sequence_matcher.cpp
SOURCES     += main.cpp
RESOURCES   += resources.qrc
LIBS	    += -lpoppler-qt4
exists($(HOME)/opt/poppler018/) {
    message(Using locally built Poppler library)
    INCLUDEPATH += $(HOME)/opt/poppler018/include/poppler/qt4
    LIBS += -Wl,-rpath -Wl,$(HOME)/opt/poppler018/lib -Wl,-L$(HOME)/opt/poppler018/lib
} else {
    exists(/usr/include/poppler/qt4) {
	INCLUDEPATH += /usr/include/poppler/qt4
    } else {
	INCLUDEPATH += /usr/local/include/poppler/qt4
    }
}
