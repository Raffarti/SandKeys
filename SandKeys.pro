TEMPLATE = subdirs

SUBDIRS += Plugin Themes
equals (QT_MAJOR_VERSION, 5): {
    other_subdirs += QmlLoader
}
equals (QT_MAJOR_VERSION, 4): {
    SUBDIRS += Qt4Loader
}

other_subdirs += Symbols

for(subdir, other_subdirs){
    include($$subdir/$$subdir".pri")
}
