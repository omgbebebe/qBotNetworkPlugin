AM_CPPFLAGS = $(WZ_CPPFLAGS) $(QT5_CFLAGS) $(GLEW_CFLAGS)
AM_CFLAGS = $(WZ_CFLAGS)
AM_CXXFLAGS = $(WZ_CXXFLAGS) $(QT5_CFLAGS)

MOCHEADER = \
	qtplugins.h

MOCEDFILES = $(MOCHEADER:%.h=%_moc.cpp)

%_moc.cpp: %.h
	$(MOC5) -o $@ $<

CLEANFILES = \
	$(MOCEDFILES)

noinst_LIBRARIES = libqtplugins.a

noinst_HEADERS = \
	$(MOCHEADER) \
	qtplugins.h

nodist_libqtplugins_a_SOURCES = \
	qtplugins_moc.cpp

libqtplugins_a_SOURCES = \
	qtplugins.cpp
