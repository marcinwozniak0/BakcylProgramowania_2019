option(USE_BUNDLED_NCURSES "Enable building of the bundled ncurses" ${USE_BUNDLED_DEPS})
if(NOT USE_BUNDLED_NCURSES)
    set(CURSES_NEED_NCURSES TRUE)
    find_package(Curses REQUIRED)
    message(STATUS "Found ncurses: include: ${CURSES_INCLUDE_DIR}, lib: ${CURSES_LIBRARIES}")
else()
    set(CURSES_BUNDLE_DIR "${PROJECT_BINARY_DIR}/ncurses-prefix/src/ncurses")
    set(CURSES_INCLUDE_DIR "${CURSES_BUNDLE_DIR}/include/")
    set(CURSES_LIBRARIES "${CURSES_BUNDLE_DIR}/lib/libncurses.a")
    message(STATUS "Using bundled ncurses in '${CURSES_BUNDLE_DIR}'")
    ExternalProject_Add(ncurses
            URL "https://ftp.gnu.org/pub/gnu/ncurses/ncurses-6.2.tar.gz"
            URL_MD5 "e812da327b1c2214ac1aed440ea3ae8d"
            CONFIGURE_COMMAND ./configure --without-cxx --without-cxx-binding --without-ada --without-manpages --without-progs --without-tests --with-terminfo-dirs=/etc/terminfo:/lib/terminfo:/usr/share/terminfo
            BUILD_COMMAND ${CMD_MAKE}
            BUILD_IN_SOURCE 1
            INSTALL_COMMAND "")
endif()